/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _PLAYER_H_
#define _PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Vector.h"                 // representação de vetor
#include "Types.h"                  // tipos específicos do motor
#include "Controller.h"             // leitura do controle
#include "Font.h"                   // exibição de texto
#include "Zombie.h"
#include <sstream>     
#include <iomanip>

// ------------------------------------------------------------------------------

enum Equipment { UNARMED, BAT, PISTOL, SHOTGUN };         // Equipamento do player
enum State { WALKING, STILL };
enum ButtonMapping { A_BUTTON = 0, B_BUTTON = 1, X_BUTTON = 2, Y_BUTTON = 3, DPAD = 0, START = 7 };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet*     tileset;                // folha de sprites do personagem
    Animation*   anim;                   // animação do personagem
    uint         equipment;              // equipamento do jogador
    int          level;                  // nível finalizado
    Timer        gunTimer;
    uint         hp;
    uint         pistolRounds;
    uint         shotgunShells;

    Sprite*      equipmentSprite;
    Sprite*      bulletSprite;
    Sprite*      hpSprite;
    Font*        font;

    Controller*  gamepad;           // entrada via controle
    bool         gamepadOn;                 // controle conectado

    Sprite*      sprite;                // sprite do player
    Image*       projectile;                // imagem do míssil
    Vector       direction;               // direção do avião
    Vector       push;
public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado

    float Angle();                  // retorna ângulo do vetor direção
    void Rotate(float angle);       // rotação (sobrescreve método)
    void RotateTo(float angle);

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto

    void Shoot();
    void AddPistolAmmo(int amount);
    void AddShotgunAmmo(int amount);

    void Push(float zX, float zY);
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline int Player::Level()
{
    return level;
}

inline float Player::Angle()
{
    return direction.Angle();
}

// ---------------------------------------------------------------------------------

#endif