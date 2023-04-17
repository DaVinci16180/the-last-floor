/**********************************************************************************
// Room (Arquivo de Cabe�alho)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _ROOM_H_
#define _ROOM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos espec�ficos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites

// ---------------------------------------------------------------------------------

enum STATE { LIGHT, DARK };

// ---------------------------------------------------------------------------------

class Room : public Object
{
private:
    Image* lightImage;
    Image* darkImage;
    Sprite* sprite = nullptr;

public:
    Room(float posX, float posY, string light, string dark, Geometry* bbox);                   // construtor    
    ~Room();                            // destrutor

    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Room::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif