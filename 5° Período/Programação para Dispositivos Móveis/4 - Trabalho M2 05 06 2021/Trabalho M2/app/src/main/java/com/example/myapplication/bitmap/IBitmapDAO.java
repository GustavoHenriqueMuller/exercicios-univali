package com.example.myapplication.bitmap;

import android.content.Context;
import android.graphics.Bitmap;

import java.io.FileNotFoundException;
import java.io.IOException;

public interface IBitmapDAO {
    Bitmap getBitmap(Context context, String name);
    void saveBitmap(Context context, String name, Bitmap bitmap) throws IOException;
}
