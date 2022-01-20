# include "matrix.h"
#include "eulerexpl.h"
# include <vector>
# include <math.h>
# include <iostream>
#include <fstream>

Matrix solve( Matrix A, Matrix b, Matrix x0){
    Matrix r(b.getn_ligne(),1,0);
    r=b-A*x0;
    Matrix p=r;
    int k=0;
    Matrix x=x0;
    while (r.norme() > 0.00001){
        float alpha=(r.transpose()*r).convert() / ((p.transpose()*A*p)).convert() ;
        x=x+p*alpha;
        
        Matrix r1=r-(A*p*alpha);
        
        float beta= (r1.transpose()*r1).convert() / (r.transpose()*r).convert()  ;
        Matrix p= r1 + p* beta;
        r=r1;

        

    }
    return(x);
    
}