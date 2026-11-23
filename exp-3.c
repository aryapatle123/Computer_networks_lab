
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
    SOCKET sock = INVALID_SOCKET;
    struct sockaddr_in serv_addr;
    char *msg = "Hello from TCP Client!";
    char buffer[BUFFER_SIZE] = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed.\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    send(sock, msg, (int)strlen(msg), 0);
    printf("Message sent to server.\n");

    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    closesocket(sock);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connection-oriented TCP Client using the BSD Socket API in C
   (Winsock2) and demonstrate active connection establishment and message exchange
   with a remote TCP Server.

2. THEORY:
   - Client-Server Architecture (TCP): The client acts as the active entity that
     initiates the connection. Unlike the server, the client does not call bind()
     or listen(); the operating system dynamically assigns an ephemeral port
     (typically 49152-65535) during connect().
   - Active Connection Establishment:
     The client initiates the TCP 3-way handshake by transmitting a SYN segment
     containing an initial sequence number to the server's listening IP and port.
   - Socket API Functions (Client):
     * socket(): Creates an endpoint for network I/O (AF_INET, SOCK_STREAM, 0).
     * inet_addr(): Converts standard IPv4 dotted-decimal string ("127.0.0.1")
       into an unsigned 32-bit integer in network byte order (big-endian).
     * htons(): Converts 16-bit port number from host byte order to network byte order.
     * connect(): Performs active connection setup to the specified server sockaddr_in.
       Blocks until the 3-way handshake succeeds or times out.
     * send(): Streams data bytes into the kernel TCP send buffer.
     * recv(): Reads incoming bytes from the TCP receive buffer.
     * closesocket() & WSACleanup(): Initiates 4-way FIN termination sequence and
       unloads Winsock DLL.

3. EXPLANATION / WORKING:
   - Step 1: WSAStartup(MAKEWORD(2,2), &wsa) initializes the Winsock environment.
   - Step 2: socket(AF_INET, SOCK_STREAM, 0) creates client streaming socket descriptor.
   - Step 3: Populate struct sockaddr_in serv_addr with server IP ("127.0.0.1" via
     inet_addr) and server port (8080 via htons).
   - Step 4: Call connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) to
     initiate 3-way handshake with TCP Server running on port 8080.
   - Step 5: Upon successful connection, send(sock, msg, strlen(msg), 0) transmits
     payload "Hello from TCP Client!".
   - Step 6: recv(sock, buffer, BUFFER_SIZE, 0) synchronously waits for server
     reply and outputs "Server response: Hello from TCP Server!".
   - Step 7: closesocket(sock) sends FIN segment to close socket; WSACleanup() cleans
     up socket resources.

4. CONCLUSION:
   Successfully implemented and verified a TCP Client in C. Demonstrated active
   TCP handshake connection establishment to 127.0.0.1:8080, verified reliable
   data transmission and response reception, and achieved graceful connection teardown.
================================================================================
*/
