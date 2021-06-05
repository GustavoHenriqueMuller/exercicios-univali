package com.example.myapplication.item;

public class Item {
    private int id;
    private String name;
    private String description;
    private double price;
    private int hasGluten;
    private double calories;
    private String url;

    public Item(int id, String name, String description, double price, int hasGluten, double calories, String url) {
        this.id = id;
        this.name = name;
        this.description = description;
        this.price = price;
        this.hasGluten = hasGluten;
        this.calories = calories;
        this.url = url;
    }

    public int getId() { return id; }

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

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getHasGluten() {
        return hasGluten;
    }

    public void setHasGluten(int containsGluten) {
        this.hasGluten = containsGluten;
    }

    public double getCalories() {
        return calories;
    }

    public void setCalories(double calories) {
        this.calories = calories;
    }

    public String getUrl() { return url; }

    public void setURL(String url) {
        this.url = url;
    }
}
