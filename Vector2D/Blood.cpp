/**********************************************************************************
// Blood (C�digo Fonte)
//
// Cria��o:     17 Mar 2013
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "Index.h"
#include "Blood.h"
#include "Random.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Blood::Blood(float pX, float pY, float angle, float spread, Color color)
{

    // configura emissor de part�culas
    Generator explosion;
    explosion.imgFile = "Resources/Blood.png";    // arquivo de imagem
    explosion.angle = angle;                     // dire��o da explos�o
    explosion.spread = spread;                   // espalhamento em graus
    explosion.lifetime = 0.4f;                     // tempo de vida em segundos
    explosion.frequency = 0.000f;                   // tempo entre gera��o de novas part�culas
    explosion.percentToDim = 0.0f;                  // desaparece ap�s 60% da vida
    explosion.minSpeed = 30.0f;                    // velocidade m�nima das part�culas
    explosion.maxSpeed = 150.0f;                   // velocidade m�xima das part�culas
    explosion.color.r = color.r;
    explosion.color.g = color.g;
    explosion.color.b = color.b;
    explosion.color.a = 1.0f;                     // transpar�ncia da part�cula

    // cria sistema de part�culas
    sparks = new Particles(explosion);

    Scale(0.5);

    // gera 50 part�culas na posi��o indicada

    
    sparks->Generate(pX, pY, 50);
    type = BLOOD;
}

// ---------------------------------------------------------------------------------

Blood::~Blood()
{
    delete sparks;
}

// -------------------------------------------------------------------------------

void Blood::Update()
{
    // atualiza posi��o de cada part�cula
    sparks->Update(gameTime);

    // remove da cena quando todas as part�culas est�o inativas
    if (sparks->Inactive())
        Level1::scene->Delete();
}

// -------------------------------------------------------------------------------