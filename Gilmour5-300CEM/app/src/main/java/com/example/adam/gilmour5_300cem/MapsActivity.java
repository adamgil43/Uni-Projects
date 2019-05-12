package com.example.adam.gilmour5_300cem;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Address;
import android.location.Geocoder;
import android.location.Location;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.location.FusedLocationProviderClient;
import com.google.android.gms.location.LocationServices;
import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.maps.DirectionsApiRequest;
import com.google.maps.GeoApiContext;
import com.google.maps.PendingResult;
import com.google.maps.model.DirectionsResult;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MapsActivity extends AppCompatActivity implements OnMapReadyCallback {

    private String TAG = "MapActivity";

    private GoogleMap mMap;
    private Boolean mLocationPermission = false;
    private FusedLocationProviderClient mfusedLocationProviderClient;
    private Address address;
    private Location currentLocation;

    private static final String FINE_LOCATION = Manifest.permission.ACCESS_FINE_LOCATION;
    private static final String COARSE_LOCATION = Manifest.permission.ACCESS_COARSE_LOCATION;
    private static final int PERMISSION_REQUEST_CODE = 1234;
    private GeoApiContext mGeoApiContext = null;
    private String title, desciption, uri;

    private EditText etText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        etText = findViewById(R.id.mapsET);
        Intent i = getIntent();
        title = i.getStringExtra("title");
        desciption = i.getStringExtra("description");
        uri = i.getStringExtra("uri");

        View decoreView = getWindow().getDecorView();
        int uiOptions = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION;

        decoreView.setSystemUiVisibility(uiOptions);

        getLocationPermission();
        getDevLocation();
    }


    private void init(){
        etText.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
                if(actionId == EditorInfo.IME_ACTION_SEARCH || actionId == EditorInfo.IME_ACTION_DONE || event.getAction() == KeyEvent.ACTION_DOWN
                        || event.getAction() == KeyEvent.KEYCODE_ENTER){
                    geoLocate();
                }
                return false;
            }
        });
    }


    private void geoLocate() {
        String strSearch = etText.getText().toString();
        Geocoder geocoder = new Geocoder(this);
        List<Address> list = new ArrayList<>();
        try {
            list = geocoder.getFromLocationName(strSearch, 1);
        } catch (IOException e){
            Log.e(TAG, e.getMessage());
        }
        if(list.size() > 0){
            address = list.get(0);
            Log.d(TAG, "Find Location: " + address.toString());
            moveMap(new LatLng(address.getLatitude(),address.getLongitude()), 15f, strSearch);
        }
    }


    private void getDevLocation() {
        mfusedLocationProviderClient = LocationServices.getFusedLocationProviderClient(this);
        try {
            if (mLocationPermission) {
                Task location = mfusedLocationProviderClient.getLastLocation();
                location.addOnCompleteListener(new OnCompleteListener() {
                    @Override
                    public void onComplete(@NonNull Task task) {
                        if (task.isSuccessful()) {
                            Log.d(TAG, "found location!");
                            currentLocation = (Location) task.getResult();
                            moveMap(new LatLng(currentLocation.getLatitude(), currentLocation.getLongitude()), 15f, "My Location");
                        } else
                            Log.d(TAG, null);
                    }
                });
            }
        } catch (SecurityException e) {
            Log.e(TAG, "getDevLoc: Security Exception " + e.getMessage());
        }

    }

    private void moveMap(LatLng latLng, float zoom, String strTitle) {
        Log.d(TAG, latLng.latitude + ", " + latLng.longitude);
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(latLng, zoom));

        MarkerOptions options = new MarkerOptions().position(latLng).title(strTitle);
        mMap.addMarker(options);
    }


    //Checks if permission are granted, if not it will ask you if you want to enable them, will not run map unless allowed
    private void getLocationPermission() {
        String[] permissions = {Manifest.permission.ACCESS_FINE_LOCATION,
                Manifest.permission.ACCESS_COARSE_LOCATION};

        if (ContextCompat.checkSelfPermission(this.getApplicationContext(),
                FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            if (ContextCompat.checkSelfPermission(this.getApplicationContext(),
                    COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
                mLocationPermission = true;
                initMap();
            } else {
                ActivityCompat.requestPermissions(this,
                        permissions,
                        PERMISSION_REQUEST_CODE);
            }
        } else {
            ActivityCompat.requestPermissions(this,
                    permissions,
                    PERMISSION_REQUEST_CODE);
        }
    }

    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        mLocationPermission = false;

        switch (requestCode) {
            case PERMISSION_REQUEST_CODE: {
                if (grantResults.length > 0) {
                    for (int i : grantResults) {
                        if (grantResults[i] != PackageManager.PERMISSION_GRANTED) {
                            mLocationPermission = false;
                            return;
                        }
                    }
                    mLocationPermission = true;
                    //initialize our map
                    initMap();
                }
            }
        }
    }


    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */

    private void initMap() {
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);

        if(mGeoApiContext == null){
            mGeoApiContext = new GeoApiContext.Builder().apiKey(getString(R.string.google_maps_key)).build();
        }
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        // Add a marker in Sydney and move the camera
        if (mLocationPermission) {
            getDevLocation();

            if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
                return;
            }
            mMap.setMyLocationEnabled(true);
            mMap.getUiSettings().setMyLocationButtonEnabled(false);

            init();
        }
    }

    public void onClick(View view){
        if(view.getId() == R.id.mGPS){
            getDevLocation();
        }
        if(view.getId() == R.id.mSave){
            saveLocation(new LatLng(currentLocation.getLatitude(), currentLocation.getLongitude()));
        }
    }

    private void saveLocation(LatLng latLng) {
        String latLong, latLat;
        latLat = Double.toString(latLng.latitude);
        latLong = Double.toString(latLng.longitude);
        Toast.makeText(this, latLat + ", " + latLong, Toast.LENGTH_LONG).show();
        Intent i = new Intent(MapsActivity.this, UploadActivity.class);
        i.putExtra("lat", latLat);
        i.putExtra("long", latLong);
        i.putExtra("title", title);
        i.putExtra("description", desciption);
        i.putExtra("uri", uri);
        startActivity(i);

    }
}
