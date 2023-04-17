/**********************************************************************************
// Projectile (Arquivo de Cabeçalho)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
//
**********************************************************************************/

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representação de vetor
#include "Player.h"                              // objeto avião

// --------------------------------------------------------------------------------

class Projectile : public Object
{
public:
    Sprite* sprite;                            // sprite do míssil
    Vector speed;                               // velocidade do míssil

public:
    Projectile(Player* player, Image* img, float angle);        // construtor
    ~Projectile();                                 // destrutor

    void Update();                              // atualização
    void Draw();                                // desenho
};

// ------------------------------------------------------------------------------

#endif