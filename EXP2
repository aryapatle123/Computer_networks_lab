
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server, client;
    struct sockaddr_in addr;
    char buffer[1024], msg[1024];

    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server, (struct sockaddr *)&addr, sizeof(addr));
    listen(server, 3);

    printf("Server listening...\n");

    while (1) {
        client = accept(server, NULL, NULL);
        printf("Client connected!\n");

        while (1) {
            memset(buffer, 0, sizeof(buffer));

            if (recv(client, buffer, sizeof(buffer)-1, 0) <= 0)
                break;

            printf("Client: %s\n", buffer);

            printf("Enter reply: ");
            fgets(msg, sizeof(msg), stdin);

            send(client, msg, strlen(msg), 0);
        }

        close(client);
        printf("Client disconnected!\n");
    }

    close(server);
    return 0;
}


//nc ip 8080
