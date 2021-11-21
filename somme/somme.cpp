#include <iostream>


int main(int argc, char** argv){

    int somme=0;
    int i=1;

    for (; i<argc; i++  ){
    somme=somme + atoi(argv[i]); /*convertit la chaine de caractère en entier */
    }

    std::cout<< somme <<std::endl;

    return(0);
}
