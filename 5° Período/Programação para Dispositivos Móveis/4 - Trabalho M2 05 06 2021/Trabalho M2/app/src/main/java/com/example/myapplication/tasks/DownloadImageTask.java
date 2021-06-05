package com.example.myapplication.tasks;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.widget.ImageView;

import com.example.myapplication.bitmap.BitmapDAOFile;

import java.io.IOException;
import java.net.URL;

public class DownloadImageTask extends AsyncTask<String, Void, Bitmap> {
    private ImageView imageView;
    private Context currentContext;
    private String fileName;

    public DownloadImageTask(ImageView imageView, Context currentContext, String fileName) {
        this.imageView = imageView;
        this.currentContext = currentContext;
        this.fileName = fileName;
    }

    @Override
    protected Bitmap doInBackground(String... urls) {
        try {
            URL imageURL = new URL(urls[0]);
            Bitmap bitmap = BitmapFactory.decodeStream(imageURL.openConnection().getInputStream());

            return bitmap;
        } catch(IOException e) {
            return null;
        }
    }

    @Override
    protected void onPostExecute(Bitmap bitmap) {
        if(bitmap != null) {
            imageView.setImageBitmap(bitmap);

            try {
                BitmapDAOFile bitmapDAOFile = new BitmapDAOFile();
                bitmapDAOFile.saveBitmap(currentContext, fileName, bitmap);
            } catch(IOException e) {
                return;
            }
        }
    }
}