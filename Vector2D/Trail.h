/**********************************************************************************
// Trail (Arquivo de Cabe�alho)
//
// Cria��o:     17 Mar 2013
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de fuma�a usando sistema de part�culas
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
    Particles* gen;               // sistema de part�culas
    bool       stop;

public:
    Trail(float pX, float pY, float angle);
    ~Trail();                           // destrutor

    int  Size();                        // quantidade de part�culas
    void TurnOff();                     // desligar fuma�a

    void Update();                      // atualiza��o
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