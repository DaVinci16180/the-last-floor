/**********************************************************************************
// Challenge (C�digo Fonte)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Challenge.h"
#include "Index.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

Challenge::Challenge(Zombie* z)
{
    zombie = z;
    counter = 0;
    timer.Start();
    decreaseTimer.Start();

    gamepad = new Controller();
    gamepadOn = gamepad->Initialize();

    background = new Sprite("Resources/DarkBg.png");
    frame = new Sprite("Resources/Frame.png");
   
    playerAndZombie = new TileSet("Resources/Attack.png", 1, 1);
    playerAndZombieAnim = new Animation(playerAndZombie, 0.5, true);
   
    buttonPunch = new TileSet("Resources/APunch.png", 1, 4);
    buttonPunchAnim = new Animation(buttonPunch, 0.2, true);

    MoveTo(960, 540);
}

// ------------------------------------------------------------------------------

Challenge::~Challenge()
{
    delete background;
    delete frame;
    delete playerAndZombie;
    delete playerAndZombieAnim;
    delete buttonPunch;
    delete buttonPunchAnim;
}

// -------------------------------------------------------------------------------

void Challenge::Update()
{
    if (timer.Elapsed(10.f)) {
        window->Close();
    } else if (counter >= 20) {
        Index::challenge = false;
        Level1::scene->Delete(this, STATIC);

        // empurra
        Index::player->Push(zombie->X(), zombie->Y());
        zombie->Push(Index::player->X(), Index::player->Y());
    }
    else {
        playerAndZombieAnim->NextFrame();
        buttonPunchAnim->NextFrame();

        if (decreaseTimer.Elapsed(.5f) && counter >= -10) {
            decreaseTimer.Start();
            counter--;
        }

        if (gamepadOn)
        {
            // l� estado atualizado do controle
            gamepad->UpdateState();

            if (gamepad->ButtonPress(0))
            {
                counter++;
            }
        }

        if (window->KeyPress(VK_SPACE))
            counter++;
    }
}

// -------------------------------------------------------------------------------

void Challenge::Draw()
{
    background->Draw(x, y, 0.1f, scale, rotation, Color{ 1,1,1,1 });
    frame->Draw(x, y, 0.f, scale, rotation, Color{ 1,1,1,1 });
    playerAndZombieAnim->Draw(x + 500, y - 150, 0.f, scale, rotation, Color{ 1,1,1,1 });
    buttonPunchAnim->Draw(x - 500, y - 110, 0.f, scale, rotation, Color{ 1,1,1,1 });
}

// -------------------------------------------------------------------------------
