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

#ifndef SINGLETON_HPP_INCLUDED
#define SINGLETON_HPP_INCLUDED

template <class O>
class OSingleton
{
    protected   :
                    static O *pSingleton;

    public      :

                    virtual ~OSingleton()
                    {
                    }
                    inline static O* Get()
                    {
                        if(!pSingleton)
                        pSingleton = new O;
                        return(pSingleton);
                    }
                    static void Del()
                    {
                        if(pSingleton)
                        {
                            delete (pSingleton);
                            pSingleton = NULL;
                        }
                    }
};

template < class O>
O* OSingleton<O>::pSingleton = 0;

#endif // SINGLETON_HPP_INCLUDED
