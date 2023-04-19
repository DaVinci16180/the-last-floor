/**********************************************************************************
// Room (Código Fonte)
//
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Room.h"
#include "Index.h"

// ---------------------------------------------------------------------------------

Room::Room(float posX, float posY, string light, string dark, Geometry* bbox)
{
    type = ROOM;

    lightImage = new Image(light);
    darkImage = new Image(dark);
    sprite = new Sprite(darkImage);
    //sprite = new Sprite(lightImage);

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
    if (lit > 0)
        lit--;
    else
        sprite = new Sprite(darkImage);
}

void Room::OnCollision(Object* obj)
{
    if (obj->Type() == PRESENCE)
    {
        if (lit == 0) {
            lit = 2;
        }

        // acende a luz
        sprite = new Sprite(lightImage);

        if (lit == 2)
            Index::audio->Play(LIGHT_SWITCH);

        lit = 2;
    }

}

// -------------------------------------------------------------------------------
