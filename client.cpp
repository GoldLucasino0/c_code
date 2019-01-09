// Data Structures Final

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include <iostream>
using namespace std;
int main(int argc,char *argv[])
{
int clientSocket;
char *IpAddress;
int Portno;
char response_buffer[100];
char request_message[]="Hi please Accept";
char buf[100];
time_t curtime;
struct tm *loc_time;
struct sockaddr_in serverAddr;
socklen_t addr_size;
if(argc<2)
{
cout<<"\nPlease Pass IP address and Port Number as a Parameter"<<endl;
exit(0);
}
IpAddress=argv[1]; //Assigning first Arguement as a IPaddress.
cout<<"\nThe Ip address is :"<<IpAddress;
Portno=atoi(argv[2]); //Assigning Second Arguement as a Port Number.
cout<<"\nThe Port Number is: "<<Portno<<endl;
//create The Socket Connection
if(!(clientSocket = socket(PF_INET, SOCK_STREAM, 1)))
{
cout<<"\nFailed to create a Scoket:\n"<<endl;
}
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(Portno);
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
addr_size = sizeof serverAddr;
//Connecting with IPaddress
if(connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size)<0)
{
cout<<"Connect Error:\n"<<endl;
exit(0);
}
curtime = time (NULL);
loc_time = localtime (&curtime);
strftime (buf, 140, "Time is %I:%M %p.\n", loc_time);
fputs (buf, stdout);
//Send Request to The Server
send(clientSocket,request_message,sizeof(request_message),0);
cout<<"\nRequest Successfully sent to the server:\n"<<endl;
//Receive Response from the Server
recv(clientSocket, response_buffer, sizeof(response_buffer), 0);
cout<<"\nReceived Response from the Server is "<<response_buffer<<endl;
return 0;
}
