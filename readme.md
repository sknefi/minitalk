# Minitalk
## Overview

Minitalk is a simple client-server communication system implemented in C using UNIX signals. It allows a client to send a message to the server character-by-character via signal transmissions (SIGUSR1 and SIGUSR2). The server reconstructs and prints the received message.

## How It Works
### Server
Run the server to start listening for messages.
Outputs its PID, which is required by the client to connect.

### Client
Sends a null-terminated string to the server, one bit at a time.
Receives acknowledgment signals to confirm successful transmission.

### Message Reconstruction
The server reconstructs the message from the received signals and prints it.
Handles null-terminated strings, marking the end of the message.

## Features
+ Signal-based Communication: Uses SIGUSR1 and SIGUSR2 for binary message transmission
+ Dynamic Memory Management: Efficiently builds messages character by character
+ Acknowledge System: Server sends acknowledgments to confirm successful receipt of bits
+ Error Handling: Ensures robust behavior for invalid inputs, memory allocation failures, and unexpected signals


## Key Notes
+ Ensure proper delays (usleep) in the client to avoid signal congestion
+ Validate server PID and input format before sending a message