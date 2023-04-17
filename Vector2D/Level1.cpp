/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#include "Index.h"
#include "Home.h"
#include "Level1.h"
#include "GameOver.h"
#include "Player.h"
#include "Room.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // adiciona jogador na cena
    scene->Add(Index::player, MOVING);

    // ----------------------

    int amount = 17;
    RoomCoordinates coordenadas[] = {
        RoomCoordinates {0,0,485,367},
        RoomCoordinates {485,0,372,271},
        RoomCoordinates {857,0,415,440},
        RoomCoordinates {1272,0,648,664},
        RoomCoordinates {242,183,243,380},
        RoomCoordinates {485,271,187,217},
        RoomCoordinates {672,271,185,217},
        RoomCoordinates {1272,200,448,464},
        RoomCoordinates {0,367,242,395},
        RoomCoordinates {241,562,244,336},
        RoomCoordinates {485,488,372,152},
        RoomCoordinates {1057,440,291,200},
        RoomCoordinates {485,640,475,258},
        RoomCoordinates {0,762,374,318},
        RoomCoordinates {374,898,586,182},
        RoomCoordinates {960,640,388,440},
        RoomCoordinates {1348,664,572,416},
    };

    for (int i = 1; i <= amount; i++) {
        string path = "Resources/Level1/Room";
        path.append(std::to_string(i));
        RoomCoordinates c = coordenadas[i - 1];
        int halfWidth = ceil((float)c.width / 2.0f);
        int halfHeight = ceil((float)c.height / 2.0f);
        scene->Add(new Room(c.x + halfWidth, c.y + halfHeight, path + "-light.png", path + "-dark.png", new Rect(-halfWidth, -halfHeight, halfWidth, halfHeight)), STATIC);
    }

    scene->Add(new Room(window->Width()/2 - 3, window->Height() / 2, "Resources/Level1/Start-light.png", "Resources/Level1/Start-dark.png", new Rect(-100, -100, 99, 99)), STATIC);

    // inicia com música
    Index::audio->Play(GONG);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        Index::audio->Stop(MUSIC);
        Index::NextLevel<Home>();
        Index::player->Reset();
    }
    else if (Index::player->Level() == 1 || window->KeyPress('N'))
    {
        //Index::NextLevel<Level2>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    //backg->Draw();
    scene->Draw();

    if (Index::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(Index::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------
