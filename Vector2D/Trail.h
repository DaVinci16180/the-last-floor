/**********************************************************************************
// Trail (Arquivo de Cabeçalho)
//
// Criação:     17 Mar 2013
// Atualização: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de fumaça usando sistema de partículas
//
**********************************************************************************/

#ifndef _TRAIL_H_
#define _TRAIL_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Types.h"
#include "Particles.h"

// ---------------------------------------------------------------------------------

class Trail : public Object
{
private:
    Particles* gen;               // sistema de partículas
    bool       stop;

public:
    Trail(float pX, float pY, float angle);
    ~Trail();                           // destrutor

    int  Size();                        // quantidade de partículas
    void TurnOff();                     // desligar fumaça

    void Update();                      // atualização
    void Draw();                        // desenho
};

// ---------------------------------------------------------------------------------

inline int Trail::Size()
{
    return gen->Size();
}

inline void Trail::Draw()
{
    gen->Draw(Layer::MIDDLE, 1.0f);
}

// ---------------------------------------------------------------------------------


#endif