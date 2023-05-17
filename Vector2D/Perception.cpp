/**********************************************************************************
// Perception (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Perception.h"
#include "Index.h"
#include "Level1.h"
#include "Projectile.h"
#include "Wall.h"
#include "Room.h"
#include "Blood.h"
#include "Random.h"
#include "Drop.h"
#include <cmath>
#include "Player.h" 

// ---------------------------------------------------------------------------------

Perception::Perception(Zombie* z)
{
    type = CHASE;
    zombie = z;
    MoveTo(z->X(), z->Y(), Layer::FRONT);
    BBox(new Circle(100));
}

// ---------------------------------------------------------------------------------

Perception::~Perception()
{
}

void Perception::Update() {
    if (zombie->hp > 0)
        MoveTo(zombie->X(), zombie->Y(), Layer::FRONT);
}

void Perception::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER) {
        zombie->Chase();
    }
}

void Perception::Draw() {

}

// ---------------------------------------------------------------------------------