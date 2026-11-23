
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
    char *msg = "Hello from UDP Client!";
    struct sockaddr_in servaddr;
    int len = sizeof(servaddr);

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
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockfd, msg, (int)strlen(msg), 0, (struct sockaddr *)&servaddr, len);
    printf("Datagram sent to server.\n");

    int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&servaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Server response: %s\n", buffer);
    }

    closesocket(sockfd);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless UDP Client using the Socket API in C (Winsock2)
   and demonstrate transmission and reception of independent datagrams to/from
   a UDP server.

2. THEORY:
   - UDP Client Characteristics:
     * Operates without establishing a virtual circuit (no 3-way handshake).
     * Explicit call to bind() is omitted; OS binds an ephemeral source port on
       first transmission.
     * Each datagram is an independent unit of transmission containing complete
       source and destination addressing information.
     * Faster throughput and minimal latency compared to TCP, suitable for
       real-time streaming, DNS queries, and VoIP.
   - Socket API Primitives:
     * socket(AF_INET, SOCK_DGRAM, 0): Creates a UDP datagram socket descriptor.
     * sendto(): Sends a datagram directly to destination sockaddr_in (IP & port).
     * recvfrom(): Waits for incoming datagram and records sender information.
     * closesocket() & WSACleanup(): Closes socket and unregisters Winsock library.

3. EXPLANATION / WORKING:
   - Step 1: Initialize Winsock subsystem via WSAStartup(MAKEWORD(2,2), &wsa).
   - Step 2: Create datagram socket descriptor using socket(AF_INET, SOCK_DGRAM, 0).
   - Step 3: Populate destination sockaddr_in servaddr with server IP ("127.0.0.1"
     via inet_addr) and destination port (8081 via htons).
   - Step 4: Call sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*)&servaddr, len)
     to transmit datagram ("Hello from UDP Client!") to UDP Server on 127.0.0.1:8081.
   - Step 5: Call recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr*)&servaddr,
     &len) to block until server sends acknowledgment datagram.
   - Step 6: Null-terminate buffer and display server reply ("Hello from UDP Server!").
   - Step 7: Execute closesocket(sockfd) and WSACleanup() to release socket resources.

4. CONCLUSION:
   Successfully implemented and verified a UDP Client in C. Validated connectionless
   datagram transmission and reply reception using sendto() and recvfrom(),
   confirming lightweight packet communication without connection setup latency.
================================================================================
*/
