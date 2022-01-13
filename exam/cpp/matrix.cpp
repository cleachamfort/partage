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

Matrix::Matrix(int nligne, int ncolonne, int valeur): m_nligne(nligne), m_ncolonne(ncolonne), tab(nligne*ncolonne, valeur)
{
    
}

/* construire une matrice à partir d'une ligne */

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

/* produit d'une matrice par un entier */
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

/* produit de deux matrices */
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

/* transpose une matrice */
Matrix Matrix::transpose() const
{
    int n=m_nligne;
    int m=m_ncolonne;
    std::vector <int> liste;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            liste.push_back(getv(j,i));
        }
    }
    Matrix transpose(m,n,liste);
    return(transpose);

}
/* norme matricielle */



int Matrix::norme(Matrix mat){
    int n=m_nligne;
    int m=m_ncolonne;
    int norme2=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            norme2=norme2+mat(i,j);
        }
    }
    return(sqrt(norme2));
}
/* extrait une ligne et renvoie le vecteur colonne */
Matrix Matrix::ligne(int i){
    int n=m_nligne;
    int m=m_ncolonne;
    std::vector<int> tab;
    for (int j=0; j<m; j++){
        tab.push_back(getv(i,j));
    }
    return(Matrix(n,1,tab));
}

Matrix Matrix::colonne(const Matrix mat){
    int n=m_nligne;
    for (int i=0; i<n; i++){
        mat.tab.push_back(getv(i,1));
    }
    return(mat);
}


// Matrix Matrix::solve( Matrix A, Matrix b, Matrix x0){
//     Matrix r=b-A*x0;
//     Matrix p=r;
//     int k=0;
//     while (norme(r) !=0){
//         Matrix num=r.transpose()*r;
//         int den=(p.transpose()*A*p);
//         Matrix a=num / den ;

//     }
// }