/**********************************************************************************
// Perception (Arquivo de Cabeçalho)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
//
**********************************************************************************/

#ifndef _PERCEPTION_H_
#define _PERCEPTION_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representação de vetor
#include "Player.h"                              // objeto avião
#include "Trail.h"                              // objeto avião
#include "Zombie.h"                              // objeto avião

// --------------------------------------------------------------------------------

class Perception : public Object
{
private:
    Zombie* zombie = nullptr;

public:
    Perception(Zombie* z);        // construtor
    ~Perception();                                 // destrutor

    void Update();                              // atualização
    void OnCollision(Object* obj);     // resolução da colisão
    void Draw();     // resolução da colisão
};

// ------------------------------------------------------------------------------

#endif