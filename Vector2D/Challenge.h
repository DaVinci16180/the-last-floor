/**********************************************************************************
// Challenge (Arquivo de Cabeçalho)
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
#include "Zombie.h"                              // objeto avião

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

    Zombie* zombie;

public:
    Challenge(Zombie* z);        // construtor
    ~Challenge();                                 // destrutor

    void Update();                              // atualização
    void Draw();                                // desenho
};

// ------------------------------------------------------------------------------

#endif
#pragma once
