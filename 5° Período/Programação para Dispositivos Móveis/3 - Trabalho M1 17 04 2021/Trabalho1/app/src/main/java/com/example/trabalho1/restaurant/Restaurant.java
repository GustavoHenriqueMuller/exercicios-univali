package com.example.trabalho1.restaurant;

import java.io.Serializable;

public class Restaurant implements Serializable {
    private String name;
    private String address;
    private String city;
    private int imageIdentifier;

    public Restaurant(String name, String address, String city, int imageIdentifier) {
        this.name = name;
        this.address = address;
        this.city = city;
        this.imageIdentifier = imageIdentifier;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public int getImageIdentifier() {
        return imageIdentifier;
    }

    public void setImageIdentifier(int imageIdentifier) {
        this.imageIdentifier = imageIdentifier;
    }
}
