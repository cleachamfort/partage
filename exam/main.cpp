#include <iostream>
#include <vector>
#include <cmath>
/*j'ai une erreur ici : */
#include "matrix.h"




int main(int, char**) {
    std::cout << "Hello, world!\n";
}

/* Question1 */
int test_operateurs()
{
   Matrix m1(3,3,0);
   Matrix m2(3,3,1);

   m2.print();
   
   
    std::cout << m2(0,0) << std::endl;
    return(0);

}

