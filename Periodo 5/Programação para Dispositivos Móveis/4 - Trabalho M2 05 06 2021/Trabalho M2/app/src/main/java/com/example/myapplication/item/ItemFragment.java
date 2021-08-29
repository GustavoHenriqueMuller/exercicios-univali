package com.example.myapplication.item;

import android.graphics.Bitmap;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.myapplication.R;
import com.example.myapplication.bitmap.BitmapDAOFile;
import com.example.myapplication.tasks.DownloadImageTask;

public class ItemFragment extends Fragment {
    private Item item;
    private boolean omitPrice;
    private boolean pickImageFromFileSystem;

    public static ItemFragment newInstance(Item item, boolean omitPrice, boolean pickImageFromFileSystem) {
        ItemFragment fragment = new ItemFragment();
        fragment.item = item;
        fragment.omitPrice = omitPrice;
        fragment.pickImageFromFileSystem = pickImageFromFileSystem;

        return fragment;
    }

    private void mapToViewElements(View v) {
        // Gets layout elements
        TextView itemName = v.findViewById(R.id.ItemName);
        TextView itemDescription = v.findViewById(R.id.ItemDescription);
        TextView itemPrice = v.findViewById(R.id.ItemPrice);
        TextView itemHasGluten = v.findViewById(R.id.ItemHasGluten);
        TextView itemCalories = v.findViewById(R.id.ItemCalories);
        ImageView itemImage = v.findViewById(R.id.ItemImage);

        // Maps values of layout elements to item attributes
        itemName.setText(item.getName());
        itemDescription.setText(item.getDescription());
        itemPrice.setText("Price: " + (omitPrice ? "to consult..." : ("$" + item.getPrice())));
        itemHasGluten.setText("Gluten: " + (item.getHasGluten() == 1 ? "yes" : "no"));
        itemCalories.setText("Calories: " + item.getCalories() + "kcal");

        // Gets the image bitmap
        if(pickImageFromFileSystem) {
            // Bitmap from file system
            BitmapDAOFile bitmapDAOFile = new BitmapDAOFile();
            Bitmap bitmap = bitmapDAOFile.getBitmap(getContext(), item.getName());
            itemImage.setImageBitmap(bitmap);
        } else {
            // URL call
            DownloadImageTask imageTask = new DownloadImageTask(itemImage, getContext(), item.getName());
            imageTask.execute(item.getUrl());
        }
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View fragmentView = inflater.inflate(R.layout.fragment_item, container, false);
        mapToViewElements(fragmentView);
        return fragmentView;
    }
}