const fibonacci = require('bindings')('fibonacci');
const express = require('express');
const app = express();
const PORT = 3000;

app.use('/', express.static('public'));

app.get('/number', (req, res) => {
	res.send(JSON.stringify({number: fibonacci.get()}))
});

app.listen(PORT, () => console.log(`Server listening on port ${PORT}`));


