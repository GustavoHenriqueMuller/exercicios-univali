const threadAPI = require('./api/thread');
const postAPI = require('./api/post');

const { MongoClient } = require('mongodb');
const Express = require('express');
const cors = require('cors');

// Configuring APP to use CORS and JSON
const port = 8080;
const app = Express();
app.use(cors());
app.use(Express.json());

function defineAPI(client) {    
    const threadCollection = client.db('boardData').collection('thread');
    const postCollection = client.db('boardData').collection('post');

    // THREAD API
    app.get   ('/thread'    , (req, res) => threadAPI.getAllThreads   (req, res, threadCollection));
    app.get   ('/thread/:id', (req, res) => threadAPI.getThreadByID   (req, res, threadCollection));
    app.post  ('/thread'    , (req, res) => threadAPI.createThread    (req, res, threadCollection));
    app.put   ('/thread/:id', (req, res) => threadAPI.updateThreadByID(req, res, threadCollection));
    app.delete('/thread/:id', (req, res) => threadAPI.deleteThreadByID(req, res, threadCollection, postCollection));

    // POST API
    app.get   ('/post'           , (req, res) => postAPI.getAllPosts       (req, res, postCollection));
    app.get   ('/post/:id'       , (req, res) => postAPI.getPostByID       (req, res, postCollection));
    app.get   ('/thread/:id/post', (req, res) => postAPI.getPostsByThreadID(req, res, postCollection));
    app.post  ('/post'           , (req, res) => postAPI.createPost        (req, res, postCollection));
    app.put   ('/post/:id'       , (req, res) => postAPI.updatePostByID    (req, res, postCollection));
    app.delete('/post/:id'       , (req, res) => postAPI.deletePostByID    (req, res, postCollection));
}

console.clear();
MongoClient.connect('mongodb+srv://gustavo:root@application.bdhow.mongodb.net/test',
                    {useNewUrlParser: true, useUnifiedTopology: true},
                    (err, client) => {
                        if (err) return console.error(err);
                        console.log('Connected to MongoDB.');
                        defineAPI(client);
                    });

app.listen(port, () => console.log(`Back-end serving API at: http://localhost:${port}`));