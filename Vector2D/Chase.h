/**********************************************************************************
// Presence (Arquivo de Cabeçalho)
//
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
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

    void Update();                              // atualização
    void Draw();                                // desenho
    void OnCollision(Object* obj);     // resolução da colisão
};

// ------------------------------------------------------------------------------

#endif