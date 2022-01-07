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
    
}

Matrix::Matrix(int nligne, int ncolonne, std::vector <int> liste){
    m_nligne=nligne;
    m_ncolonne=ncolonne;
    for (int i=0; i< nligne*ncolonne; i++){
        tab.push_back(liste[i]);
    }


}

Matrix::~Matrix()
{

}

std::vector <int> Matrix::getTab() {return tab;}

/*opérateurs*/

/* permet d'accéder à l'élement (i,j) de la matrice */
int Matrix::getv(int i, int j) const
{
    int n=m_nligne;
    int m=m_ncolonne;
    int indc=m*i +j;
    int res=tab[indc];
    return(res);
}

int Matrix::operator()(int i,int j) const{
    return(getv(i,j));
}

void Matrix::print() const{
    int n=m_nligne;
    int m=m_ncolonne;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            std::cout << getv(i,j) << "  ";
        }
        std::cout << std::endl;
    }
}
Matrix Matrix::operator+(const Matrix &mat) const 
{
    int n=m_nligne;
    int m=m_ncolonne;

    Matrix res(n, m, 0);
    for (int i=0; i<n*m; i++)
    {
        res.tab [i] =tab[i]+mat.tab[i];
        
    }
    return(res);

}

Matrix Matrix::operator-(const Matrix &mat) const
{
    int n=m_nligne;
    int m=m_ncolonne;

    Matrix res(n, m, 0);
    for (int i=0; i<n*m; i++)
    {
        res.tab [i] =tab[i]-mat.tab[i];
        

    }
    return(res);
}

Matrix Matrix::operator*(int entier) const
{
    int n=m_nligne;
    int m=m_ncolonne;

    Matrix res(n, m, 0);
    for (int i=0; i<n*m; i++)
    {
        res.tab [i] =entier * tab[i];
        

    }
    return(res);
}

Matrix Matrix::operator*(Matrix mat) const
{
    int n1=m_nligne;
    int m1=m_ncolonne;
    int n2=mat.m_nligne;
    int m2=mat.m_ncolonne;
    assert (m1==n2);
    std::vector <int> liste;
    
    
    
    
    for (int i=0; i<n1; i++ ){
        for (int j=0; j<m2; j++){
            int S=0;
            for (int k=0; k<m1; k++){
                S=S+ getv(i,k)* mat(k,j) ;}
                
            liste.push_back(S);
            }
    
    }  
    Matrix res(n1,m2,liste);  
    return(res);
}