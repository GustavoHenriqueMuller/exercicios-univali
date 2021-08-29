package com.example.myapplication.item.consumer;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

import com.example.myapplication.item.Item;

import java.util.ArrayList;
import java.util.List;

public class ItemDAOSQLite extends SQLiteOpenHelper implements IItemDAO {
    private static final String dbname = "TrabalhoM2";

    public ItemDAOSQLite(@Nullable Context context, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, dbname, factory, version);

        this.getWritableDatabase().execSQL("PRAGMA foreign_keys = ON;");
        this.getWritableDatabase().execSQL(
                "CREATE TABLE IF NOT EXISTS Item (" +
                        "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                        "name VARCHAR(60)," +
                        "description VARCHAR(500)," +
                        "price FLOAT," +
                        "hasGluten TINYINT," +
                        "calories FLOAT," +
                        "url VARCHAR(1000)" +
                        ");"
        );
    }

    @Override
    public void onCreate(SQLiteDatabase db) {}

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {}

    public void persistItem(Item item) {
        String sql = "INSERT INTO Item (name, description, price, hasGluten, calories, url) VALUES (?, ?, ?, ?, ?, ?);";
        this.getWritableDatabase().execSQL(sql, new Object[]{item.getName(), item.getDescription(), item.getPrice(),
                item.getHasGluten(), item.getCalories(), item.getUrl()});
    }

    public void updateItemById(Integer itemId, Item item) {
        String sql = "UPDATE Item SET name = ?, description = ?, price = ?, hasGluten = ?, calories = ?, url = ? WHERE id = ?;";
        this.getWritableDatabase().execSQL(sql, new Object[]{item.getName(), item.getDescription(), item.getPrice(),
                item.getHasGluten(), item.getCalories(), item.getUrl(), itemId});
    }

    public Item getItemById(Integer itemId) {
        Cursor cursor = this.getReadableDatabase().rawQuery("SELECT id, name, description, price, hasGluten, calories, url " +
                                                                " FROM Item WHERE id = " + itemId + ";", null);
        cursor.moveToNext();
        if(cursor.getCount() > 0) {
            // Maps record to Item
            int id = cursor.getInt(0);
            String name = cursor.getString(1);
            String description = cursor.getString(2);
            Double price = cursor.getDouble(3);
            Integer hasGluten = cursor.getInt(4);
            Double calories = cursor.getDouble(5);
            String url = cursor.getString(6);

            Item item = new Item(id, name, description, price, hasGluten, calories, url);

            return item;
        } else {
            return null;
        }
    }

    public List<Item> getAllItems() {
        List<Item> items = new ArrayList<>();
        Cursor cursor = this.getReadableDatabase().rawQuery("SELECT id, name, description, price, hasGluten, calories, url" +
                                                                " FROM Item;", null);
        // Iterates over every record and maps to a new Item
        while(cursor.moveToNext()) {
            int id = cursor.getInt(0);
            String name = cursor.getString(1);
            String description = cursor.getString(2);
            Double price = cursor.getDouble(3);
            Integer hasGluten = cursor.getInt(4);
            Double calories = cursor.getDouble(5);
            String url = cursor.getString(6);

            Item item = new Item(id, name, description, price, hasGluten, calories, url);
            items.add(item);
        }

        return items;
    }
}
