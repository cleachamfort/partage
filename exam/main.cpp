
#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.h"
#include "eulerexpl.h"
#include "solve.h"


/* Question1 */
int test_operateurs()
{
   Matrix m2(3,3, {1,2,4,0,1,6,0,0,1});
   std::vector <float> liste {0,1.1,2,3,4,5,6,7,8};
   Matrix m3(3,3, liste);
   Matrix m4=m2*m3;
   Matrix m5=m4.transpose();
   m3.set(0,0,1.2);
   Matrix m6= Matrix(1,1,2);

    std::cout << "test affichage et construction" << std::endl;
    std::cout << "m2 = " ;
    m2.print();
    std::cout << "\n";
    std::cout << "m3 = "  ;
    m3.print();
    std::cout << "\n";
    std::cout << "test affichage d'une valeur" << std::endl;
    std::cout << "m3(1,2) =" << m3(1,2) << "\n";
    std::cout << "\n";
    std::cout << "test produit de matrice" << std::endl;
    std::cout << "m4 = ";
    m4.print();
    std::cout << "\n";
    std::cout << "test transposition" << std::endl;
    std::cout << "m5 = ";
    m5.print();
    std::cout << "\n";
    std::cout << "m6 = " << m6.convert()<< "\n" ;
    



    return(0);

}

void test_inversion(){
    Matrix A(4,4,0);
    A.Id();
    A.set(0,0,2);
    Matrix b=Matrix(4, 1, {4,1,2,3});
    Matrix x0= Matrix(4, 1, {0,0,0,0});
    Matrix x = solve(A,b, x0);
    A.print();
    x.print();
    

}


int main(int, char**) {
    std::cout << "Hello, world!\n";
    test_operateurs();



    float dx=0.05;
    
    float dt=0.01;
    
    {constr_K(dx);}
    {calcul_euler_expl(dt, dx);}
    // test_inversion();

}


