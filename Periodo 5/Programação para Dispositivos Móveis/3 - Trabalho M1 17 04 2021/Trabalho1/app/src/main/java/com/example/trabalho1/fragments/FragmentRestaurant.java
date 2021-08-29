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
import com.example.trabalho1.restaurant.Restaurant;

public class FragmentRestaurant extends Fragment {

    private Restaurant restaurant;

    public FragmentRestaurant() {}

    public static FragmentRestaurant newInstance(Restaurant restaurant) {
        FragmentRestaurant fragment = new FragmentRestaurant();
        fragment.restaurant = restaurant;
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) { super.onCreate(savedInstanceState); }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View v = inflater.inflate(R.layout.fragment_restaurant, container, false);

        // Sets attributes
        TextView name = v.findViewById(R.id.name);
        TextView city = v.findViewById(R.id.city);
        TextView address = v.findViewById(R.id.address);
        ImageView image = v.findViewById(R.id.image);

        name.setText(restaurant.getName());
        city.setText(restaurant.getCity());
        address.setText(restaurant.getAddress());
        image.setBackgroundResource(restaurant.getImageIdentifier());

        return v;
    }
}