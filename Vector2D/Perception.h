/**********************************************************************************
// Perception (Arquivo de Cabe�alho)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#ifndef _PERCEPTION_H_
#define _PERCEPTION_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representa��o de vetor
#include "Player.h"                              // objeto avi�o
#include "Trail.h"                              // objeto avi�o
#include "Zombie.h"                              // objeto avi�o

// --------------------------------------------------------------------------------

class Perception : public Object
{
private:
    Zombie* zombie = nullptr;

public:
    Perception(Zombie* z);        // construtor
    ~Perception();                                 // destrutor

    void Update();                              // atualiza��o
    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Draw();     // resolu��o da colis�o
};

// ------------------------------------------------------------------------------

#endif