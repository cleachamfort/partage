#include "CSnakeSegment.h"

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