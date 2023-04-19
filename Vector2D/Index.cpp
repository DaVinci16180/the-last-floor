/**********************************************************************************
// Index (Código Fonte)
//
// Criação:     05 Out 2011
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "Index.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros estáticos da classe
Game* Index::level = nullptr;
Player* Index::player = nullptr;
Presence* Index::presence = nullptr;
Audio* Index::audio = nullptr;
bool    Index::viewBBox = true;

// ------------------------------------------------------------------------------

void Index::Init()
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(RAIN, "Resources/Rain.wav");
    audio->Add(GONG, "Resources/Gong.wav");
    audio->Add(GUN_SOUND, "Resources/Pistol.wav", 3);
    audio->Add(SHOTGUN_SOUND, "Resources/Shotgun.wav", 3);
    audio->Add(MUSIC, "Resources/Music.wav");
    audio->Add(TRANSITION, "Resources/Transition.wav");
    audio->Add(LIGHT_SWITCH, "Resources/LightSwitch.wav");

    // bounding box não visível
    viewBBox = false;

    // cria jogador
    player = new Player();
    presence = new Presence();

    // inicializa nível de abertura do jogo
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void Index::Update()
{
    // habilita/desabilita visualização da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;

    // atualiza nível
    level->Update();
}

// ------------------------------------------------------------------------------

void Index::Draw()
{
    // desenha nível
    level->Draw();
}

// ------------------------------------------------------------------------------

void Index::Finalize()
{
    level->Finalize();

    delete player;
    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1920, 1080);
    engine->window->Color(30, 50, 80);
    engine->window->Title("Zombia");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Index());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

