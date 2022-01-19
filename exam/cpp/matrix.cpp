#include "matrix.h"
#include "math.h"
#include <vector>
#include <cassert>
#include <iostream>

/* constructeurs et destructeur */
Matrix::Matrix()
{

}

/* construire une matrice remplie d'une unique valeur */

Matrix::Matrix(int nligne, int ncolonne, float valeur): m_nligne(nligne), m_ncolonne(ncolonne), tab(nligne*ncolonne, valeur)
{
    
}

/* construire une matrice à partir d'une ligne */

Matrix::Matrix(int nligne, int ncolonne, std::vector <float> liste){
    m_nligne=nligne;
    m_ncolonne=ncolonne;
    for (int i=0; i< nligne*ncolonne; i++){
        tab.push_back(liste[i]);
    }


}

Matrix::~Matrix()
{

}



int Matrix::getn_ligne(){return m_nligne;}

/*opérateurs*/

/* permet d'accéder à l'élement (i,j) de la matrice */
float Matrix::getv(int i, int j) const
{
    int n=m_nligne;
    int m=m_ncolonne;
    int indc=m*i +j;
    int res=tab[indc];
    return(res);
}

float Matrix::operator()(int i,int j) const{
    return(getv(i,j));
}

/*permet d'afficher la matrice */
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

/* fait un changement de valeur */
void Matrix::set(int i, int j, float valeur){
    int n=m_nligne;
    int m=m_ncolonne;
    int indc=m*i +j;
    tab[indc]=valeur;
}

/* somme de deux matrices */
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
/* différence de deux matrices */
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

/* produit d'une matrice par un scalaire */
Matrix Matrix::operator*(float scalaire) const
{
    int n=m_nligne;
    int m=m_ncolonne;

    Matrix res(n, m, 0);
    for (int i=0; i<n*m; i++)
    {
        res.tab [i] = scalaire * tab[i];
        

    }
    return(res);
}

/* produit de deux matrices */
Matrix Matrix::operator*(Matrix mat) const
{
    int n1=m_nligne;
    int m1=m_ncolonne;
    int n2=mat.m_nligne;
    int m2=mat.m_ncolonne;
    assert (m1==n2);
    std::vector <float> liste;
    
    
    
    
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

/* transpose une matrice */
Matrix Matrix::transpose() const
{
    int n=m_nligne;
    int m=m_ncolonne;
    std::vector <float> liste;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            liste.push_back(getv(j,i));
        }
    }
    Matrix transpose(m,n,liste);
    return(transpose);

}

/* extrait une ligne */
Matrix Matrix::ligne(int i){
    int n=m_nligne;
    int m=m_ncolonne;
    std::vector<float> tab;
    for (int j=0; j<m; j++){
        tab.push_back(getv(i,j));
    }
    return(Matrix(1,m,tab));
}

/* la matrice courante est une matrice identité */
void Matrix::Id(){
    int n=m_nligne;
    int m=m_ncolonne;
    for (int i=0; i<n*m; i++){
        tab[i]=0;

    }
    for (int i=0; i<n; i++){
        tab[i+m*i]=1;
    }
}

/* prend une matrice (1,1) et renvoie l'entier correspondant */
float Matrix::convert(){
    return(getv(0,0));
}


/* norme matricielle */



float Matrix::norme(){
    int n=m_nligne;
    int m=m_ncolonne;
    int norme2=0;
    for (int i=0; i<n; i++){                                                                                                                                                                    
        for (int j=0; j<m; j++){
            norme2=norme2+getv(i,j);
        }
    }
    return(sqrt(norme2));
}