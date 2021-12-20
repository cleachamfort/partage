#pragma once
/* une classe : on veut cacher des choses au monde exterieur */ 
/* 3 mots clés : private, public, protected */
/*on peut en mettre autant qu'on veut*/

class CSnake
{
private:  /* philosophie de programmation : c'est là qu'on définit les attributs */  
    /* data */
    int _x = 0;
    int _y = 0;
    int _colour = 0;
    int _direction=0;

/* convention : le constructeur et le destructeur ne retournent pas de type, on les repère car ils portent le nom de la classe*/
public: /* on ne définit pas des attributs dans public*/
    CSnake(/* args */);
    ~CSnake();
    void deplacer();
    void change_direction(int direction);

public:
    void change_colour();

/* protected : accessible aux classes dérivées */ 
};