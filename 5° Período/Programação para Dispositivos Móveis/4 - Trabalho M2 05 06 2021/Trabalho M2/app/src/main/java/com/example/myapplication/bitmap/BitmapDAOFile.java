package com.example.myapplication.bitmap;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class BitmapDAOFile implements IBitmapDAO {
    @Override
    public Bitmap getBitmap(Context context, String name) {
        File file = new File(context.getFilesDir(), name + ".png");
        return BitmapFactory.decodeFile(file.getPath());
    }

    @Override
    public void saveBitmap(Context context, String name, Bitmap bitmap) throws IOException {
        File file = new File(context.getFilesDir(), name + ".png");
        FileOutputStream out = new FileOutputStream(file);
        bitmap.compress(Bitmap.CompressFormat.PNG, 100, out);

        out.flush();
        out.close();
    }
}
