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

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "sprite.hpp"
#include "server.hpp"
#include "client.hpp"
#include "menu.hpp"
#include "sound.hpp"

class CPlayer
{
    public  :
                CPlayer();              //Konstruktor
                ~CPlayer();             //Destruktor
                void Init();            //Initialisiert die Spieler
                void Render();          //Rendert die Spieler und den Ball
                void Control();         //Steuerung der Spieler
                bool Collision(SDL_Rect a , SDL_Rect b);    //Kollisions Erkennung
                void MoveBall();        //Bewegt den Ball
                void Reset();           //Resetet das Spiel
                void Points();          //Berechnet Punkte der Spieler und gibt Sie aus
                void AI();              //Computer Gegner
                short int i_Player;     //Anzahl der Spieler
                int i_Ball_Speed_X;     //X Geschwindigkeit des Balles
                int i_Ball_Speed_Y;     //Y Geschwindigkeit des Balles
                CServer server;
                CClient client;
    private :
                CSprite *pPlayer;       //Spieler Bild
                CSprite *pComputer;     //Spieler Bild
                CSprite *pBall;         //Ball Bild
                CSprite *pBack;         //Hintergrundbild
                CSound *pSoundPlayer;   //Sound f�r den Player
                CSound *pSoundCpu;      //Sound f�r den Computer
                SDL_Surface *pScreen;   //Bildschirm auf den Gerendert wird
                SDL_Rect Player;        //Rect des Players
                SDL_Rect Computer;      //Rect des Players
                SDL_Rect Ball;          //Rect des Balles
                SDL_Rect m_Rect;        //Ein Rect
                SDL_Event g_Event;      //SDL Event
                short int iPlayerPoint; //Spieler Punkte
                short int iCpuPoint;    //Spieler Punkte
                int ipaddle_center;     //Spieler Schl�ger mitte
                int iball_center;       //Ball mitte
                int ipaddle_location;   //Wo trifft der Ball auf den Schl�ger
                int ipaddle_center_cpu; //CPU Schl�ger mitte
                int ipaddle_location_cpu;//Wo trifft der Ball auf den CPU Schl�ger
                bool b_decision;        //Entscheidung "zur�ck an start oder nicht"
                bool release;           //Freigabe des Balles
                int ipaddle_rand;        //welche Toleranz hat das Paddle im Bezug auf die mitte des Balles
                int iball_y;             //Ab wann soll die KI Reagieren
};
#endif // PLAYER_HPP_INCLUDED
