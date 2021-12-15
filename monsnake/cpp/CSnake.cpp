#include "CSnake.h"

/* le constructeur initialise l'univers (une sorte d'init automatique) et le destructeur permet de faire le ménage */ 
/* le constructeur peut être vide */ 
CSnakeSegment::CSnakeSegment(/* args */)
{
    _x=1;
}

CSnakeSegment::~CSnakeSegment()
{
}

void CSnakeSegment::change_colour()
{
    _colour++;
}

CSnakeSegment::deplacer(){
    if (direction==0){
        snake.pop_back();
        snake.push_back({snake[5].first()+1,snake[5].second());
    };
    else if (direction==1){
        snake.pop_back();
        snake.push_back({snake[5].first()-1,snake[5].second());
    };
    else if (direction==2){
        snake.pop_back();
        snake.push_back({snake[5].first(),snake[5].second()+1);
    };
    else if (direction==3){
        snake.pop_back();
        snake.push_back({snake[5].first(),snake[5].second()-1);
    }

}

CSnakeSegment::change_direction(int direction){
    int key_scan = keyboard_scan();
        if (key_scan == UP_ARROW)
        {
            snake.pop_back();
            snake.push_back({snake[5].first(),snake[5].second()-1);
            _direction=3
        }
        else if (key_scan == DOWN_ARROW)
        {
            snake.pop_back();
            snake.push_back({snake[5].first(),snake[5].second()+1);
            _direction=2
        }
        else if (key_scan == LEFT_ARROW)
        {
            snake.pop_back();
            snake.push_back({snake[5].first()-1,snake[5].second());
            _direction=1;
        }
        else if (key_scan == RIGHT_ARROW)
        {
            snake.pop_back();
            snake.push_back({snake[5].first()+1,snake[5].second());
            _direction=0;
        }


}
