package com.example.adam.gilmour5_300cem;

import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class RegisterActivity extends AppCompatActivity {

    private EditText etEmail, etPassword, etConPass;
    private FirebaseAuth mAuth;
    private ProgressBar arPB;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        mAuth = FirebaseAuth.getInstance();

        etEmail = findViewById(R.id.arEmail);
        etPassword = findViewById(R.id.arPassword);
        etConPass = findViewById(R.id.arConPassword);

        arPB = findViewById(R.id.arPB);

        arPB.setVisibility(View.INVISIBLE);
    }

    public void onClick(View v){
        if (v.getId() == R.id.arBtnReg){
            String email = etEmail.getText().toString();
            String password = etPassword.getText().toString();
            String cPassword = etConPass.getText().toString();

            if(!TextUtils.isEmpty(email) && !TextUtils.isEmpty(password) && !TextUtils.isEmpty(cPassword)){
                if(cPassword.equals(password)){
                    arPB.setVisibility(View.VISIBLE);
                    mAuth.createUserWithEmailAndPassword(email, cPassword).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
                        @Override
                        public void onComplete(@NonNull Task<AuthResult> task) {
                            if (task.isSuccessful()){
                                Toast.makeText(RegisterActivity.this, "Account Created", Toast.LENGTH_LONG).show();
                                sendToMain();
                            } else{
                                String errorMessage = task.getException().getMessage();
                                Toast.makeText(RegisterActivity.this, "Error : " + errorMessage, Toast.LENGTH_LONG).show();
                            }
                            arPB.setVisibility(View.INVISIBLE);
                        }
                    });
                }
            }
        }
        if (v.getId() == R.id.arBtnAlready){
            sendToLogin();
        }
    }

    private void sendToLogin() {
        Intent intent = new Intent(this, LoginActivity.class);
        startActivity(intent);
        finish();
    }

    private void sendToMain() {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
        finish();
    }}
