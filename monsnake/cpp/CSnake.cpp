#include "CSnake.h"
#include <vector>


/* le constructeur initialise l'univers (une sorte d'init automatique) et le destructeur permet de faire le ménage */ 
/* le constructeur peut être vide */ 
CSnake::CSnake(/* args */)
{
    _x=1;
}

CSnake::~CSnake()
{
}

void CSnake::change_colour()
{
    _colour++;
}


void snake_init()
{

int counter=0;
for (counter; counter<6; counter++) {
    snake[counter]={counter,0};
};
}


void CSnake::deplacer(){
    if (_direction==0){
        snake.pop_back();
        snake.push_back({snake[5].first()+1,snake[5].second()});
    }
    else if (_direction==1){
        snake.pop_back();
        snake.push_back({snake[5].first()-1,snake[5].second()});
    }
    else if (_direction==2){
        snake.pop_back();
        snake.push_back({snake[5].first(),snake[5].second()+1});
    }
    else if (_direction==3){
        snake.pop_back();
        snake.push_back({snake[5].first(),snake[5].second()-1});
    }

}

void CSnake::change_direction(int consigne){
    
        if (consigne==3)
        {
            snake.pop_back();
            snake.push_back({snake[5].first(),snake[5].second()-1);
            _direction=3;
        }
        else if (consigne=2)
        {
            snake.pop_back();
            snake.push_back({snake[5].first(),snake[5].second()+1);
            _direction=2;
        }
        else if (consigne==1)
        {
            snake.pop_back();
            snake.push_back({snake[5].first()-1,snake[5].second());
            _direction=1;
        }
        else if (consigne==0)
        {
            snake.pop_back();
            snake.push_back({snake[5].first()+1,snake[5].second());
            _direction=0;
        }


}
