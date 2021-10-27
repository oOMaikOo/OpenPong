/**
OpenPong ist ein Pong Clone mit Multiplayerfunktion

Copyright (C) 2009 MacGyver
Dieses Programm ist freie Software. Sie k�nnen es unter den Bedingungen der GNU General
Public License, wie von der Free Software Foundation ver�ffentlicht, weitergeben und/oder
modifizieren, entweder gem�� Version 3 der Lizenz oder (nach Ihrer Option) jeder sp�teren
Version.
Die Ver�ffentlichung dieses Programms erfolgt in der Hoffnung, da� es Ihnen von Nutzen
sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite Garantie der MARKTREIFE
oder der VERWENDBARKEIT F�R EINEN BESTIMMTEN ZWECK. Details finden Sie in der GNU General
Public License.
Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem Programm
erhalten haben. Falls nicht, siehe <http://www.gnu.org/licenses/>.
**/

#include "client.hpp"

CClient::CClient()
{

}
CClient::~CClient()
{
    SDLNet_TCP_Close(server);
    SDLNet_Quit();
}

void CClient::OpenClient(char *s)
{
//    char *s;
//    cout << "Bitte ip des Servers Eingeben : "<< endl;
//    cin >> s;
    cout << "IP : " << s << endl;
    if (SDLNet_ResolveHost (&addr,s, 6699) < 0)
    {
        printf ("ERR ResolveHost: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }

    client = SDLNet_TCP_Open (&addr);

    if (client == NULL)
    {
        printf ("ERR TCP_Open: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }
}

void CClient::Recive(Sint16 *a, bool *b)
{

    /*result = SDLNet_TCP_Recv(client , &recive, sizeof(int));

    Sint16 b = recive;

    return b;*/

    int recive[2];

    result = SDLNet_TCP_Recv(client , &recive, sizeof(recive));

    *a = recive[0];

    *b = recive[1];

}

void CClient::Send(Sint16 a, bool b)
{
    /*int result;

    int b = a;

    int  len=sizeof(b);

    result = SDLNet_TCP_Send (client, &b, sizeof(int));

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }*/

    int result;
    int x[2];
    x[0] = a;
    x[1] = b;

    int  len=sizeof(x);

    result = SDLNet_TCP_Send (client, &x, sizeof(x));

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }
}

void CClient::ReciveSettings(int *a)
{
    int recive[1];

    int  len=sizeof(recive);

    result = SDLNet_TCP_Recv(client , &recive, sizeof(recive));

    *a = recive[0];

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }

}
