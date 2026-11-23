
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8081
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET sockfd;
    char buffer[BUFFER_SIZE];
    char *response = "Hello from UDP Server!";
    struct sockaddr_in servaddr, cliaddr;
    int len = sizeof(cliaddr);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == SOCKET_ERROR) {
        printf("Bind failed.\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("UDP Server running on port %d...\n", PORT);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&cliaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Client says: %s\n", buffer);
    }

    sendto(sockfd, response, (int)strlen(response), 0, (struct sockaddr *)&cliaddr, len);
    printf("Response sent.\n");

    closesocket(sockfd);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless, iterative UDP Server using the Socket API in C
   (Winsock2) and demonstrate datagram reception and transmission without prior
   connection establishment.

2. THEORY:
   - User Datagram Protocol (UDP): A lightweight, connectionless, unreliable
     Transport Layer protocol. It operates without handshakes, sequence numbers,
     acknowledgments, or retransmissions, providing low latency (best-effort delivery).
   - UDP Header Format (Fixed 8 Bytes):
     * Source Port (16 bits)
     * Destination Port (16 bits)
     * Length (16 bits - header + data)
     * Checksum (16 bits - optional/mandatory in IPv6)
   - Connectionless Socket Semantics:
     * Does NOT call listen() or accept().
     * Must call bind() to fix its local port number (8081) so clients can direct
       datagrams to it.
     * Uses recvfrom() to receive independent datagrams; automatically captures
       the sender's IP address and port into a struct sockaddr_in (cliaddr).
     * Uses sendto() to send reply datagrams directly to the captured client address.

3. EXPLANATION / WORKING:
   - Step 1: Initialize Winsock library via WSAStartup(MAKEWORD(2,2), &wsa).
   - Step 2: Create a datagram socket using socket(AF_INET, SOCK_DGRAM, 0).
   - Step 3: Configure server sockaddr_in: sin_family = AF_INET, sin_port =
     htons(8081), sin_addr.s_addr = INADDR_ANY.
   - Step 4: Call bind() to assign port 8081 to the socket descriptor.
   - Step 5: Call recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&cliaddr,
     &len). The call blocks until a UDP datagram arrives from any client.
   - Step 6: Print received datagram payload ("Client says: Hello from UDP Client!").
   - Step 7: Call sendto(sockfd, response, strlen(response), 0, (struct sockaddr*)&cliaddr,
     len) to transmit reply ("Hello from UDP Server!") back to client's address.
   - Step 8: Call closesocket(sockfd) and WSACleanup() to terminate execution.

4. CONCLUSION:
   Successfully implemented and verified a UDP Server in C. Demonstrated datagram
   reception and transmission using recvfrom() and sendto() over port 8081,
   confirming connectionless communication without virtual circuit overhead.
================================================================================
*/
