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
#include "Wall.h"
#include "Engine.h"
#include "Challenge.h"
#include <cmath>

// ---------------------------------------------------------------------------------

Player::Player()
{
    font = new Font("Resources/FFFForward.png");
    font->Spacing(70);

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

    tileset = new TileSet("Resources/Feet.png", 480, 480, 6, 12);
    anim = new Animation(tileset, 0.07f, true);

    // sequências de animação do player
    uint walking[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    uint still[1] = { 0 };

    anim->Add(STILL, still, 1);
    anim->Add(WALKING, walking, 12);

    sprite = new Sprite("Resources/Player.png");

    ScaleTo(0.07f);

    // cria bounding box
    BBox(new Circle(12 * (1 / 0.07f)));

    // inicializa estado do player
    equipment = PISTOL;
    shotgunShells = 4;
    pistolRounds = 12;
    hp = 3;
    level = 0;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete anim;
    delete equipmentSprite;
    delete bulletSprite;
    delete hpSprite;
    delete font;
    delete gamepad;
    delete sprite;
    delete projectile;
}

void Player::Draw()
{
    anim->Draw(x, y, Layer::MIDDLE, scale, rotation);
    sprite->Draw(x, y, Layer::UPPER, scale, rotation);
    equipmentSprite->Draw(100, 50, Layer::FRONT, 0.7, 0, Color({ 1, 1, 1, 0.8 }));
    hpSprite->Draw(1880, 40, Layer::FRONT, 0.7, 0, Color({ 1, 1, 1, 0.8 }));
    bulletSprite->Draw(1880, 100, Layer::FRONT, 0.7, 0, Color({ 1, 1, 1, 0.8 }));

    Color grey(1.0f, 1.0f, 1.0f, 0.8f);

    std::ostringstream health;
    health << std::setw(2) << std::setfill('0') << hp;
    font->Draw(1830, 40, health.str(), grey, Layer::FRONT, 0.2f);

    std::ostringstream bullets;
    bullets << std::setw(2) << std::setfill('0') << (equipment == PISTOL ? pistolRounds : shotgunShells);
    font->Draw(1830, 100, bullets.str(), grey, Layer::FRONT, 0.2f);
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
    if (obj->Type() == WALL)
    {
        Wall* wall = dynamic_cast<Wall*>(obj);

        int top = wall->Y();
        int bot = wall->Y() + wall->height;
        int left = wall->X();
        int right = wall->X() + wall->width;

        if (x <= left) {
            MoveTo(wall->X() - 12, Y());
        }

        else if (x >= right) {
            MoveTo(wall->X() + wall->width + 12, Y());
        }

        else if (y >= bot) {
            MoveTo(X(), wall->Y() + wall->height + 12);
        }

        else if (y <= top) {
            MoveTo(X(), wall->Y() - 12);
        }
    }

    if (obj->Type() == ZOMBIE) {
        Translate(10, 0);
        Level1::scene->Add(new Challenge(), STATIC);
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
        Translate(gamepad->Axis(AxisX) * 0.15f * gameTime, gamepad->Axis(AxisY) * 0.15f * gameTime);

        if (gamepad->Axis(AxisX) != 0 || gamepad->Axis(AxisY) != 0) {
            int xx = gamepad->Axis(AxisX);
            int yy = gamepad->Axis(AxisY);

            double radianos = std::atan2(-yy, xx);
            double graus = radianos * 180 / 3.14159;
            RotateTo(graus);

            float speed = 1 / (max(abs(xx), abs(yy)) * 0.02);

            anim->Select(WALKING);
            anim->Delay(speed);
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
            Shoot();
        }
    }
    else {
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

        Translate(xx * 100 * gameTime, yy * 100 * gameTime);

        double radianos = std::atan2(-yy, xx);
        double graus = radianos * 180 / 3.14159;

        if (!xx && !yy)
            anim->Select(STILL);
        else {
            anim->Select(WALKING);
            RotateTo(graus);
        }
    }

    // atualiza animação
    anim->Select(equipment);
    anim->NextFrame();
}

void Player::Shoot() {
    switch (equipment)
    {
    case PISTOL:
        if (gunTimer.Elapsed(0.1f) && pistolRounds > 0) {
            gunTimer.Reset();
            Index::audio->Play(GUN_SOUND);
            Level1::scene->Add(new Projectile(this, projectile, 0), MOVING);

            pistolRounds--;
        }
        break;
    case SHOTGUN:
        if (gunTimer.Elapsed(1.0f) && shotgunShells > 0) {
            gunTimer.Reset();
            Index::audio->Play(SHOTGUN_SOUND);
            Level1::scene->Add(new Projectile(this, projectile, 4), MOVING);
            Level1::scene->Add(new Projectile(this, projectile, 10), MOVING);
            Level1::scene->Add(new Projectile(this, projectile, -4), MOVING);
            Level1::scene->Add(new Projectile(this, projectile, -10), MOVING);

            shotgunShells--;
        }
        break;
    default:
        break;
    }
}

void Player::AddPistolAmmo(int amount) {
    pistolRounds += amount;
}

void Player::AddShotgunAmmo(int amount) {
    shotgunShells += amount;
}

// ---------------------------------------------------------------------------------