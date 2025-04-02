package com.grptwo.greengrowth;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class LoginActivity extends AppCompatActivity {
    EditText username, password;
    Button loginButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        username = findViewById(R.id.username);
        password = findViewById(R.id.password);
        loginButton = findViewById(R.id.loginButton);

        loginButton.setOnClickListener(v -> {
            String user = username.getText().toString();
            String pass = password.getText().toString();

            // Simple check (You can replace with a more secure method)
            if (user.equals("admin") && pass.equals("admin")) {
                // Login success
                startActivity(new Intent(LoginActivity.this, MainActivity.class));
                finish(); // To ensure LoginActivity is removed from the stack
            } else {
                Toast.makeText(LoginActivity.this, "Invalid login!", Toast.LENGTH_SHORT).show();
            }
        });
    }
}
