package com.example.adam.gilmour5_300cem;

import android.content.Intent;
import android.net.Uri;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.firestore.DocumentChange;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.EventListener;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.FirebaseFirestoreException;
import com.google.firebase.firestore.Query;
import com.google.firebase.firestore.QuerySnapshot;

import java.util.ArrayList;
import java.util.List;

import javax.annotation.Nullable;

public class MainActivity extends AppCompatActivity {


    private FirebaseAuth mAuth;
    private RecyclerView placesViews;
    private List<Places> placesList;

    private FirebaseFirestore firebaseFirestore;
    private PlacesRecyclerAdapter placesRecyclerAdapter;

    private DocumentSnapshot lastVisible;

    //Has the first page been loaded?
    private Boolean firstPageLoad = false;

    private static final String TAG = "MainActivity";
    private static final int ERROR_DIALOG_REQUEST = 9001;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar;

        toolbar = findViewById(R.id.main_toolbar);
        setSupportActionBar(toolbar);

        getSupportActionBar().setTitle("Walk 'n' Go!");

        mAuth = FirebaseAuth.getInstance();

        //Showing Places
        placesList = new ArrayList<>();
        placesViews = findViewById(R.id.placesListView);

        placesRecyclerAdapter = new PlacesRecyclerAdapter(placesList, MainActivity.this);
        placesViews.setLayoutManager(new LinearLayoutManager(this));
        placesViews.setAdapter(placesRecyclerAdapter);
        placesViews.setHasFixedSize(true);

        if(mAuth.getCurrentUser() != null){
            firebaseFirestore = FirebaseFirestore.getInstance();
            placesViews.addOnScrollListener(new RecyclerView.OnScrollListener() {
                @Override
                public void onScrolled(@NonNull RecyclerView recyclerView, int dx, int dy) {
                    super.onScrolled(recyclerView, dx, dy);
                    Boolean atEnd = !recyclerView.canScrollVertically(1);
                    if(atEnd){
                        loadMorePost();
                    }
                }
            });

            //FireBase query, set limit to 3
            Query query = firebaseFirestore.collection("Places").orderBy("title", Query.Direction.DESCENDING).limit(3);
            query.addSnapshotListener(this, new EventListener<QuerySnapshot>() {
                @Override
                public void onEvent(@Nullable QuerySnapshot queryDocumentSnapshots, @Nullable FirebaseFirestoreException e) {
                    //Contains data read from a document inside FireBase
                    if(!queryDocumentSnapshots.isEmpty()){
                        if (!firstPageLoad){
                            lastVisible = queryDocumentSnapshots.getDocuments().get(queryDocumentSnapshots.size() -1);
                            //Initialise placeList
                            placesList.clear();
                        }
                        for (DocumentChange queriedDoc : queryDocumentSnapshots.getDocumentChanges()){
                            if(queriedDoc.getType() == DocumentChange.Type.ADDED){
                                Places places = queriedDoc.getDocument().toObject(Places.class);
                                if(!firstPageLoad){
                                    placesList.add(places);
                                } else {
                                    placesList.add(0, places);
                                }

                                placesRecyclerAdapter.notifyDataSetChanged();

                            }
                        }
                        firstPageLoad = true;
                    }
                }
            });
        }

    }

    /*
    Load more places when the person has scrolled to the bottom of the recycler view, if there are any left to add.
     */
    private void loadMorePost() {
        if(mAuth.getCurrentUser() != null){
            Query query =firebaseFirestore.collection("Places")
                    .orderBy("title")
                    .startAfter(lastVisible)
                    .limit(3);
            query.addSnapshotListener(this, new EventListener<QuerySnapshot>() {
                @Override
                public void onEvent(@Nullable QuerySnapshot queryDocumentSnapshots, @Nullable FirebaseFirestoreException e) {
                    if(!queryDocumentSnapshots.isEmpty()){
                        //Last Visible is the last document got from the last query.
                        lastVisible = queryDocumentSnapshots.getDocuments().get(queryDocumentSnapshots.size() -1);
                        for (DocumentChange queriedDoc : queryDocumentSnapshots.getDocumentChanges()){
                            if(queriedDoc.getType() == DocumentChange.Type.ADDED) {
                                //Find data in FireBase and create objects out of them
                                Places places = queriedDoc.getDocument().toObject(Places.class);
                                //Add the objects to the list
                                placesList.add(places);

                                placesRecyclerAdapter.notifyDataSetChanged();
                            }
                        }
                    }
                }
            });
        }
    }

    @Override
    protected void onStart() {
        super.onStart();

        FirebaseUser currentUser = FirebaseAuth.getInstance().getCurrentUser();
        if (currentUser == null){
            sendToLogin();
        }
    }

    public void onClick(View v){
        if (v.getId() == R.id.amAdd){
            Intent intent = new Intent(this, UploadActivity.class);
            startActivity(intent);
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
            String url = "https://www.google.com/maps/dir/?api=1&origin=&destination=52.413094,-1.443142&travelmode=driving";
            Intent i = new Intent(Intent.ACTION_VIEW);
            i.setData(Uri.parse(url));
            startActivity(i);
            //sentToSettings();
        }
        return false;
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
}
