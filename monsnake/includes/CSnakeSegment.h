#pragma once
/* une classe : on veut cacher des choses au monde exterieur */ 
/* 3 mots clés : private, public, protected */
/*on peut en mettre autant qu'on veut*/

class CSnakeSegment
{
private:  /* philosophie de programmation : c'est là qu'on définit les attributs */  
    /* data */
    int _x = 0;
    int _y = 0;
    int _colour = 0;

/* convention : le constructeur et le destructeur ne retournent pas de type, on les repère car ils portent le nom de la classe*/
public: /* on ne définit pas des attributs dans public*/
    CSnakeSegment(/* args */);
    ~CSnakeSegment();

public:
    void change_colour();

/* protected : accessible aux classes dérivées */ 
};