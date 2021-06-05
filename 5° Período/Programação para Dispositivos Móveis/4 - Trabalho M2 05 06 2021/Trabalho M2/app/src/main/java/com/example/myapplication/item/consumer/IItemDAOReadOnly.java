package com.example.myapplication.item.consumer;

import com.example.myapplication.item.Item;

import org.json.JSONException;
import org.xml.sax.SAXException;

import java.io.IOException;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

public interface IItemDAOReadOnly {
    Item getItemById(Integer itemId) throws IOException, ParserConfigurationException, SAXException, JSONException;
    List<Item> getAllItems()  throws IOException, ParserConfigurationException, SAXException, JSONException;
}
