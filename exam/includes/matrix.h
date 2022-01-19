#pragma once 
#include <vector>

class Matrix
{

private:
    /* la taille et la liste (à une dimension pour simplifier ) */
    int m_ncolonne;
    int m_nligne;
    std::vector <float> tab;

public:
    /* constructeurs et destructeur */
    Matrix();
    Matrix(int nligne, int ncolonne, float valeur);
    Matrix(int nligne, int ncolonne, std::vector <float> liste);
    ~Matrix();
    /* opérateurs */
    float getv(int i, int j) const;
    float operator()(int i, int j) const;
    void print() const;
    void set(int i, int j, float valeur);
    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(float scalaire) const;
    Matrix operator*(const Matrix mat) const;
    /* question 2 */
    Matrix transpose() const;
    Matrix ligne(int i);
    float norme();
    void Id();
    Matrix colonne(const Matrix mat);
    float convert();

    /* get */
    std::vector <int> getTab();
    int getn_ligne();
    


};
