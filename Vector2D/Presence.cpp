/**********************************************************************************
// Presence (C�digo Fonte)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Presence.h"
#include "Index.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

Presence::Presence()
{
    type = PRESENCE;

    if (Index::player != nullptr)
        MoveTo(Index::player->X(), Index::player->Y());

    BBox(new Point());
}

// ------------------------------------------------------------------------------

Presence::~Presence()
{
}

void Presence::OnCollision(Object* obj) {

}

// -------------------------------------------------------------------------------

void Presence::Update()
{
    if (Index::player != nullptr)
        MoveTo(Index::player->X(), Index::player->Y());
}

// -------------------------------------------------------------------------------

void Presence::Draw()
{
}

// -------------------------------------------------------------------------------
