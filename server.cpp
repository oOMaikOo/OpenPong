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

#include "server.hpp"

CServer::CServer()
{
    server = NULL;
    client = NULL;
}
CServer::~CServer()
{
    SAFE_DELETE (remoteIP);
    SDLNet_TCP_Close(server);
    SDLNet_Quit();
}


void CServer::OpenServer()
{

    if (SDLNet_ResolveHost (&addr, NULL, 6699) < 0)
    {
        printf ("ERR ResolveHost: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }

    server = SDLNet_TCP_Open (&addr);

    if (server == NULL)
    {
        printf ("ERR TCP_Open: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }

    client = SDLNet_TCP_Accept (server);
    cout << "Server wurde Gestartet !" << endl;

    while (client == NULL)
    {
        SDL_Delay (1000);
        client = SDLNet_TCP_Accept (server);
    }
    cout << "Client hat verbunden !" << endl;

}

void CServer::Recive(Sint16 *a, bool *b)
{
    /*result = SDLNet_TCP_Recv(client , &recive, sizeof(int));

    Sint16 b = recive;

    return b;*/


    int recive[2];

    result = SDLNet_TCP_Recv(client , &recive, sizeof(recive));

    *a = recive[0];

    *b = recive[1];
}

void CServer::Send(Sint16 a, bool b)
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

void CServer::SendSettings(int a)
{
    int result;
    int x[1];
    x[0] = a;

    int  len=sizeof(x);

    result = SDLNet_TCP_Send (client, &x, sizeof(x));

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }
}
