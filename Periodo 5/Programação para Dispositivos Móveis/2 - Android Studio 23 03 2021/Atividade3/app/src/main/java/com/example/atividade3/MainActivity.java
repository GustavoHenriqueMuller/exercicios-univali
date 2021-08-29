package com.example.atividade3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btnCalculate = findViewById(R.id.btnCalculate);

        btnCalculate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                toPresentation();
            }
        });
    }

    private void toPresentation() {
        EditText inputFact = findViewById(R.id.inputFact);

        try {
            Integer n = Integer.parseInt(inputFact.getText().toString());
            Intent switchActivityIntent = new Intent(this, FactPresentationActivity.class);
            switchActivityIntent.putExtra("fact", String.valueOf(n));
            startActivity(switchActivityIntent);
        } catch(NumberFormatException e) {
            Toast toast = Toast.makeText(getApplicationContext(), "Valor de fatorial inválido/muito grande!", Toast.LENGTH_SHORT);
            toast.show();
        }
    }
}