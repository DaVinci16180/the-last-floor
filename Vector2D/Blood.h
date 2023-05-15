/**********************************************************************************
// Blood (Arquivo de Cabe�alho)
//
// Cria��o:     17 Mar 2013
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#ifndef _BLOOD_H_
#define _BLOOD_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Particles.h"

// ---------------------------------------------------------------------------------

class Blood : public Object
{
private:
    Particles* sparks;                 // sistema de part�culas

public:
    Blood(float pX, float pY, float angle, float spread, Color color);      // construtor
    ~Blood();                       // destrutor

    int Size();                         // quantidade de part�culas
    void Update();                      // atualiza��o
    void Draw();                        // desenho
};

// ---------------------------------------------------------------------------------

inline int Blood::Size()
{
    return sparks->Size();
}

inline void Blood::Draw()
{
    sparks->Draw(Layer::MIDDLE, 1.0f);
}

// ---------------------------------------------------------------------------------


#endif