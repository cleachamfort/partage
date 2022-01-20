
# include "matrix.h"
#include "eulerexpl.h"
# include <vector>
# include <math.h>
# include <iostream>
#include <fstream>
#define M_PI 3.14159265358979323846

// Matrix constr_X(float N){
// std::vector <float> tab;
// float a;
// for (int i=0; i<N; i++){
//         a=float(i / N);
//         tab.push_back(a) ; /* delta_x=1/N */
//     }
//     Matrix X= Matrix(1,N,tab);
//     std::cout << "X " << std::endl;
//     X.print();
//     return(X);
// }

Matrix constr_K(float dx){
float M=1/dx;
Matrix K=Matrix(M,M,0);
    for (int i=1; i<M-1; i++){
        
            K.set(i,i,-2);
            K.set(i,i-1,1);
            K.set(i,i+1,1);
        
    }
    K.set(0,0,-2);
    K.set(0,1,0);
    K.set(M-1,M-1, -2);
    K.set(M-1,M-2,0);
    (K * M*M).print();  
    return(K* M*M);
}



void calcul_euler_expl(float dt, float dx ){ /* N est le pas de discrétisation en temps et M celui d'espace */
float N=1/dt;
float M=1/dx;
Matrix K=constr_K(dx);

/*construction de T0*/

Matrix Id(M,M,0);
Id.Id();

Matrix T0(M, 1, 0);
for (int i=0; i<M; i++){
    float a=1/2+sin(2*M_PI*i/N)-1/2*cos(2*M_PI*i/N);
    T0.set(i,0,a);
}
std::cout << "T0 = " ;

/* itération */


Matrix T2=T0;
std::ofstream txt;

txt.open("../src/temperature.csv");
Matrix A=(Id -K*dt);
A.print();
for (int k=0; k<N; k++){
    for (unsigned int i = 0; i < M-1 ; i++)
        { 
            txt << T2(i,0) << ",";       
        }

    txt <<T2(M-1,0) <<  "\n ";
    
    T2=A*T2;
    }

}
