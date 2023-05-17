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
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Room.h"
#include "Wall.h"
#include "Zombie.h"
#include "Chase.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // adiciona jogador na cena
    scene->Add(Index::player, MOVING);
    scene->Add(Index::presence, MOVING);

    // ----------------------

    int amount = 18;
    Coordinates salas[] = {
        Coordinates{1405,742,292,338},
        Coordinates{946,742,461,338},
        Coordinates{657,940,290,140},
        Coordinates{1226,214,201,188},
        Coordinates{242,838,415,242},
        Coordinates{241,840,293,417},
        Coordinates{656,743,290,197},
        Coordinates{0,607,242,473},
        Coordinates{1697,1080,680,223},
        Coordinates{1226,402,471,341},
        Coordinates{1424,214,496,188},
        Coordinates{638,214,588,529},
        Coordinates{241,395,416,152},
        Coordinates{0,395,242,212},
        Coordinates{842,0,1078,214},
        Coordinates{657,0,185,214},
        Coordinates{242,0,415,395},
        Coordinates{0,0242,395}
    };

    for (int i = 1; i <= amount; i++) {
        string path = "Resources/Level2/Room";
        path.append(std::to_string(i));
        Coordinates c = salas[i - 1];
        int halfWidth = ceil((float)c.width / 2.0f);
        int halfHeight = ceil((float)c.height / 2.0f);

        Geometry* g;
        if (i == 1) {
            Mixed* m = new Mixed();
            m->Insert(new Rect(-242, -184, 242, -1));
            m->Insert(new Rect(-242, -1, 0, 183));

            g = m;
        }
        else if (i == 4) {
            Mixed* m = new Mixed();
            m->Insert(new Rect(-324, -332, 323, -132));
            m->Insert(new Rect(124, -132, 323, 332));

            g = m;
        }
        else if (i == 8) {
            Mixed* m = new Mixed();
            m->Insert(new Rect(-223, -232, 224, 8));
            m->Insert(new Rect(-147, 8, 224, 232));

            g = m;
        }
        else if (i == 10) {
            Mixed* m = new Mixed();
            m->Insert(new Rect(-121, -167, 122, 32));
            m->Insert(new Rect(11, 32, 122, 168));

            g = m;
        }
        else {
            g = new Rect(-halfWidth, -halfHeight, halfWidth, halfHeight);
        }
        scene->Add(new Room(c.x + halfWidth, c.y + halfHeight, path + "-light.png", path + "-dark.png", g), STATIC);

        // 1 4 8 10
    }

    scene->Add(new Room(window->Width() / 2 - 3, window->Height() / 2, "Resources/Level1/Start-light.png", "Resources/Level1/Start-dark.png", new Rect(-100, -100, 99, 99)), STATIC);

    amount = 31;
    Coordinates paredes[] = {
        // em volta
        Coordinates {0, 0, 5, 1080},
        Coordinates {0, 0, 1920, 5},
        Coordinates {0, 1075, 1920, 5},
        Coordinates {1915, 0, 5, 1080},

        // salas
        Coordinates{1231,407,10,684},
        Coordinates{237,5,10,76},
        Coordinates{237,121,10,269},
        Coordinates{237,395,10,63},
        Coordinates{237,498,10,442},
        Coordinates{237,980,10,95},
        Coordinates{652,636,10,382},
        Coordinates{941,747,10,328},
        Coordinates{1401,747,10,328},
        Coordinates{1221,329,10,412},
        Coordinates{1692,407,10,555},
        Coordinates{652,1058,10,17},
        Coordinates{652,490,10,106},
        Coordinates{837,5,10,142},
        Coordinates{837,186,10,23},
        Coordinates{1221,218,10,71},
        Coordinates{1420,218,10,71},
        Coordinates{1420,329,10,68},
        Coordinates{652,67,10,383},
        Coordinates{652,5,10,28},
        Coordinates{141,400,10,516},
        Coordinates{652,219,10,1263},
        Coordinates{653,748,10,657},
        Coordinates{1350,748,10,197},
        Coordinates{1587,748,10,105},
        Coordinates{246,552,10,407},
        Coordinates{247,844,10,406},
        Coordinates{5,612,10,83},
        Coordinates{128,612,10,110},
        Coordinates{662,945,10,280},
        Coordinates{5,400,10,96},
        Coordinates{1692,1002,10,73}
    };

    for (int i = 0; i < amount; i++) {
        Coordinates c = paredes[i];
        scene->Add(new Wall(c.x, c.y, c.width, c.height), STATIC);
    }

    //Zombie* z = new Zombie(900, 540, Index::player);
    //scene->Add(z, MOVING);
    //Chase* chase = new Chase(z);
    //scene->Add(chase, MOVING);
    // inicia com música
    Index::audio->Play(GONG);
}

// ------------------------------------------------------------------------------

void Level2::Update()
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

void Level2::Draw()
{
    //backg->Draw();
    scene->Draw();

    if (Index::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    scene->Remove(Index::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------
