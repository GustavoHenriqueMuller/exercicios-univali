package com.example.myapplication.item.consumer;

import com.example.myapplication.item.Item;
import com.example.myapplication.item.adapters.StreamToStringAdapter;
import com.google.gson.Gson;

import org.json.JSONArray;
import org.json.JSONException;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

public class ItemDAOJSON implements IItemDAOReadOnly {
    private List<Item> getItemsFromResponse(String response) throws JSONException {
        JSONArray jsonArr = new JSONArray(response);
        ArrayList<Item> items = new ArrayList<>();
        Gson gson = new Gson();

        // Parses JSON array for each object
        for(int i = 0; i < jsonArr.length(); i++) {
            items.add(gson.fromJson(jsonArr.get(i).toString(), Item.class));
        }

        return items;
    }

    private String makeRequest(String url) throws IOException {
        // Make request
        URL itemURL = new URL(url);
        HttpURLConnection con = (HttpURLConnection) itemURL.openConnection();
        con.setRequestMethod("GET");
        con.setRequestProperty("Accept", "application/json");

        // Gets response
        InputStream is = con.getInputStream();
        String response = StreamToStringAdapter.convert(is);

        // Disconnecting
        con.disconnect();
        is.close();

        return response;
    }

    public Item getItemById(Integer itemId) throws IOException, JSONException {
        String response = makeRequest("http://192.168.3.122:8080/item/" + itemId);
        return getItemsFromResponse(response).get(0);
    }

    public List<Item> getAllItems() throws IOException, JSONException {
        String response = makeRequest("http://192.168.3.122:8080/item");
        return getItemsFromResponse(response);
    }
}
