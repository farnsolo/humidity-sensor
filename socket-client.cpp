#include <cstring>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
    std::cout << "Running now";
    int clientSocket = socket(AF_INET, SOCK_STREAM,0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    if(inet_pton(AF_INET, "172.28.91.42", &serverAddress.sin_addr) <= 0){
        std::cout << "\nError in address space\n";
        return -1;
    }


    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        std::cout << "\nFAIL connection\n";
        return -1;
    }

    // humidity and temp data first

    const char* humidity = "23.8";
    const char* temp = "12.5";

    char message[100];
    strcpy(message, humidity);
    strcat(message,temp);
    

    send(clientSocket,message,strlen(message),0);

    close(clientSocket);
    std::cout << "\nRunning now";
    return 0;
}
