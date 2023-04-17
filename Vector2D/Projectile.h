/**********************************************************************************
// Projectile (Arquivo de Cabe�alho)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representa��o de vetor
#include "Player.h"                              // objeto avi�o

// --------------------------------------------------------------------------------

class Projectile : public Object
{
public:
    Sprite* sprite;                            // sprite do m�ssil
    Vector speed;                               // velocidade do m�ssil

public:
    Projectile(Player* player, Image* img, float angle);        // construtor
    ~Projectile();                                 // destrutor

    void Update();                              // atualiza��o
    void Draw();                                // desenho
};

// ------------------------------------------------------------------------------

#endif