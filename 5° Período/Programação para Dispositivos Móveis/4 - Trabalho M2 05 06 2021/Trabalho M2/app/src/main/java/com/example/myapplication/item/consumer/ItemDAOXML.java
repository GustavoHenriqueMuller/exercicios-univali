package com.example.myapplication.item.consumer;

import com.example.myapplication.item.Item;
import com.example.myapplication.item.adapters.StreamToStringAdapter;

import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

import java.io.IOException;
import java.io.InputStream;
import java.io.StringReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

public class ItemDAOXML implements IItemDAOReadOnly {
    private List<Item> getItemsFromResponse(String response) throws IOException, ParserConfigurationException, SAXException {
        // Parses XML response to extract item data
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();

        // Transforms XML into document
        StringReader sr = new StringReader(response);
        InputSource is = new InputSource(sr);
        Document doc = dBuilder.parse(is);

        // Gets each item element
        int qntItems = doc.getElementsByTagName("item").getLength();
        NodeList idList = doc.getElementsByTagName("id");
        NodeList nameList = doc.getElementsByTagName("name");
        NodeList descriptionList = doc.getElementsByTagName("description");
        NodeList priceList = doc.getElementsByTagName("price");
        NodeList hasGlutenlist = doc.getElementsByTagName("hasGluten");
        NodeList caloriesList = doc.getElementsByTagName("calories");
        NodeList urlList = doc.getElementsByTagName("url");

        ArrayList<Item> items = new ArrayList<>();

        for(int i = 0; i < qntItems; i++) {
            Item newItem = new Item(Integer.parseInt(idList.item(i).getTextContent()),
                                    nameList.item(i).getTextContent(),
                                    descriptionList.item(i).getTextContent(),
                                    Double.parseDouble(priceList.item(i).getTextContent()),
                                    Integer.parseInt(hasGlutenlist.item(i).getTextContent()),
                                    Double.parseDouble(caloriesList.item(i).getTextContent()),
                                    urlList.item(i).getTextContent());

            items.add(newItem);
        }

        return items;
    }

    private String makeRequest(String url) throws IOException {
        // Make request
        URL itemURL = new URL(url);
        HttpURLConnection con = (HttpURLConnection) itemURL.openConnection();
        con.setRequestMethod("GET");
        con.setRequestProperty("Accept", "application/xml");

        // Gets response
        InputStream is = con.getInputStream();
        String response = StreamToStringAdapter.convert(is);

        // Disconnecting
        con.disconnect();
        is.close();

        return response;
    }

    public Item getItemById(Integer itemId) throws IOException, ParserConfigurationException, SAXException {
        String response = makeRequest("http://192.168.3.122:8080/item/" + itemId);
        return  getItemsFromResponse(response).get(0);
    }

    public List<Item> getAllItems() throws IOException, ParserConfigurationException, SAXException {
        String response = makeRequest("http://192.168.3.122:8080/item");
        return getItemsFromResponse(response);
    }
}
