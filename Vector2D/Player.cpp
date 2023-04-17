/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"
#include "Index.h"
#include "Level1.h"
#include "Projectile.h"
#include <cmath>

// ---------------------------------------------------------------------------------

Player::Player()
{
    type = PLAYER;
    gunTimer.Start();

    // inicializa controle
    gamepad = new Controller();
    gamepadOn = gamepad->Initialize();

    // cria sprites
    equipmentSprite = new Sprite(new Image("Resources/Pistol.png"));
    bulletSprite = new Sprite(new Image("Resources/Bullet.png"));
    hpSprite = new Sprite(new Image("Resources/Heart.png"));

    projectile = new Image("Resources/Projectile.png");

    // posição, escala e rotação inicial do player
    MoveTo(window->CenterX(), window->CenterY(), Layer::FRONT);
    RotateTo(90);

    // direção inicial do player
    direction.RotateTo(90.0f);
    direction.ScaleTo(1.0f);

    tileset = new TileSet("Resources/Player.png", 30, 30, 6, 12);
    anim = new Animation(tileset, 0.07f, true);

    // sequências de animação do player
    uint walking[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    uint still[1] = { 0 };

    anim->Add(STILL, still, 1);
    anim->Add(WALKING, walking, 12);

    // cria bounding box
    //BBox(new Circle(12));
    BBox(new Point());

    // inicializa estado do player
    equipment = PISTOL;
    level = 0;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;
}


void Player::Rotate(float angle)
{
    Object::Rotate(angle);
    direction.Rotate(angle);
}

void Player::RotateTo(float angle)
{
    Object::RotateTo(-angle + 90);
    direction.RotateTo(angle);
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), window->CenterY(), Layer::UPPER);
    RotateTo(90);
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
    //if (obj->Type() == FINISH)
    {
        // chegou ao final do nível
    //    level++;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    float delta = 250 * gameTime;
    // Movimentação do personagem
    if (gamepadOn)
    {
        // lê estado atualizado do controle
        gamepad->UpdateState();

        // movimenta com o analógico esquerdo
        Translate(gamepad->Axis(AxisX) * 0.25f * gameTime, gamepad->Axis(AxisY) * 0.25f * gameTime);

        if (gamepad->Axis(AxisX) != 0 || gamepad->Axis(AxisY) != 0) {
            int xx = gamepad->Axis(AxisX);
            int yy = gamepad->Axis(AxisY);

            double radianos = std::atan2(-yy, xx);
            double graus = radianos * 180 / 3.14159;
            RotateTo(graus);

            anim->Select(WALKING);
        }
        else {
            anim->Select(STILL);
        }

        if (gamepad->Axis(AxisRX) != 0 || gamepad->Axis(AxisRY) != 0) {
            int xx = gamepad->Axis(AxisRX);
            int yy = gamepad->Axis(AxisRY);
            
            double radianos = std::atan2(-yy, xx);
            double graus = radianos * 180 / 3.14159;
            RotateTo(graus);
        }

        // reinicia posição do player
        if (gamepad->ButtonPress(START))
        {
            Reset();
        }

        // movimento com o D-pad
        switch (gamepad->Dpad(DPAD))
        {
        case 0:
            Translate(0.0f, -delta);    // para cima
            break;
        case 4500:
            Translate(delta, -delta);   // para cima e direita
            break;
        case 9000:
            Translate(delta, 0.0f);     // para direita
            break;
        case 13500:
            Translate(delta, delta);    // para baixo e direita
            break;
        case 18000:
            Translate(0.0f, delta);     // para baixo
            break;
        case 22500:
            Translate(-delta, delta);   // para baixo e esquerda
            break;
        case 27000:
            Translate(-delta, 0.0f);   // para esquerda
            break;
        case 31500:
            Translate(-delta, -delta);  // para cima e esquerda
            break;
        }

        if (gamepad->ButtonPress(Y_BUTTON))
        {
            if (equipment == SHOTGUN) {
                equipment = PISTOL;
                equipmentSprite = new Sprite(new Image("Resources/Pistol.png"));
                bulletSprite = new Sprite(new Image("Resources/Bullet.png"));
            }
            else if (equipment == PISTOL) {
                equipment = SHOTGUN;
                equipmentSprite = new Sprite(new Image("Resources/Shotgun.png"));
                bulletSprite = new Sprite(new Image("Resources/Cap.png"));
            }
        }

        // dispara
        if (gamepad->ButtonPress(5))
        {
            switch (equipment)
            {
            case PISTOL:
                if (gunTimer.Elapsed(0.1)) {
                    gunTimer.Reset();
                    Index::audio->Play(GUN_SOUND);
                    Level1::scene->Add(new Projectile(this, projectile, 0), MOVING);
                }
                break;
            case SHOTGUN:
                if (gunTimer.Elapsed(1)) {
                    gunTimer.Reset();
                    Index::audio->Play(SHOTGUN_SOUND);
                    Level1::scene->Add(new Projectile(this, projectile, 4), MOVING);
                    Level1::scene->Add(new Projectile(this, projectile, 10), MOVING);
                    Level1::scene->Add(new Projectile(this, projectile, -4), MOVING);
                    Level1::scene->Add(new Projectile(this, projectile, -10), MOVING);
                }
                break;
            default:
                break;
            }
            
        }

        if (gamepad->ButtonPress(Y_BUTTON)) {

        }
    }

    int xx = 0;
    int yy = 0;

    // rotaciona nave
    if (window->KeyDown(VK_RIGHT))
        xx++;
    if (window->KeyDown(VK_LEFT))
        xx--;
    if (window->KeyDown(VK_UP))
        yy--;
    if (window->KeyDown(VK_DOWN))
        yy++;

    if (!xx && !yy)
        anim->Select(STILL);
    else
        anim->Select(WALKING);


    Translate(xx * 100 * gameTime, yy * 100 * gameTime);

    double radianos = std::atan2(-yy, xx);
    double graus = radianos * 180 / 3.14159;
    RotateTo(graus);

    // atualiza animação
    anim->Select(equipment);
    anim->NextFrame();
}


// ---------------------------------------------------------------------------------