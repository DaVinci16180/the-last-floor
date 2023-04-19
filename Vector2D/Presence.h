/**********************************************************************************
// Presence (Arquivo de Cabeçalho)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
//
**********************************************************************************/

#ifndef _PRESENCE_H_
#define _PRESENCE_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 

// --------------------------------------------------------------------------------

class Presence : public Object
{
public:
    Presence();        // construtor
    ~Presence();                                 // destrutor

    void Update();                              // atualização
    void Draw();                                // desenho
    void OnCollision(Object* obj);     // resolução da colisão
};

// ------------------------------------------------------------------------------

#endif