/**********************************************************************************
// Zombie (Arquivo de Cabeçalho)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Vector.h"                 // representação de vetor
#include "Player.h"
// ------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

class Zombie : public Object
{
private:
    TileSet* tileset;                // folha de sprites do personagem
    Animation* feet;                   // animação do personagem

    Sprite*      sprite;
    Vector       direction;               // direção do avião
    Vector       push;

public:
    int         hp;

public:
    Zombie(int x, int y);                           // construtor
    ~Zombie();                          // destrutor

    float Angle();                  // retorna ângulo do vetor direção
    void Rotate(float angle);       // rotação (sobrescreve método)
    void RotateTo(float angle);
    
    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();   
    
    void Chase();                     // desenho do objeto
    void Push(float pX, float pY);

};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Zombie::Draw()
{
    feet->Draw(x, y, Layer::MIDDLE, scale, rotation);
    sprite->Draw(x, y, Layer::UPPER, scale, rotation);
}

inline float Zombie::Angle()
{
    return direction.Angle();
}

// ---------------------------------------------------------------------------------

#endif