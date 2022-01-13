# include "matrix.h"
# include <vector>

int N=100;
int M=100;
float delta_x=1/N;

std::vector<int> constr_X(int n){
std::vector <int> tab;
for (int i=0; i<n; i++){
        tab.push_back(i /delta_x) ;
    }
    return(tab);
}

Matrix constr_K(int n){
std::vector <int> tab(n*n, 0);
    for (int i=1; i<n; i++){
        tab[(n-1)*i+i]=1;
        tab[(n-1)*i+i+1]=-2;
    }
    for (int i=0; i<n-1; i++){
        tab[(n)*i+i+1]=1;
    }
    Matrix K=Matrix(n,n,tab);
    return(K);
}

std::vector<int> T0_list;

for (int i=0; i<M; i++){
    T0_list.push_back(1/2+sin(2*pi*constr_X(N)(i,1)));
}
Matrix T0= Matrix(M,1,T0_list);

Matrix Id(int a, int b){
    std::vector <int> tab(0,a*b);
    for (int i=0; i<n; i++ ){
            tab[i+b*i]=1;}
    Matrix Id = Matrix(a,b,tab);
    return(Id);
    }



Matrix T2=T0;
for (int k=0; k<N; k++){
    T_tot.colonne(T2);
    T2=(Id -dt*K)* T2;
}

