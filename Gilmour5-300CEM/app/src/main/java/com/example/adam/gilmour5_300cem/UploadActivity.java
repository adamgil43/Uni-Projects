package com.example.adam.gilmour5_300cem;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.net.Uri;
import android.provider.MediaStore;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.text.TextUtils;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.tasks.Continuation;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.FieldValue;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.FirebaseFirestoreSettings;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.google.firebase.storage.UploadTask;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class UploadActivity extends AppCompatActivity {

    private FirebaseAuth mAuth;
    private StorageReference storageReference;
    private FirebaseFirestore firebaseFirestore;
    private EditText etTitle, etComment;
    private TextView tvLat, tvLong;
    private ImageView imageView;
    private String latLat, latLong, iTitle, iDescription, iURI;
    private Uri uri;
    private final int RequestPermissionCode = 1;
    Intent GalIntent, CropIntent;
    DisplayMetrics displayMetrics;
    private Button upload;
    int width, hieght;
    private Bitmap postBitmap;
    private String TAG = "UploadActivity";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Toolbar toolbar;


        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_upload);
        etTitle = findViewById(R.id.upTitle);
        etComment = findViewById(R.id.upDescription);
        tvLat = findViewById(R.id.upLat);
        tvLong = findViewById(R.id.upLong);
        imageView = findViewById(R.id.ivSelectPicture);


        Intent i = getIntent();
        latLat = i.getStringExtra("lat");
        latLong = i.getStringExtra("long");
        iDescription = i.getStringExtra("description");
        iTitle = i.getStringExtra("title");

        upload = findViewById(R.id.upUpload);


        etComment.setText(iDescription);
        etTitle.setText(iTitle);


        tvLong.setText(latLong);
        tvLat.setText(latLat);

        toolbar = findViewById(R.id.main_toolbar);
        setSupportActionBar(toolbar);


        storageReference = FirebaseStorage.getInstance().getReference();
        firebaseFirestore = FirebaseFirestore.getInstance();
        mAuth = FirebaseAuth.getInstance();

        getSupportActionBar().setTitle("Walk 'n' Go!");

        int permissionCheck = ContextCompat.checkSelfPermission(UploadActivity.this, Manifest.permission.CAMERA);
        if (permissionCheck == PackageManager.PERMISSION_DENIED){
            RequestRuntimePermission();
        }
    }

    private void RequestRuntimePermission() {
        if(!ActivityCompat.shouldShowRequestPermissionRationale(UploadActivity.this, Manifest.permission.CAMERA)){
            ActivityCompat.requestPermissions(UploadActivity.this, new String[]{Manifest.permission.CAMERA}, RequestPermissionCode);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if(item.getItemId() == R.id.mmLogout){
            mAuth.signOut();
            sendToLogin();
        }
        if(item.getItemId() == R.id.mmChangePass){
            sentToSettings();
        }
        return false;
    }

    public void onClick(View v){
        if(v.getId() == R.id.upGetLoc){
            Intent intent = new Intent(this, MapsActivity.class);
            intent.putExtra("title", iTitle);
            intent.putExtra("description", iDescription);
            startActivity(intent);
            finish();
        }
        if(v.getId() == R.id.ivSelectPicture){
            GalleryOpen();
        }
        if(v.getId() == R.id.upUpload){
            upload();
        }
    }

    private void upload() {
        final String strDescription = etComment.getText().toString();
        final String strTitle = etTitle.getText().toString();
        if (!TextUtils.isEmpty(strDescription) && !TextUtils.isEmpty(strTitle)){
            String randomName = UUID.randomUUID().toString();

            final StorageReference filePath = storageReference.child("place_images").child(randomName + ".jpg");
            UploadTask uploadTask = filePath.putFile(uri);

            uploadTask.addOnFailureListener(new OnFailureListener() {
                @Override
                public void onFailure(@NonNull Exception e) {
                    return;
                }
            }).addOnSuccessListener(new OnSuccessListener<UploadTask.TaskSnapshot>() {
                @Override
                public void onSuccess(UploadTask.TaskSnapshot taskSnapshot) {
                    taskSnapshot.getMetadata();
                }
            });

            Task<Uri> uriTask = uploadTask.continueWithTask(new Continuation<UploadTask.TaskSnapshot, Task<Uri>>() {
                @Override
                public Task<Uri> then(@NonNull Task<UploadTask.TaskSnapshot> task) throws Exception {
                    if (!task.isSuccessful()){
                        throw task.getException();
                    }
                    return filePath.getDownloadUrl();
                }
            }).addOnCompleteListener(new OnCompleteListener<Uri>() {
                @Override
                public void onComplete(@NonNull Task<Uri> task) {
                    if (task.isSuccessful()){
                        upload.setEnabled(false);
                        Uri downloadUri = task.getResult();
                        Map<String, Object> postMap = new HashMap<>();
                        postMap.put("image_url", downloadUri.toString());
                        postMap.put("title", strTitle);
                        postMap.put("description", strDescription);
                        postMap.put("longitude", latLong);
                        postMap.put("latitude", latLat);

                        firebaseFirestore.collection("Places").add(postMap).addOnCompleteListener(new OnCompleteListener<DocumentReference>() {
                            @Override
                            public void onComplete(@NonNull Task<DocumentReference> task) {
                                if(task.isSuccessful()){
                                    Toast.makeText(UploadActivity.this, "Place Added", Toast.LENGTH_LONG).show();
                                    Intent intent = new Intent(UploadActivity.this, MainActivity.class);
                                    startActivity(intent);
                                    finish();
                                } else {
                                    upload.setEnabled(true);
                                    Log.d(TAG, "OnComplete2: " + task.getException().getMessage());
                                }
                            }
                        });

                    } else {
                        Toast.makeText(UploadActivity.this, task.getException().getMessage(), Toast.LENGTH_LONG).show();
                    }
                }
            });


        }


    }

    private void GalleryOpen() {
        GalIntent = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        startActivityForResult(Intent.createChooser(GalIntent, "Select Image from Gallery"), 2);

    }

    private void sentToSettings() {
        Intent intent = new Intent(this, PasswordActivity.class);
        startActivity(intent);
    }

    private void sendToLogin() {
        Intent intent = new Intent(this, LoginActivity.class);
        startActivity(intent);
        finish();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if(requestCode == 0 && resultCode == RESULT_OK){
            Toast.makeText(this,"How did you get this message? ", Toast.LENGTH_LONG).show();
        }
        else if (requestCode == 2){
            if (data != null){
                uri = data.getData();
                imageView.setImageURI(uri);
                iURI = uri.toString();
            }
        }
    }
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch (requestCode){
            case RequestPermissionCode:{
                if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                    Toast.makeText(this, "You can crop", Toast.LENGTH_LONG).show();
                } else {
                    Toast.makeText(this,"Please Accept Permissions",Toast.LENGTH_LONG).show();
                }
                break;
            }
        }
    }
}
