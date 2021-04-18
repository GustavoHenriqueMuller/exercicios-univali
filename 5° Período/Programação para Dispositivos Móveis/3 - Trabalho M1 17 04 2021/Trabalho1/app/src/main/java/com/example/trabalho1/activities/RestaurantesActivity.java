package com.example.trabalho1.activities;

import android.os.Bundle;

import com.example.trabalho1.R;
import com.example.trabalho1.fragments.FragmentFranchise;
import com.example.trabalho1.fragments.FragmentRestaurant;
import com.example.trabalho1.restaurant.Franchise;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.view.View;
import android.widget.LinearLayout;

import java.util.List;

public class RestaurantesActivity extends AppCompatActivity {
    private Franchise franchise;

    private void updateRestaurantList() {
        LinearLayout franchiseLL = (LinearLayout) findViewById(R.id.restaurantList);
        FragmentManager fm = getSupportFragmentManager();

        // Clears linear layout
        franchiseLL.removeAllViews();

        // Creates and adds views
        for(int i = 0; i < franchise.getRestaurants().size(); i++) {
            FragmentTransaction fragmentTransaction = fm.beginTransaction();
            FragmentRestaurant restaurantFragment = FragmentRestaurant.newInstance(franchise.getRestaurants().get(i));
            fragmentTransaction.add(franchiseLL.getId(), restaurantFragment).commit();
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_restaurantes);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        // Goes back to otherfranchises
        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });

        // Gets franchise and updates restaurants list
        franchise = (Franchise) getIntent().getSerializableExtra("Franchise");
        updateRestaurantList();
    }
}