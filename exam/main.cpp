#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.h"

/* Question1 */
int test_operateurs()
{
   Matrix m2(3,3, {1,2,4,0,1,6,0,0,1});
   std::vector <int> liste {0,1,2,3,4,5,6,7,8};
   Matrix m3(3,3, liste);
   Matrix m4=m2*m3;
   Matrix m5=m4.transpose();

 
    std::cout << "m2 = " << std::endl;
    m2.print();
    std::cout << "m3 = " << std::endl;
    m3.print();
    std::cout << "m3(1,2) =" << m3(1,2) << std::endl;
    std::cout << "m4 = " << std::endl;
    m4.print();
    m5.print();


    return(0);

}


int main(int, char**) {
    std::cout << "Hello, world!\n";
    test_operateurs();
}
