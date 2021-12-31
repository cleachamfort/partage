#include <iostream>
#include <vector>
#include <cmath>
/*j'ai une erreur ici : */
#include "matrix.h"




int main(int, char**) {
    std::cout << "Hello, world!\n";
}

/* Question1 */
void test_operateurs()
{
   Matrix m1(3,3,0);
   Matrix m2(3,3,1);

   

}

/*Question 2 */

/* matrice K */

Matrix K(N,N,0);

K.tab[0]=-2;
K.tab[1]=1
for (int i=1; i<N; i++){
    K.tab[i*(N-1)+(i+1)]=-2;
    K.tab[i*(N-1)+(i)]=1;
}

dt=
N=100;
std::vector <int> X;
for (int k=0; k<N+1; k++){
    X[k]=k/N;
}

std::vector <int> T0;
for (int k=0; k<N+1; k++){
    T[k]=1/2 + std::sin(2*pi*X[k])-1/2*std::cos(2*pi*X[k]);
}

std::vector <std::vector> Temp;
Temp[0]=T0;

M=100;

for (int k=0;k<M;k++){
    Temp[k+1]=Temp[k]-dt*K*Temp[k];
}