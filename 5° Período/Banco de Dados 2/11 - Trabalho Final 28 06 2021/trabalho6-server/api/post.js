const { ObjectID } = require('bson');

function getAllPosts(req, res, postCollection) {
    postCollection.find().toArray((err, res) => {
        if (err) throw err;
        res.length > 0 ? res.status(200).send(JSON.stringify(data)) : res.status(204).send();
    });
}

function getPostByID(req, res, postCollection) {
    const postID = ObjectID(req.params.id);
    postCollection.findOne({_id: postID}, (err, data) => {
        if (err) throw err;
        data ? res.status(200).send(JSON.stringify(data)) : res.status(204).send();
    });
}

function getPostsByThreadID(req, res, postCollection) {
    postCollection.find({threadID: req.params.id}).toArray((err, data) => {
        if (err) throw err;
        data.length > 0 ? res.status(200).send(JSON.stringify(data)) : res.status(204).send();
    });
}

function createPost(req, res, postCollection) {
    postCollection.insertOne(req.body, (err, res) => { if(err) throw err; })
    res.status(200).send();
}

function updatePostByID(req, res, postCollection) {
    const postID = ObjectID(req.params.id);
    const filter = {_id: postID};
    const updatePost = {$set: req.body};

    postCollection.updateOne(filter, updatePost, (err, data) => {
        if (err) throw err;
        const amountUpdated = data.result.n;

        amountUpdated > 0 ? res.status(200).send() : res.status(404).send();
    });
}

function deletePostByID(req, res, postCollection) {
    const postID = ObjectID(req.params.id);
    const filter = {_id: postID};

    postCollection.deleteMany(filter, (err, data) => {
        if (err) throw err;
        const amountDeleted = data.result.n;

        amountDeleted > 0 ? res.status(200).send() : res.status(404).send();
    });
}

exports.getAllPosts = getAllPosts;
exports.getPostByID = getPostByID;
exports.getPostsByThreadID = getPostsByThreadID;
exports.createPost = createPost;
exports.updatePostByID = updatePostByID;
exports.deletePostByID = deletePostByID;