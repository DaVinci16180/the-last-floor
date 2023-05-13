/**********************************************************************************
// Trail (C�digo Fonte)
//
// Cria��o:     17 Mar 2013
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de fuma�a usando sistema de part�culas
//
**********************************************************************************/

#include "Trail.h"
#include "Index.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Trail::Trail(float pX, float pY, float angle)
{
    // configura gerador de part�culas
    Generator trail;
    trail.imgFile = "Resources/Projectile.png";    // arquivo de imagem
    trail.angle = angle;                    // dire��o da fuma�a
    trail.spread = 0;                       // espalhamento em graus
    trail.lifetime = .5f;                     // tempo de vida em segundos
    trail.frequency = 0.010f;                 // tempo entre gera��o de novas part�culas
    trail.percentToDim = .9f;                 // desaparece ap�s 60% da vida
    trail.minSpeed = 10.f;                    // velocidade m�nima das part�culas
    trail.maxSpeed = 10.f;                   // velocidade m�xima das part�culas

    // cria sistema de part�culas
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
