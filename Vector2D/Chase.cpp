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

#include "Chase.h"
#include "Index.h"
#include "Level1.h"
#include "Zombie.h"
#include "Room.h"

// ------------------------------------------------------------------------------

Chase::Chase(Zombie* z)
{
    type = CHASE;
    zombie = z;
        MoveTo(zombie->X(), zombie->Y());

    BBox(new Circle(7 * (1 / 0.07f)));
}

// ------------------------------------------------------------------------------

Chase::~Chase()
{
}

void Chase::OnCollision(Object* obj) {
    if (obj->Type() == PLAYER) {
        zombie->Chase();
    }
    
}

// -------------------------------------------------------------------------------

void Chase::Update()
{
    
       MoveTo(zombie->X(), zombie->Y());
}

// -------------------------------------------------------------------------------

void Chase::Draw()
{
}

// -------------------------------------------------------------------------------
