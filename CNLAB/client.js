const net = require('net')

//create a client socket
const client  = net.createConnection({port:8080},()=>{
    console.log("server created");
    client.write("hello")
});

//handle data
client.on('data',(data)=>{
    console.log(`server received ${data}`)
    client.end()
})

//closing server
client.on('end',()=>{
    console.log("server disconnected")
})

client.on('error',(err)=>{
    console.error(`error is ${err.message}`)
})