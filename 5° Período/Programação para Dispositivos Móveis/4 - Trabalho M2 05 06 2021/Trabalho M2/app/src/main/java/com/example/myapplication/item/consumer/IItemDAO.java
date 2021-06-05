package com.example.myapplication.item.consumer;

import com.example.myapplication.item.Item;

import org.json.JSONException;
import org.xml.sax.SAXException;

import java.io.IOException;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

public interface IItemDAO extends IItemDAOReadOnly {
    void persistItem(Item item);
    void updateItemById(Integer itemId, Item newItem);
}
