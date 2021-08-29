package com.example.myapplication.item.adapters;

public abstract class StreamToStringAdapter {
    public static String convert(java.io.InputStream is) {
        java.util.Scanner s = new java.util.Scanner(is).useDelimiter("\\A");
        return s.hasNext() ? s.next() : "";
    }
}