/**********************************************************************************
// Room (C�digo Fonte)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#include "Room.h"

// ---------------------------------------------------------------------------------

Room::Room(float posX, float posY, string light, string dark, Geometry* bbox)
{
    lightImage = new Image(light);
    darkImage = new Image(dark);
    sprite = new Sprite(darkImage);

    BBox(bbox);
    MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Room::~Room()
{
    delete lightImage;
    delete darkImage;
    delete sprite;
}

// -------------------------------------------------------------------------------

void Room::Update()
{

}

// -------------------------------------------------------------------------------
