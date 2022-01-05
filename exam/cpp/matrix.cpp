#include "matrix.h"
#include <vector>
#include <cassert>
#include <iostream>

/* constructeurs et destructeur */
Matrix::Matrix()
{

}

Matrix::Matrix(int nligne, int ncolonne, int valeur): m_nligne(nligne), m_ncolonne(ncolonne), tab(nligne*ncolonne, valeur)
{
    int n=nligne;
    int m=ncolonne;
}

Matrix::~Matrix()
{

}

std::vector <int> Matrix::getTab() {return tab;}

/*opérateurs*/

/* permet d'accéder à l'élement (i,j) de la matrice */
int Matrix::operator()(int i, int j)
{
    int n=m_nligne;
    int m=m_ncolonne;
    int indc=m*i +j;
    int res=tab[indc];
    return(res);
}

void Matrix::print() const{
    int n=m_nligne;
    int m=m_ncolonne;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            std::cout << *this(i,j) << std::endl;
        }
    }
}
Matrix Matrix::operator+(const Matrix &mat) 
{
    int n=m_nligne;
    int m=m_ncolonne;

    Matrix res(n, m, 0);
    for (int i=0; i<n; i++)
    {
        res.tab [i] =tab[i]+mat.tab[i];
        return(res);

    }

}

Matrix Matrix::operator-(const Matrix &mat) 
{
    int n=m_nligne;
    int m=m_ncolonne;

    Matrix res(n, m, 0);
    for (int i=0; i<n; i++)
    {
        res.tab [i] =tab[i]-mat.tab[i];
        return(res);

    }

}

Matrix Matrix::operator*(int entier) 
{
    int n=m_nligne;
    int m=m_ncolonne;

    Matrix res(n, m, 0);
    for (int i=0; i<n; i++)
    {
        res.tab [i] =entier * tab[i];
        return(res);

    }

}

Matrix Matrix::operator*(Matrix mat) 
{
    int n1=m_nligne;
    int m1=m_ncolonne;
    int n2=mat.m_nligne;
    int m2=mat.m_ncolonne;
    assert (m1==n2);
    Matrix res(n1,m2,0);
    
    int S=0;
    int compteur=0;
    for (int i=0; i<n1; i++ ){
        for (int j=0; j<m2; j++){
            
            for (int k=0; k<m1; k++){
                int value=mat(k,j);
                S=S+ *this(i,k)* value ;}
            }
            res.tab [compteur]=S;
            compteur++;
        }    
    return(res);
}