package com.example.trabalho1.fragments;

import android.content.Intent;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.trabalho1.R;
import com.example.trabalho1.activities.RestaurantesActivity;
import com.example.trabalho1.restaurant.Franchise;

public class FragmentFranchise extends Fragment {

    private Franchise franchise;

    public FragmentFranchise() {}

    public static FragmentFranchise newInstance(Franchise franchise) {
        FragmentFranchise fragment = new FragmentFranchise();
        fragment.franchise = franchise;

        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View v = inflater.inflate(R.layout.fragment_franchise, container, false);

        // Sets attributes
        TextView name = v.findViewById(R.id.name);
        TextView description = v.findViewById(R.id.description);
        ImageView image = v.findViewById(R.id.image);

        name.setText(franchise.getName());
        description.setText(franchise.getDescription());
        image.setBackgroundResource(franchise.getImageIdentifier());

        // Leads to restaurants
        v.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getContext(), RestaurantesActivity.class);
                intent.putExtra("Franchise", franchise);
                startActivity(intent);
            }
        });

        return v;
    }
}