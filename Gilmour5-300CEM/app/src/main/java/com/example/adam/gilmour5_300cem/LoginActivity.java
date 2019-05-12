package com.example.adam.gilmour5_300cem;

import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

public class LoginActivity extends AppCompatActivity {

    private FirebaseAuth mAuth;
    private EditText etEmail, etPassword;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        mAuth = FirebaseAuth.getInstance();

        etEmail = findViewById(R.id.etLEmail);
        etPassword = findViewById(R.id.etLPassword);
    }

    @Override
    protected void onStart() {
        super.onStart();

        FirebaseUser currentUser = mAuth.getCurrentUser();
        if(currentUser != null){
            sendToMain();
        }
    }



    public void onClick(View v){
        if (v.getId() == R.id.btnLLogin){

            String strEmail = etEmail.getText().toString();
            String strPassword = etPassword.getText().toString();

            if(!TextUtils.isEmpty(strEmail) && !TextUtils.isEmpty(strPassword)){

                mAuth.signInWithEmailAndPassword(strEmail, strPassword).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        if (task.isSuccessful()){
                            sendToMain();
                        } else {
                            String errorMessage = task.getException().getMessage();
                            Toast.makeText(LoginActivity.this,errorMessage,Toast.LENGTH_LONG).show();
                        }


                    }
                });
            }


        }
        if (v.getId() == R.id.upUpload){
            sentToRegister();
        }

    }

    private void sentToRegister() {
        Intent intent = new Intent(this, RegisterActivity.class);
        startActivity(intent);
    }

    private void sendToMain() {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
        finish();
    }}
