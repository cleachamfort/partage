#pragma once 
#include <vector>

class Matrix
{

private:
    /* la taille et la liste (à une dimension pour simplifier ) */
    int m_ncolonne;
    int m_nligne;
    std::vector <int> tab;

public:
    /* constructeurs et destructeur */
    Matrix();
    Matrix(int nligne, int ncolonne, int valeur);
    Matrix(int nligne, int ncolonne, std::vector <int> liste);
    ~Matrix();
    /* opérateurs */
    int getv(int i, int j) const;
    int operator()(int i, int j) const;
    void print() const;
    void set(int i, int j, int valeur);
    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(float scalaire) const;
    Matrix operator*(const Matrix mat) const;
    /* question 2 */
    Matrix transpose() const;
    Matrix ligne(int i);
    int norme();
    void Id();
    Matrix colonne(const Matrix mat);
    float convert();

    /* get */
    std::vector <int> getTab();
    int getn_ligne();
    


};
