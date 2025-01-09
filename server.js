const net = require('net');

// Create a server
const server = net.createServer((socket) => {
  console.log('Client connected');

  // Handle incoming data from the client
  socket.on('data', (data) => {
    console.log(`Received from client: ${data}`);
    socket.write(`Echo: ${data}`);
  });

  // Handle client disconnection
  socket.on('end', () => {
    console.log('Client disconnected');
  });

  // Handle errors
  socket.on('error', (err) => {
    console.error(`Socket error: ${err.message}`);
  });
});

// Start the server
const PORT = 8080;
server.listen(PORT, () => {
  console.log(`Server is listening on port ${PORT}`);
});
