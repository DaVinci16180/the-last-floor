/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "Index.h"
#include "Home.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Home::Init()
{

    gamepad = new Controller();
    gamepadOn = gamepad->Initialize();

    backg = new Sprite("Resources/TitleScreen.png");
    tileset = new TileSet("Resources/PressEnter.png", 72, 48, 1, 5);
    anim = new Animation(tileset, 0.180f, true);
    Index::audio->Play(RAIN, true);
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    if (gamepadOn)
    {
        // lê estado atualizado do controle
        gamepad->UpdateState();

        if (gamepad->ButtonPress(7))
        {
            Index::audio->Stop(RAIN);
            Index::NextLevel<Level1>();
        } else if (gamepad->ButtonPress(1))
        {
            window->Close();
        }
        else
        {
            anim->NextFrame();
        }
    }

    // sai com o pressionar do ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    // se a tecla ENTER for pressionada
    if (window->KeyPress(VK_RETURN))
    {
        Index::audio->Stop(RAIN);
        Index::NextLevel<Level1>();
    }
    else if (!gamepadOn)
    {
        anim->NextFrame();
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    anim->Draw(545, 275);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete anim;
    delete tileset;
    delete backg;
}

// ------------------------------------------------------------------------------