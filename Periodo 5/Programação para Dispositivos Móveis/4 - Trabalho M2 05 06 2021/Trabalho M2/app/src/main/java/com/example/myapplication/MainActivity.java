package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentTransaction;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.example.myapplication.item.consumer.IItemDAOReadOnly;
import com.example.myapplication.item.consumer.ItemDAOJSON;
import com.example.myapplication.item.Item;
import com.example.myapplication.item.ItemFragment;
import com.example.myapplication.item.consumer.ItemDAOSQLite;
import com.example.myapplication.item.consumer.ItemDAOXML;

import org.json.JSONException;
import org.xml.sax.SAXException;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

public class MainActivity extends AppCompatActivity {
    // Checks if connected to internet
    private boolean connectedToInternet() {
        ConnectivityManager connectivity = (ConnectivityManager) getApplicationContext().getSystemService(Context.CONNECTIVITY_SERVICE);
        if (connectivity != null) {
            NetworkInfo[] info = connectivity.getAllNetworkInfo();
            if (info != null) {
                for (int i = 0; i < info.length; i++) {
                    if (info[i].getState() == NetworkInfo.State.CONNECTED) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // Adds item to item list
    private void addItemToList(Item item, LinearLayout itemList, boolean omitPrice, boolean pickImageFromFileSystem) {
        FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
        ItemFragment itemFragment = ItemFragment.newInstance(item, omitPrice, pickImageFromFileSystem);
        fragmentTransaction.add(itemList.getId(), itemFragment).commit();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ThreadGetItems getItemsThread;

        // Check if connected to internet to search for items on SQLite
        if(connectedToInternet()) {
            getItemsThread = new ThreadGetItems(new ItemDAOJSON());
        } else {
            getItemsThread = new ThreadGetItems(new ItemDAOSQLite(getApplicationContext(), null, 1));
        }

        getItemsThread.execute();
    }

    private class ThreadGetItems extends AsyncTask<String, Void, List<Item>> {
        private IItemDAOReadOnly consumer;
        private String errorMessage;

        ThreadGetItems(IItemDAOReadOnly consumer) {
            this.consumer = consumer;
        }

        private void persistItemsToSQLIDatabase(List<Item> items) {
            // Save items to SQLI database
            ItemDAOSQLite db = new ItemDAOSQLite(getApplicationContext(), null, 1);

            // Only adds items if there are no items in SQLI database
            for(Item item : items) {
                Item dbItem = db.getItemById(item.getId());

                if(dbItem == null) {
                    db.persistItem(item); // Insert item to SQLI if not exists
                } else {
                    db.updateItemById(dbItem.getId(), item); // Update item to SQLI if exists
                }
            }
        }

        @Override
        protected List<Item> doInBackground(String... urls) {
            List<Item> items = new ArrayList<>();

            try {
                items = (ArrayList<Item>) consumer.getAllItems();

                if(connectedToInternet())
                    persistItemsToSQLIDatabase(items);

                errorMessage = items.size() > 0 ? "" : getResources().getString(R.string.get_item_empty_error);
            } catch (IOException e) {
                errorMessage = getResources().getString(R.string.get_item_io_error);
            } catch (ParserConfigurationException e) {
                errorMessage = getResources().getString(R.string.get_item_parser_configuration_error);
            } catch (JSONException e) {
                errorMessage = getResources().getString(R.string.get_item_json_error);
            } catch (SAXException e) {
                errorMessage = getResources().getString(R.string.get_item_parser_sax_error);
            }

            return items;
        }

        @Override
        protected void onPostExecute (List<Item> items) {
            // Prints message if no items are present
            if(!errorMessage.isEmpty()) {
                Toast.makeText(getApplicationContext(), errorMessage, Toast.LENGTH_SHORT).show();
            } else {
                // Add received items to list
                LinearLayout itemList = findViewById(R.id.ItemList);
                boolean connected = connectedToInternet();

                for(Item item : items) {
                    addItemToList(item, itemList, !connected, !connected);
                }
            }
        }
    }
}