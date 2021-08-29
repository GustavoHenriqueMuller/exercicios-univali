package com.example.trabalhom3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentTransaction;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private final int AMOUNT_IMAGE_INPUTS = 3;

    private void setMessageResult(String message) {
        TextView messageView = findViewById(R.id.textViewResult);
        messageView.setText(message);
    }

    private void addFragmentToList(LinearLayout itemList, FragmentImageInput imageInputFragment) {
        FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
        fragmentTransaction.add(itemList.getId(), imageInputFragment).commit();
    }

    private boolean evaluateImages(List<Bitmap> bitmaps) {
        for(int i = 0; i < bitmaps.size() - 1; i++) {
            if (!(bitmaps.get(i).sameAs(bitmaps.get(i + 1)))) {
                return false;
            }
        }

        return true;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        LinearLayout imageList = findViewById(R.id.listImageInputFragments);
        List<FragmentImageInput> fragmentsImageInput = new ArrayList<>();

        for(int i = 0; i < AMOUNT_IMAGE_INPUTS; i++) {
            FragmentImageInput imageInputFragment = FragmentImageInput.newInstance(getApplicationContext(), MainActivity.this, i);
            fragmentsImageInput.add(imageInputFragment);
            addFragmentToList(imageList, imageInputFragment);
        }

        final Button evaluateButton = findViewById(R.id.buttonEvaluate);
        evaluateButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                List<Bitmap> bitmaps = new ArrayList<>();

                for(FragmentImageInput fragment : fragmentsImageInput) {
                    Bitmap currentBitmap = fragment.getImageBitmap();

                    if(currentBitmap == null) {
                        setMessageResult(getString(R.string.image_evaluation_not_enough_images));
                        return;
                    } else {
                        bitmaps.add(currentBitmap);
                    }
                }

                boolean allAreEqual = evaluateImages(bitmaps);
                String messageString = allAreEqual ? getString(R.string.image_evaluation_success) : getString(R.string.image_evaluation_failure);
                setMessageResult(messageString);
            }
        });
    }
}