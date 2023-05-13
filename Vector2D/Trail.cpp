/**********************************************************************************
// Trail (Código Fonte)
//
// Criação:     17 Mar 2013
// Atualização: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de fumaça usando sistema de partículas
//
**********************************************************************************/

#include "Trail.h"
#include "Index.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Trail::Trail(float pX, float pY, float angle)
{
    // configura gerador de partículas
    Generator trail;
    trail.imgFile = "Resources/Projectile.png";    // arquivo de imagem
    trail.angle = angle;                    // direção da fumaça
    trail.spread = 0;                       // espalhamento em graus
    trail.lifetime = .5f;                     // tempo de vida em segundos
    trail.frequency = 0.010f;                 // tempo entre geração de novas partículas
    trail.percentToDim = .9f;                 // desaparece após 60% da vida
    trail.minSpeed = 10.f;                    // velocidade mínima das partículas
    trail.maxSpeed = 10.f;                   // velocidade máxima das partículas

    // cria sistema de partículas
    gen = new Particles(trail);
    MoveTo(pX, pY);
    type = TRAIL;

    stop = false;
}

// ---------------------------------------------------------------------------------

Trail::~Trail()
{
    delete gen;
}

void Trail::TurnOff()
{
    stop = true;
}

// -------------------------------------------------------------------------------

void Trail::Update()
{
    if (stop)
    {
        if (gen->Inactive())
            Level1::scene->Delete();
    }
    else
    {
        gen->Generate(x, y);
    }

    gen->Update(gameTime);
}

// -------------------------------------------------------------------------------
