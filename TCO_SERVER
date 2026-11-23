

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "Hello from TCP Server!";

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Bind failed.\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    listen(server_fd, 3);
    printf("TCP Server listening on port %d...\n", PORT);

    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if (new_socket == INVALID_SOCKET) {
        printf("Accept failed.\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    recv(new_socket, buffer, BUFFER_SIZE, 0);
    printf("Client says: %s\n", buffer);

    send(new_socket, response, (int)strlen(response), 0);
    printf("Response sent to client.\n");

    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connection-oriented, iterative TCP Server using the BSD Socket
   API in C (Winsock2) and demonstrate reliable full-duplex communication with a
   client application.

2. THEORY:
   - Transmission Control Protocol (TCP): A reliable, connection-oriented,
     byte-stream Transport Layer protocol. It guarantees in-order, error-free
     delivery using sequence numbers, positive acknowledgments (ACK), checksums,
     and sliding window flow control.
   - Three-Way Handshake Connection Establishment:
       Client ---[ SYN (Seq = x) ]--------------------------> Server
       Client <---[ SYN (Seq = y), ACK (Ack = x + 1) ]-------- Server
       Client ---[ ACK (Ack = y + 1) ]------------------------> Server
   - Socket API Lifecycle (Iterative Server):
     * socket(): Allocates an endpoint descriptor (AF_INET, SOCK_STREAM, IPPROTO_TCP).
     * bind(): Associates the server socket with a well-known local IP (INADDR_ANY)
       and port (8080) stored in a sockaddr_in structure.
     * listen(): Places socket into a passive listening state with an incoming
       connection queue backlog (backlog = 3).
     * accept(): Blocks program execution until an incoming connection request
       arrives; extracts the first connection from queue and returns a brand-new
       dedicated connected socket descriptor (new_socket) for client communication.
     * recv() / send(): Performs full-duplex data transfer over the established stream.
     * closesocket() & WSACleanup(): Initiates 4-way FIN/ACK teardown and frees
       Winsock DLL resources.

3. EXPLANATION / WORKING:
   - Step 1: Initialize Winsock subsystem via WSAStartup(MAKEWORD(2, 2), &wsa).
   - Step 2: Create endpoint via socket(AF_INET, SOCK_STREAM, 0). Check for
     INVALID_SOCKET error.
   - Step 3: Populate struct sockaddr_in: sin_family = AF_INET, sin_port =
     htons(8080) (Host to Network Short byte-order conversion), sin_addr.s_addr =
     INADDR_ANY (binds to all host network interfaces).
   - Step 4: Call bind() to bind socket to port 8080; terminate if SOCKET_ERROR.
   - Step 5: Execute listen(server_fd, 3) to enable passive listening.
   - Step 6: Block on accept() waiting for incoming client handshake. Once received,
     it returns new_socket.
   - Step 7: Call recv(new_socket, buffer, BUFFER_SIZE, 0) to receive client message
     and print to stdout ("Client says: Hello from TCP Client!").
   - Step 8: Call send(new_socket, response, strlen(response), 0) to return
     acknowledgment payload ("Hello from TCP Server!").
   - Step 9: Call closesocket() for new_socket and server_fd; call WSACleanup().

4. CONCLUSION:
   Successfully implemented and verified a connection-oriented TCP Server in C.
   Demonstrated socket creation, binding, passive listening, 3-way handshake
   acceptance, reliable bidirectional message exchange, and graceful socket closure.
================================================================================
*/
