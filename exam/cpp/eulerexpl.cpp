
# include "matrix.h"
#include "eulerexpl.h"
# include <vector>
# include <math.h>
# include <iostream>
#include <fstream>
#define M_PI 3.14159265358979323846

Matrix constr_X(int N){
std::vector <int> tab;

for (int i=0; i<N; i++){
        tab.push_back(i * 1/ N) ; /* delta_x=1/N */
    }
    Matrix X= Matrix(1,N,tab);
    X.print();
    return(X);
}

Matrix constr_K(int M){
Matrix K=Matrix(M,M,0);
    for (int i=0; i<M; i++){
        
            K.set(i,i,-2);
            K.set(i,i-1,1);
            K.set(i,i+1,1);
        
    }
    return(K* M*M);
}



void calcul_euler_expl(int N, int dt, int M ){ /* N est le pas de discrétisation en temps et M celui d'espace */

Matrix K=constr_K(N);

/*construction de T0*/

Matrix Id(N,N,0);
Id.Id();

Matrix T0(N, 1, 0);
for (int i=0; i<N; i++){
    T0.set(i,1,(1/2+sin(2*M_PI*constr_X(N)(i,1))));
}

/* itération */
std::vector <Matrix> T;

Matrix T2=T0;
for (int k=0; k<M; k++){

    T.push_back(T2);
    
    std::ofstream txt;
    txt.open("../src/temperature.csv");

    for (unsigned int i = 0; i < M-1 ; i++)
        { 
            txt << T2(1,i) << ";";       
        }

        txt <<T2(1,M-1)<< std::endl;

    T2=(Id -K*dt)* T2;
    }

}
