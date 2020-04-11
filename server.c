#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
    char server_message[512] = " \nYou have reached the server.";

    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(4444);
    server_address.sin_addr.s_addr = INADDR_ANY;

    printf("Starting the server.......\nWaiting for client to connect to the server. \n");

    // Bind the socket to the specified IP and Port
    bind(server_socket, (struct sockaddr*) & server_address, sizeof(server_address));

    listen(server_socket, 10);

    int client_socket = accept(server_socket, NULL, NULL);

    // Send the message
    send(client_socket, server_message, sizeof(server_message), 0);

    // Close the socket
    printf("The client has connected to the server. \nThe Server closed the connection.\n");
    close(server_socket);
    
}