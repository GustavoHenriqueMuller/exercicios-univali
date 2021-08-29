const { ObjectID } = require('bson');

function getAllThreads(req, res, threadCollection) {
    threadCollection.find().toArray((err, data) => {
        if (err) throw err;
        data.length > 0 ? res.status(200).send(JSON.stringify(data)) : res.status(204).send();
    });
}

function getThreadByID(req, res, threadCollection) {
    const threadID = ObjectID(req.params.id);
    threadCollection.findOne({_id: threadID}, (err, data) => {
        if (err) throw err;
        data ? res.status(200).send(JSON.stringify(data)) : res.status(204).send();
    });
}

function createThread(req, res, threadCollection) {
    threadCollection.insertOne(req.body, (err, res) => { if(err) throw err; })
    res.status(200).send();
}

function updateThreadByID(req, res, threadCollection) {
    const threadID = ObjectID(req.params.id);
    const updateThread = {$set: req.body};

    threadCollection.updateOne({_id: threadID}, updateThread, (err, data) => {
        if (err) throw err;
        const amountUpdated = data.result.n;

        amountUpdated > 0 ? res.status(200).send() : res.status(404).send();
    });
}

function deleteThreadByID(req, res, threadCollection, postCollection) {
    postCollection.deleteMany({threadID: req.params.id}, (err, data) => {
        if (err) throw err;
    });

    const threadID = ObjectID(req.params.id);
    threadCollection.deleteMany({_id: threadID}, (err, data) => {
        if (err) throw err;
        const amountDeleted = data.result.n;

        amountDeleted > 0 ? res.status(200).send() : res.status(404).send();
    });
}

exports.getAllThreads = getAllThreads;
exports.getThreadByID = getThreadByID;
exports.createThread = createThread;
exports.updateThreadByID = updateThreadByID;
exports.deleteThreadByID = deleteThreadByID;