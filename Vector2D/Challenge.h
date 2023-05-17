/**********************************************************************************
// Challenge (Arquivo de Cabe�alho)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#ifndef _DROP_H_
#define _DROP_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representa��o de vetor
#include "Player.h"                              // objeto avi�o
#include "Trail.h"                              // objeto avi�o

// --------------------------------------------------------------------------------

class Challenge : public Object
{
public:
    Sprite* background;
    Sprite* frame;

    TileSet* playerAndZombie;
    Animation* playerAndZombieAnim;

    TileSet* buttonPunch;
    Animation* buttonPunchAnim;

    Timer timer;
    Timer decreaseTimer;
    int counter;

    Controller* gamepad;
    bool        gamepadOn;

public:
    Challenge();        // construtor
    ~Challenge();                                 // destrutor

    void Update();                              // atualiza��o
    void Draw();                                // desenho
};

// ------------------------------------------------------------------------------

#endif
#pragma once
