package com.example.atividade3exercicio2;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.graphics.Color;
import android.os.Bundle;
import android.widget.TextView;
import java.util.Calendar;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    enum DAY_STATE {
        DAY,
        NOON,
        NIGHT
    }

    private DAY_STATE getDayState(int hour) {
        if(hour >= 5 && hour <= 12) {
            return DAY_STATE.DAY;
        } else if(hour <= 18) {
            return DAY_STATE.NOON;
        } else {
            return DAY_STATE.NIGHT;
        }
    }

    private String getMessageOfHour(int hour) {
        DAY_STATE dayState = getDayState(hour);

        switch(dayState) {
            case DAY:
                return "Bom dia";
            case NOON:
                return "Boa tarde";
            case NIGHT:
                return "Boa noite";
        }

        return null;
    }

    private Integer getColorOfHour(int hour) {
        DAY_STATE dayState = getDayState(hour);

        switch(dayState) {
            case DAY:
                return Color.parseColor("#ffe08a");
            case NOON:
                return Color.parseColor("#93e868");
            case NIGHT:
                return Color.parseColor("#1f206b");
        }

        return null;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textoHorario = findViewById(R.id.textoHorario);
        ConstraintLayout constraintLayout = findViewById(R.id.constraintLayout);

        Date currentTime = Calendar.getInstance().getTime();
        int hours = currentTime.getHours();
        textoHorario.setText(getMessageOfHour(hours));
        constraintLayout.setBackgroundColor(getColorOfHour(hours));
    }
}