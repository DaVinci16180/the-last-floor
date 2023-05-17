/**********************************************************************************
// Zombie (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
#include "Vector.h"                 // representa��o de vetor

// ------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

class Zombie : public Object
{
private:
    TileSet* tileset;                // folha de sprites do personagem
    Animation* feet;                   // anima��o do personagem
    int         hp;

    Sprite* sprite;
    Vector direction;               // dire��o do avi�o
public:
    Zombie(int x, int y);                           // construtor
    ~Zombie();                          // destrutor

    float Angle();                  // retorna �ngulo do vetor dire��o
    void Rotate(float angle);       // rota��o (sobrescreve m�todo)
    void RotateTo(float angle);

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

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