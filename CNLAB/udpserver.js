const dgram = require('dgram')
//create udp socket
const server = dgram.createSocket('udp4')
//handling incoming messages
server.on('message',(msg,rip)=>{
    console.log(`recived messgae ${msg} from ${rip.address}:${rip.port}`);

    const response = `${msg}`;
    server.send(response,rip.port,rip.address,(err)=>{
        if(err){
            console.error("error sending response",err.message);
        }
        else{
            console.log(`repsonse sent to ${rip.address}`);
        }
    });
});
server.on('error', (err) => {
    console.error(`Server error: ${err.message}`);
    server.close();
  });
  
  // Start the server
  const PORT = 8080;
  server.bind(PORT, () => {
    console.log(`UDP server is listening on port ${PORT}`);
  });