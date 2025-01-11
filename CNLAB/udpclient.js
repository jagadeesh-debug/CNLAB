const dgram = require('dgram');

// Create a UDP socket
const client = dgram.createSocket('udp4');

// Message to send to the server
const message = Buffer.from('Hello, Server!');

// Send the message
const PORT = 8080;
const HOST = 'localhost';

client.send(message, PORT, HOST, (err) => {
  if (err) {
    console.error('Error sending message:', err.message);
    client.close();
  } else {
    console.log('Message sent to server');
  }
});

// Listen for the server's response
client.on('message', (msg) => {
  console.log(`Received from server: ${msg}`);
  client.close();
});

// Handle client errors
client.on('error', (err) => {
  console.error(`Client error: ${err.message}`);
  client.close();
});
