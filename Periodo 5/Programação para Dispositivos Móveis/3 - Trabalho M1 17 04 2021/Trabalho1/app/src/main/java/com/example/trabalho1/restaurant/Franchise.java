package com.example.trabalho1.restaurant;

import com.example.trabalho1.R;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Franchise implements Serializable  {
    public static final int minimumRestaurants = 6;
    private List<Restaurant> restaurants = new ArrayList<>();
    private String name;
    private String description;
    private int imageIdentifier;

    public Franchise(String name, String description, int imageIdentifier) {
        this.name = name;
        this.description = description;
        this.imageIdentifier = imageIdentifier;

        // Creates new restaurants
        for(int i = 0; i < minimumRestaurants; i++) {
            String restaurantName = "Restaurante " + i + " de '" + this.name + "'";
            String restaurantAddress = "Rua " + (int) (Math.random() * 1000) + ", número " + (int) (Math.random() * 500);
            String restaurantCity = "Balneário Camboriú";
            int restaurantImageIdentifier = R.drawable.restaurant_image_foreground;

            restaurants.add(new Restaurant(restaurantName, restaurantAddress, restaurantCity, restaurantImageIdentifier));
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public int getImageIdentifier() {
        return imageIdentifier;
    }

    public void setImageIdentifier(int imageIdentifier) {
        this.imageIdentifier = imageIdentifier;
    }

    public int getMinimumRestaurants() {
        return minimumRestaurants;
    }

    public List<Restaurant> getRestaurants() {
        return restaurants;
    }
}
