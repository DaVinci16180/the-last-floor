/**********************************************************************************
// Wall (Arquivo de Cabe�alho)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#ifndef _WALL_H_
#define _WALL_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo

// --------------------------------------------------------------------------------

class Wall : public Object
{
public:
    int width = 0;
    int height = 0;

    Wall(float posX, float posY, int w, int h);        // construtor
    ~Wall();                                 // destrutor

    void Update();                              // atualiza��o
    void Draw();                                // desenho
    void OnCollision(Object* obj);     // resolu��o da colis�o
};

// ------------------------------------------------------------------------------

#endif