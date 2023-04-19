/**********************************************************************************
// Wall (Arquivo de Cabeçalho)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
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

    void Update();                              // atualização
    void Draw();                                // desenho
    void OnCollision(Object* obj);     // resolução da colisão
};

// ------------------------------------------------------------------------------

#endif