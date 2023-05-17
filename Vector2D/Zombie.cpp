/**********************************************************************************
// Zombie (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Zombie.h"
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

Zombie::Zombie(int x, int y)
{
    type = ZOMBIE;
    MoveTo(x, y, Layer::FRONT);
    RotateTo(90);

    // direção inicial do player
    direction.RotateTo(90.0f);
    direction.ScaleTo(1.0f);

    tileset = new TileSet("Resources/Feet.png", 480, 480, 6, 12);
    feet = new Animation(tileset, 0.1f, true);

    sprite = new Sprite("Resources/Zombie.png");

    // cria bounding box
    BBox(new Circle(16 * (1 / 0.07f)));
    BBox(new Circle(20 * (1 / 0.07f)));
    ScaleTo(0.07f);

    hp = 4;
}

// ---------------------------------------------------------------------------------

Zombie::~Zombie()
{
    delete feet;
    delete tileset;
    sprite;
}


void Zombie::Rotate(float angle)
{
    Object::Rotate(angle);
    direction.Rotate(angle);
}

void Zombie::RotateTo(float angle)
{
    Object::RotateTo(-angle + 90);
    direction.RotateTo(angle);
}

// ---------------------------------------------------------------------------------

void Zombie::OnCollision(Object* obj)
{
    if (obj->Type() == WALL)
    {
        Wall* wall = dynamic_cast<Wall*>(obj);

        int top = wall->Y();
        int bot = wall->Y() + wall->height;
        int left = wall->X();
        int right = wall->X() + wall->width;

        if (x <= left) {
            MoveTo(wall->X() - 14, Y());
        }

        else if (x >= right) {
            MoveTo(wall->X() + wall->width + 14, Y());
        }

        else if (y >= bot) {
            MoveTo(X(), wall->Y() + wall->height + 14);
        }

        else if (y <= top) {
            MoveTo(X(), wall->Y() - 14);
        }
    }

    if (obj->Type() == ROOM) {
        Room* room = dynamic_cast<Room*>(obj);

        if (!room->Lit()) {
            ScaleTo(0);
        }
        else {
            ScaleTo(0.07f);
        }
    }

    if (obj->Type() == PROJECTILE) {
        Projectile* proj = dynamic_cast<Projectile*>(obj);
        hp--;

        float angle = proj->speed.Angle();

        if (hp) {
            Level1::scene->Add(new Blood(x, y, angle, 45, Color{ 1,0,0,1 }), STATIC);
        }
        else {
            Level1::scene->Add(new Blood(x, y, angle, 360, Color{ 1,0,0,1 }), STATIC);
            Level1::scene->Add(new Blood(x, y, angle, 360, Color{ (60.f / 255.f), (163.f / 255.f), (112.f / 255.f), 1 }), STATIC);
            Level1::scene->Add(new Blood(x, y, angle, 360, Color{ (60.f / 255.f), (163.f / 255.f), (112.f / 255.f), 1 }), STATIC);
        }
    }
}

// ---------------------------------------------------------------------------------

void Zombie::Update()
{
    if (push.Magnitude() != 0) {
        push.Scale(0.95);
        Translate(push.XComponent() * 50.0f * gameTime, -push.YComponent() * 50.0f * gameTime);
    }
    if (push.Magnitude() <= 0.2) {
        push.ScaleTo(0);
    }

    float delta = 400 * gameTime;

    if (hp <= 0) {
        Level1::scene->Delete(this, MOVING);

        RandI rand = RandI(1, 8);
        int dice = rand.Rand();

        if (dice < 5) {
            int amount = dice;
            Level1::scene->Add(new Drop(x, y, PISTOL, amount), STATIC);
        }
        else if (dice < 8) {
            int amount = dice - 5;
            Level1::scene->Add(new Drop(x, y, SHOTGUN, amount), STATIC);
        }
    }
   
       
    
    feet->NextFrame();
}
void Zombie::Chase() {
    if (!Index::challenge && hp > 0) {
        direction.RotateTo(Line::Angle(Point(x, y), Point(Index::player->X(), Index::player->Y())));
        RotateTo(Line::Angle(Point(x, y), Point(Index::player->X(), Index::player->Y())));

        // movimenta objeto pelo seu vetor velocidade
        Translate(direction.XComponent() * 50.0f * gameTime, -direction.YComponent() * 50.0f * gameTime);
    }
}

void Zombie::Push(float pX, float pY) {
    push = Vector(Line::Angle(Point(x, y), Point(pX, pY)), 10.f);
    push.Rotate(180);

    Translate(push.XComponent() * 50.0f * gameTime, -push.YComponent() * 50.0f * gameTime);
}

// ---------------------------------------------------------------------------------