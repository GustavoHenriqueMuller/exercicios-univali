const MySQL = require('mysql');
const Express = require('express');
const JStoXML = require('js2xmlparser');

const app = Express();
const PORT = 8080;

// Connection to MySQL Database
const connection = MySQL.createConnection({
    host: 'localhost',
    user: 'gustavo',
    password: 'admin'
});

// Gets data formatted for XML or JSON
function formatData(data, req) {
    if (req.accepts('application/xml')) {
        return {responseData: JStoXML.parse('items', {'item' : data}), status: 200, contentType: 'application/xml'};
    } else if(req.accepts('json')) {
        return {responseData: data, status: 200, contentType: 'application/json'};
    } else {
        return {responseData: 'Data format not acceptable.', status: 406, contentType: 'text/html'};
    }
}

// Listing API endpoints
app.get('/item', (req, res) => {
    let sql = 'SELECT * FROM trabalhom2.Item;';
    
    // Queries for all items
    connection.query(sql, (err, result) => {
        if (err) throw err;

        // Returns XML or JSON
        let formattedData = formatData(result, req);
        res.type(formattedData.contentType);
        res.status(formattedData.status).send(formattedData.responseData);
    });
});

app.get('/item/:id', (req, res) => {
    let itemId = req.params.id;
    let sql = 'SELECT * FROM trabalhom2.Item WHERE trabalhom2.Item.id = ?;';
    
    // Queries for specific item
    connection.query(sql, [itemId], (err, result) => {
        if (err) throw err;

        // Returns XML or JSON
        let formattedData = formatData(result, req);
        res.type(formattedData.contentType);
        res.status(formattedData.status).send(formattedData.responseData);
    });
});

// Starting connections
connection.connect((err) => {
    if (err) throw err;
    console.log('Back-end connected to MySQL Database.')
});

app.listen(PORT, () => console.log(`Back-end serving API at: http://localhost:${PORT}`));