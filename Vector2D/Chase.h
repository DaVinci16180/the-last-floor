/**********************************************************************************
// Presence (Arquivo de Cabe�alho)
//
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#ifndef _CHASE_H_
#define _CHASE_H_

// --------------------------------------------------------------------------------

#include "Object.h"     
#include "Zombie.h"
// objetos do jogo 

// --------------------------------------------------------------------------------

class Chase : public Object
{
private:
    Zombie* zombie;
public:
    Chase(Zombie* z);        // construtor
    ~Chase();                                 // destrutor

    void Update();                              // atualiza��o
    void Draw();                                // desenho
    void OnCollision(Object* obj);     // resolu��o da colis�o
};

// ------------------------------------------------------------------------------

#endif