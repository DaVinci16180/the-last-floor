/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _PLAYER_H_
#define _PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
#include "Vector.h"                 // representa��o de vetor
#include "Types.h"                  // tipos espec�ficos do motor
#include "Controller.h"             // leitura do controle
#include "Font.h"                   // exibi��o de texto
#include <sstream>                                

// ------------------------------------------------------------------------------

enum Equipment { UNARMED, BAT, PISTOL, SHOTGUN };         // Equipamento do player
enum State { WALKING, STILL };
enum ButtonMapping { A_BUTTON = 0, B_BUTTON = 1, X_BUTTON = 2, Y_BUTTON = 3, DPAD = 0, START = 7 };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet*     tileset;                // folha de sprites do personagem
    Animation*   anim;                   // anima��o do personagem
    uint         equipment;              // equipamento do jogador
    uint         hp;
    int          level;                  // n�vel finalizado
    Timer        gunTimer;

    Sprite*      equipmentSprite;
    Sprite*      bulletSprite;
    Sprite*      hpSprite;

    Controller* gamepad;           // entrada via controle
    bool gamepadOn;                 // controle conectado

    Sprite* sprite;                // sprite do avi�o
    Image* projectile;                // imagem do m�ssil
    Vector direction;               // dire��o do avi�o
public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // �ltimo n�vel finalizado

    float Angle();                  // retorna �ngulo do vetor dire��o
    void Rotate(float angle);       // rota��o (sobrescreve m�todo)
    void RotateTo(float angle);

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline int Player::Level()
{
    return level;
}

inline void Player::Draw()
{
    anim->Draw(x, y, Layer::UPPER, scale, rotation);
    equipmentSprite->Draw(100, 50, Layer::FRONT, 0.7, 0, Color({1, 1, 1, 0.8}));
    hpSprite->Draw(1880, 40, Layer::FRONT, 0.7, 0, Color({ 1, 1, 1, 0.8 }));
    bulletSprite->Draw(1880, 100, Layer::FRONT, 0.7, 0, Color({ 1, 1, 1, 0.8 }));
}

inline float Player::Angle()
{
    return direction.Angle();
}

// ---------------------------------------------------------------------------------

#endif