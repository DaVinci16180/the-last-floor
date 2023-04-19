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
#include "Wall.h"

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
    scene->Add(Index::presence, MOVING);

    // ----------------------

    int amount = 17;
    Coordinates salas[] = {
        Coordinates {0,0,485,367},
        Coordinates {485,0,372,271},
        Coordinates {857,0,415,440},
        Coordinates {1272,0,648,664},
        Coordinates {242,183,243,380},
        Coordinates {485,271,187,217},
        Coordinates {672,271,185,217},
        Coordinates {1272,200,448,464},
        Coordinates {0,367,242,395},
        Coordinates {241,562,244,336},
        Coordinates {485,488,372,152},
        Coordinates {1057,440,291,200},
        Coordinates {485,640,475,258},
        Coordinates {0,762,374,318},
        Coordinates {374,898,586,182},
        Coordinates {960,640,388,440},
        Coordinates {1348,664,572,416},
    };

    for (int i = 1; i <= amount; i++) {
        string path = "Resources/Level1/Room";
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

    scene->Add(new Room(window->Width()/2 - 3, window->Height() / 2, "Resources/Level1/Start-light.png", "Resources/Level1/Start-dark.png", new Rect(-100, -100, 99, 99)), STATIC);

    amount = 47;
    Coordinates paredes[] = {
        // em volta
        Coordinates {0, 0, 5, 1080},
        Coordinates {0, 0, 1920, 5},
        Coordinates {0, 1075, 1920, 5},
        Coordinates {1915, 0, 5, 1080},

        // salas
        Coordinates { 379,893,576,10 },
        Coordinates { 247,178,96,10 },
        Coordinates { 383,178,97,10 },
        Coordinates { 480,106,10,193 },
        Coordinates { 480,339,10,166 },
        Coordinates { 480,545,10,38 },
        Coordinates { 480,623,10,202 },
        Coordinates { 480,860,10,33 },
        Coordinates { 237,178,10,270 },
        Coordinates { 237,488,10,269 },
        Coordinates { 480,5,10,61 },
        Coordinates { 852,5,10,117 },
        Coordinates { 852,162,10,177 },
        Coordinates { 852,379,10,164 },
        Coordinates { 852,583,10,52 },
        Coordinates { 955,645,10,324 },
        Coordinates { 955,1009,10,66 },
        Coordinates { 1343,1029,10,46 },
        Coordinates { 1343,445,10,544 },
        Coordinates { 1267,5,10,81 },
        Coordinates { 1267,126,10,173 },
        Coordinates { 1267,339,10,96 },
        Coordinates { 1052,445,10,75 },
        Coordinates { 1052,560,10,75 },
        Coordinates { 1715,205,10,454 },
        Coordinates { 369,757,10,212 },
        Coordinates { 369,1009,10,66 },
        Coordinates { 5,362,96,10 },
        Coordinates { 141,362,96,10 },
        Coordinates { 5,757,96,10 },
        Coordinates { 141,757,228,10 },
        Coordinates { 247,558,233,9 },
        Coordinates { 667,276,10,144 },
        Coordinates { 667,460,10,23 },
        Coordinates { 490,483,362,10 },
        Coordinates { 490,266,362,10 },
        Coordinates { 862,435,491,10 },
        Coordinates { 1277,195,448,10 },
        Coordinates { 490,635,692,10 },
        Coordinates { 1222,635,121,10 },
        Coordinates { 1353,659,164,10 },
        Coordinates { 1557,659,249,10 },
        Coordinates { 1846,659,69,10 },
    };

    for (int i = 0; i < amount; i++) {
        Coordinates c = paredes[i];
        scene->Add(new Wall(c.x, c.y, c.width, c.height), STATIC);
    }

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
