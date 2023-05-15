/**********************************************************************************
// Drop (Arquivo de Cabeçalho)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
//
**********************************************************************************/

#ifndef _DROP_H_
#define _DROP_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representação de vetor
#include "Player.h"                              // objeto avião
#include "Trail.h"                              // objeto avião

// --------------------------------------------------------------------------------

class Drop : public Object
{
public:
    Sprite* sprite;
    int type;
    int amount;

public:
    Drop(float x, float y, int type, int amount);        // construtor
    ~Drop();                                 // destrutor

    void Update();                              // atualização
    void Draw();                                // desenho
    void OnCollision(Object* obj);     // resolução da colisão
};

// ------------------------------------------------------------------------------

#endif