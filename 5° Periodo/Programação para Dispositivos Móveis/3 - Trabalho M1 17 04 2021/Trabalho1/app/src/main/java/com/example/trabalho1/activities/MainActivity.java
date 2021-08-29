package com.example.trabalho1.activities;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.widget.LinearLayout;
import android.widget.SearchView;

import com.example.trabalho1.R;
import com.example.trabalho1.fragments.FragmentFranchise;
import com.example.trabalho1.restaurant.Franchise;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private static final int minimumFranchises = 10;

    private List<Franchise> createFranchises(String conditionText) {
        List<Franchise> franchises = new ArrayList<>();

        // Creates franchises
        for(int i = 0; i < minimumFranchises; i++) {
            String name = "Franquia " + i;
            String description = getString(R.string.lorem_ipsum);
            int imageIdentifier = R.drawable.restaurant_image_foreground;

            if(conditionText.isEmpty() || (name.contains(conditionText) || description.contains(conditionText))) {
                franchises.add(new Franchise(name, description, imageIdentifier));
            }
        }

        return franchises;
    }

    private void updateFranchiseList(String conditionText) {
        LinearLayout franchiseLL = (LinearLayout) findViewById(R.id.franchiseList);
        FragmentManager fm = getSupportFragmentManager();
        List<Franchise> franchises = createFranchises(conditionText);

        // Clears linear layout
        franchiseLL.removeAllViews();

        // Creates and adds views
        for(int i = 0; i < franchises.size(); i++) {
            FragmentTransaction fragmentTransaction = fm.beginTransaction();
            FragmentFranchise franchiseFragment = FragmentFranchise.newInstance(franchises.get(i));
            fragmentTransaction.add(franchiseLL.getId(), franchiseFragment).commit();
        }
    }

    private void addSearchListener() {
        SearchView searchFranchise = (SearchView) findViewById(R.id.searchFranchise);
        searchFranchise.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {
                updateFranchiseList(query);
                return true;
            }

            @Override
            public boolean onQueryTextChange(String newText) {
                updateFranchiseList(newText);
                return true;
            }
        });
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        addSearchListener();
        updateFranchiseList("");
    }
}