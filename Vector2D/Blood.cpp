/**********************************************************************************
// Blood (Código Fonte)
//
// Criação:     17 Mar 2013
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de explosão usando sistema de partículas
//
**********************************************************************************/

#include "Index.h"
#include "Blood.h"
#include "Random.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Blood::Blood(float pX, float pY, float angle, float spread, Color color)
{

    // configura emissor de partículas
    Generator explosion;
    explosion.imgFile = "Resources/Blood.png";    // arquivo de imagem
    explosion.angle = angle;                     // direção da explosão
    explosion.spread = spread;                   // espalhamento em graus
    explosion.lifetime = 0.4f;                     // tempo de vida em segundos
    explosion.frequency = 0.000f;                   // tempo entre geração de novas partículas
    explosion.percentToDim = 0.0f;                  // desaparece após 60% da vida
    explosion.minSpeed = 30.0f;                    // velocidade mínima das partículas
    explosion.maxSpeed = 150.0f;                   // velocidade máxima das partículas
    explosion.color.r = color.r;
    explosion.color.g = color.g;
    explosion.color.b = color.b;
    explosion.color.a = 1.0f;                     // transparência da partícula

    // cria sistema de partículas
    sparks = new Particles(explosion);

    Scale(0.5);

    // gera 50 partículas na posição indicada

    
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
    // atualiza posição de cada partícula
    sparks->Update(gameTime);

    // remove da cena quando todas as partículas estão inativas
    if (sparks->Inactive())
        Level1::scene->Delete();
}

// -------------------------------------------------------------------------------