
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

Matrix constr_K(float M){
Matrix K=Matrix(M,M,0);
    for (int i=1; i<M-1; i++){
        
            K.set(i,i,-2);
            K.set(i,i-1,1);
            K.set(i,i+1,1);
        
    }
    K.set(0,0,-2);
    K.set(0,1,1);
    K.set(M-1,M-1, -2);
    K.set(M-1,M-2,1);
    return(K* M*M);
}



void calcul_euler_expl(float N, float dt, float M ){ /* N est le pas de discrétisation en temps et M celui d'espace */

Matrix K=constr_K(N);

/*construction de T0*/

Matrix Id(N,N,0);
Id.Id();

Matrix T0(N, 1, 0);
for (int i=0; i<N; i++){
    float a=1/2+sin(2*M_PI*i/N)-1/2*cos(2*M_PI*i/N);
    T0.set(i,0,a);
}
std::cout << "T0 = " ;
T0.print();

/* itération */
std::vector <Matrix> T;

Matrix T2=T0;
std::ofstream txt;

txt.open("../src/temperature.csv");
for (int k=0; k<M; k++){

    T.push_back(T2);
    
    

    for (unsigned int i = 0; i < M-1 ; i++)
        { 
            txt << T2(1,i) << ";";       
        }

    txt <<T2(1,M-1) << "stop"<< "\n ";

    T2=(Id -K*dt)* T2;
    }

}
