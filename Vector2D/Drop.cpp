/**********************************************************************************
// Drop (C�digo Fonte)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Drop.h"
#include "Index.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

Drop::Drop(float x, float y, int t, int a)
{
    type = DROP;

    if (t == PISTOL) {
        sprite = new Sprite("Resources/Bullet.png");
    }
    else {
        sprite = new Sprite("Resources/Cap.png");
    }

    amount = a;
    type = t;

    ScaleTo(0.4f);

    // move para posi��o
    MoveTo(x, y);

    BBox(new Circle(20));
}

// ------------------------------------------------------------------------------

Drop::~Drop()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Drop::Update()
{
    
}

void Drop::OnCollision(Object* obj) {
    if (obj->Type() == PLAYER) {
        Player* player = dynamic_cast<Player*>(obj);

        if (type == PISTOL) {
            player->AddPistolAmmo(amount);
        }
        else {
            player->AddShotgunAmmo(amount);
        }

        Level1::scene->Delete(this, STATIC);
    }
}

// -------------------------------------------------------------------------------

void Drop::Draw()
{
    sprite->Draw(x, y, Layer::FRONT, scale, rotation, Color{1,1,1,1});
}

// -------------------------------------------------------------------------------
