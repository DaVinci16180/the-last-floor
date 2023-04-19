/**********************************************************************************
// Presence (Código Fonte)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
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
