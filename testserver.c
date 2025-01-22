#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <stdbool.h>
#pragma comment(lib, "ws2_32.lib")
#define PORT 1234

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int size_client_address = sizeof(client_address);
    char buffer[255];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Error initializing WSA: %d\n", WSAGetLastError());
        return 1;
    }

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Error creating socket: %d\n", WSAGetLastError());
        return 1;
    }

    // Bind server socket
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        printf("Bind failed: %d\n", WSAGetLastError());
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) == SOCKET_ERROR) {
        printf("Listen failed: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Waiting for connection...\n");

    // Accept incoming connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &size_client_address)) == INVALID_SOCKET) {
        printf("Accept failed: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Connection successful!\n");

    // Main chatting interface
    while (1) {
        printf("\nServer: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        printf("Client: ");
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received == SOCKET_ERROR) {
            printf("Recv failed: %d\n", WSAGetLastError());
            break;
        } else if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        }
        buffer[bytes_received] = '\0'; // Null-terminate received data
        printf("%s", buffer);
    }

    // Cleanup
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();

    return 0;
}