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
        float num=(r.transpose()*r).convert();
        float den=((p.transpose()*A*p)).convert();
        float div=1/den;
        float alpha=num * div ;
        x=x+p*alpha;
        Matrix r_prec=r;
        r=r-A*p*alpha;
        float div2=(r_prec.transpose()*r_prec).convert();
        float beta= (r.transpose()*r).convert() *  1 / div2  ;
        Matrix p= r + p* beta;
        x.print();

    }
    return(x);
    
}