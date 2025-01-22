#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define PORT 1234
#define SERVER_IP "127.0.0.1"
bool run;
int main()
{
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_address;
    char buffer[255];
    // initiating wsa for accessing socket function
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSA initialization failed");
        return true;
    }
    // create client socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        printf("Failed creating socket!");
        return true;
    }

    // prepare sockaddr_in structs
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(PORT);

    // preparing for connection
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Connection failed\n");
        return true;
    }
    printf("Connection successfull....\n");

    // main chat section
    while (1)
    {
        printf("\nServer:");
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("%s", buffer);
        printf("\nClient:");
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    closesocket(client_socket);
    WSACleanup();

    return 0;
}