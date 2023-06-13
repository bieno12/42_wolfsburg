Sure, here is a rephrased version of the project instructions in a README.md file:

# UNIX Signal-Based Communication Program

This project involves creating a communication program in the form of a client and a server using UNIX signals. The server must be started first and print its PID upon launch. The client takes two parameters: the server PID and a string to send.

The client must send the string passed as a parameter to the server using signals. Upon receiving the signal, the server should print the string quickly. The server must be able to receive strings from several clients in a row without needing to restart.

To ensure efficient communication, the server must display the received string quickly. If it takes too long (e.g., 1 second for displaying 100 characters), then it is considered too long. Therefore, it is important to optimize the server's performance to handle incoming signals quickly.

Only two signals can be used in this project: SIGUSR1 and SIGUSR2. The communication between the client and the server must be done only using these signals.

## How to Run the Program

1. Compile server executable using $make server 
2. Compile client executable using $make client
3. Start the server by running the compiled server executable. The server will print its PID upon launch.
4. Start the client by running the compiled client executable with two parameters: the server PID and the string to send.
5. The client will send the string to the server using SIGUSR1 signal. Upon receiving the signal, the server will print the string.
6. Repeat steps 3-4 for additional clients.

## Note

It is important to optimize the server's performance to handle incoming signals quickly. This can be achieved through techniques such as signal handlers, signal blocking, and non-blocking I/O operations.
