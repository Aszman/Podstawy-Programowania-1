#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>

int connectToServer();

int main()
{
    if(connectToServer() == -1)
    {
        printf("\nWystąpił błąd podczas połączenia");
        return 0;
    }

    return 0;
}

int connectToServer()
{
    struct sockaddr_in serwer = { };

    serwer.sin_family = AF_INET;
    serwer.sin_port = htons(50000);

    serwer.sin_addr.s_addr = htons( INADDR_ANY );

    struct hostent * he = NULL;

    if ((he = gethostbyname("2.tcp.ngrok.io"))== NULL)
    {
        printf("Niepoprawny adres serwera");
        return -1;
    }

    const char * ipAddress = inet_ntoa( **( struct in_addr ** ) he->h_addr_list );

    //inet_pton(AF_INET, ipAddress, & serwer.sin_addr);

    const int gniazdo = socket( AF_INET, SOCK_STREAM, 0);

    if (gniazdo == -1)
    {
        printf("Nie udało się stworzyć gniazda");
        return -1;
    }


    if (connect( gniazdo, ( struct sockaddr * ) &serwer, sizeof(serwer)) ==-1)
    {
        printf("Nie udało się  połączyć do serwera");
        return -1;
    }

    char bufor[1024]="";

   while (1)
   {
        recv(gniazdo, bufor, sizeof(bufor), 0);
        printf("%s",bufor);

        scanf("%s", bufor);
        send(gniazdo, bufor, sizeof(bufor), 0);

        strcpy(bufor, "");
    }

    shutdown(gniazdo, SHUT_RDWR);
    return 0;
}
