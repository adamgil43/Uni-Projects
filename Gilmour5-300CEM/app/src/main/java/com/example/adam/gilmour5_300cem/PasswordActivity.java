package com.example.adam.gilmour5_300cem;

import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

public class PasswordActivity extends AppCompatActivity {

    private EditText etPassword, etConPass;
    FirebaseUser user;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_password);

        etPassword = findViewById(R.id.asPass);
        etConPass = findViewById(R.id.asConPass);

        user = FirebaseAuth.getInstance().getCurrentUser();

        Toolbar toolbar = findViewById(R.id.asToolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setTitle("Change Password");
    }

    public void onClick(View v){
        if (v.getId() == R.id.asUpdate){
            String password = etPassword.getText().toString();
            String conPass = etConPass.getText().toString();
            if (!TextUtils.isEmpty(password) && !TextUtils.isEmpty(conPass)){
                if (conPass.equals(password)){
                    user.updatePassword(conPass).addOnCompleteListener(new OnCompleteListener<Void>() {
                        @Override
                        public void onComplete(@NonNull Task<Void> task) {
                            if (task.isSuccessful()){
                                Toast.makeText(PasswordActivity.this,"Password Changed", Toast.LENGTH_LONG).show();
                                finish();
                            } else {
                                String errorMessage = task.getException().getMessage();
                                Toast.makeText(PasswordActivity.this, "Error : " + errorMessage, Toast.LENGTH_LONG).show();
                            }
                        }
                    });
                } else {
                    Toast.makeText(this,"Passwords are not the same", Toast.LENGTH_LONG).show();
                }
            }
        }
        if (v.getId() == R.id.asBack){
            finish();
        }

    }
}
