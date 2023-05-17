/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo
//
**********************************************************************************/

#ifndef _LEVEL2_H_
#define _LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Chase.h"
// ------------------------------------------------------------------------------


class Level2 : public Game
{
private:
    //Background* backg = nullptr;   // pano de fundo animado

public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif