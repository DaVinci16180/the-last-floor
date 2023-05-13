/**********************************************************************************
// Projectile (Código Fonte)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
//
**********************************************************************************/

#include "Projectile.h"
#include "Index.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

Projectile::Projectile(Player* player, Image* img, float angle)
{
    type = PROJECTILE;

    // inicializa sprite
    sprite = new Sprite(img);

    // inicializa vetor velocidade
    speed.RotateTo(player->Angle() + angle);
    speed.ScaleTo(1200);

    // usa mesma rotação do player
    RotateTo(player->Rotation() + angle);
    ScaleTo(0.4f);

    // move para posição
    MoveTo(player->X(), player->Y());

    //trail = new Trail(player->X(), player->Y(), player->Angle() + angle);
    //Level1::scene->Add(trail, STATIC);

    BBox(new Circle(10));
}

// ------------------------------------------------------------------------------

Projectile::~Projectile()
{
    delete sprite;
    delete trail;
}

// -------------------------------------------------------------------------------

void Projectile::Update()
{
    // desloca míssil pelas componentes do vetor speed
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);

    // se o míssil sair da janela
    if (x > window->Width() || x < 0 || y > window->Height() || y < 0)
    {
        //trail->TurnOff();
        Level1::scene->Delete();
    }
}

void Projectile::OnCollision(Object* obj) {
    if (obj->Type() == WALL) {
        MoveTo(-10, -10);
        //trail->TurnOff();
    }
}

// -------------------------------------------------------------------------------

void Projectile::Draw()
{
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
