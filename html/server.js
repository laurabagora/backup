const express = require('express')
const logger = require('morgan')
const path = require('path')
const server = express()
server.use(express.urlencoded({'extended': true}))
server.use(logger('dev'))

// Routes
server.get('/do_a_random', (req, res) => {
  res.send(`Your number is: ${Math.floor(Math.random() * 100) + 1}`)
})

server.post('/8.html', function(req, res) {
   res_string = ('The ${req.body['adj']}  ocean ')
              'is home to  ${req.body['num']} kinds of fish that ' +
              ' ${req.body['verb1']}  to find  ${req.body.noun1]} ' +
              'when the ${req.body['verb2']} night time hits. ' +
              'Several types of  ${req.body['animal']}s circle the ' +
              'sound of  ${req.body['noun2']}  until the day time hits.')
   res.send(res_string)
})


// Setup static page serving for all the pages in "public"
const publicServedFilesPath = path.join(__dirname, 'public')
server.use(express.static(publicServedFilesPath))


// The server uses port 80 by default unless you start it with the extra
// command line argument 'local' like this:
//       node server.js local
let port = 80
if (process.argv[2] === 'local') {
  port = 8080
}

server.listen(port, () => console.log('Ready on localhost!'))
