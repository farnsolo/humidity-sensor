#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

class Transfer
{
  public:
     Transfer()
     {
       clientSocket = socket(AF_INET, SOCK_STREAM,0);
       
       serverAddress.sin_family = AF_INET;
       serverAddress.sin_port = htons(8080);
       
       //if (inet_pton(AF_INET,"172.28.91.42", &serverAddress.sin_addr) <= 0)
     }
     
     void send(float humidity, float temp)
     {
       if (connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)) < 0)
       {
         std::cout << "Error connecting to server - connection not made";
       }
 
       const char* dataH = (char*)malloc(20);
       const char* dataT = (char*)malloc(20);
       int convert = snprintf(dataH, sizeof dataH, "%f", humidity);
       int convert = snprintf(dataT,sizeof dataT)

       char message[100];
       strcpy(message, dataH);
       free(dataH);
       strcat(message, dataT);
       free(dataT);

       send(clientSocket,message,strlen(message),0);
       close(clientSocket);
     }
  private:
     int clientSocket;
     sockaddr_in serverAddress;
};
