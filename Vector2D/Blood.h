/**********************************************************************************
// Blood (Arquivo de Cabeçalho)
//
// Criação:     17 Mar 2013
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de explosão usando sistema de partículas
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
    Particles* sparks;                 // sistema de partículas

public:
    Blood(float pX, float pY, float angle, float spread, Color color);      // construtor
    ~Blood();                       // destrutor

    int Size();                         // quantidade de partículas
    void Update();                      // atualização
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