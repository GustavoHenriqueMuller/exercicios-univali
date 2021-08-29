package com.example.atividade3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class FactPresentationActivity extends AppCompatActivity {

    private Integer fact(int n) {
        if((n == 0) || (n == 1)) {
            return 1;
        } else {
            return n * fact(n-1);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fact_presentation);

        Integer n = Integer.parseInt(getIntent().getStringExtra("fact"));
        TextView resultado = findViewById(R.id.resultado);
        Button buttonRetornar = findViewById(R.id.buttonRetornar);

        buttonRetornar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent switchActivityIntent = new Intent(v.getContext(), MainActivity.class);
                startActivity(switchActivityIntent);
            }
        });

        resultado.setText("Resultado: " + String.valueOf(fact(n)));
    }
}