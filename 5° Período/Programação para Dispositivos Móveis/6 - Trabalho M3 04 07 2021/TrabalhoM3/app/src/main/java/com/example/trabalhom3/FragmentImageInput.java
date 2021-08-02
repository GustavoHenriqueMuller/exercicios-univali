package com.example.trabalhom3;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.drawable.Drawable;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.FileNotFoundException;
import java.io.InputStream;

public class FragmentImageInput extends Fragment {
    private boolean imageIsEmpty = true;
    private ImageView imageView;
    private Context previousContext;
    private Activity activity;
    private int imageIndex = 0;

    static final int REQUEST_IMAGE_CAPTURE = 1;
    static final int PICK_IMAGE = 4;

    public FragmentImageInput() {}

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data){
        if(resultCode == Activity.RESULT_OK) {
            try {
                switch(requestCode) {
                    case REQUEST_IMAGE_CAPTURE:
                        Bundle extras = data.getExtras();
                        Bitmap imageBitmap = (Bitmap) extras.get("data");
                        imageView.setImageBitmap(imageBitmap);
                        break;
                    case PICK_IMAGE:
                        InputStream inputStream = previousContext.getApplicationContext().getContentResolver().openInputStream(data.getData());
                        imageView.setImageBitmap(BitmapFactory.decodeStream(inputStream));
                        break;
                }

                imageIsEmpty = false;
            } catch(FileNotFoundException e) {
                Toast.makeText(previousContext, getString(R.string.image_get_error_exception), Toast.LENGTH_SHORT).show();
            }
        } else {
            Toast.makeText(previousContext, getString(R.string.image_get_error), Toast.LENGTH_SHORT).show();
        }
    }

    public static FragmentImageInput newInstance(Context previousContext, Activity activity, int imageIndex) {
        FragmentImageInput fragment = new FragmentImageInput();
        fragment.previousContext = previousContext;
        fragment.activity = activity;
        fragment.imageIndex = imageIndex;

        return fragment;
    }

    private void selectImageDialog() {
        final CharSequence[] options = {getString(R.string.image_get_from_camera), getString(R.string.image_get_from_library)};

        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setTitle(getString(R.string.image_choose));

        builder.setItems(options, (dialog, selectedIndex) -> {
            CharSequence selectedOption = options[selectedIndex];

            if (selectedOption.equals(getString(R.string.image_get_from_camera))) {
                Intent intent = new Intent(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
                startActivityForResult(intent, REQUEST_IMAGE_CAPTURE);

            } else if (selectedOption.equals(getString(R.string.image_get_from_library))) {
                Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
                intent.setType("image/*");
                startActivityForResult(intent, PICK_IMAGE);

            } else if (selectedOption.equals("Cancel")) {
                dialog.dismiss();
            }
        });

        builder.show();
    }

    private Bitmap getBitmapFromDrawable(Drawable drawable) {
        final Bitmap bmp = Bitmap.createBitmap(drawable.getIntrinsicWidth(), drawable.getIntrinsicHeight(), Bitmap.Config.ARGB_8888);
        final Canvas canvas = new Canvas(bmp);
        drawable.setBounds(0, 0, canvas.getWidth(), canvas.getHeight());
        drawable.draw(canvas);

        return bmp;
    }

    public Bitmap getImageBitmap() {
        return imageIsEmpty ? null : getBitmapFromDrawable(imageView.getDrawable());
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View fragmentView = inflater.inflate(R.layout.fragment_image_input, container, false);
        final Button buttonSelectImage = fragmentView.findViewById(R.id.buttonSelectImage);
        this.imageView = fragmentView.findViewById(R.id.imageView);

        buttonSelectImage.setText("SELECT IMAGE " + this.imageIndex);
        buttonSelectImage.setOnClickListener(v -> selectImageDialog());

        return fragmentView;
    }
}