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
    ~Matrix();
    /* opérateurs */
    int operator()(int i, int j);
    Matrix operator+(const Matrix &mat);
    Matrix operator-(const Matrix &mat);
    Matrix operator*(int entier);
    Matrix operator*(const Matrix &mat);
    /* get */
    std::vector <int> getTab();
    


};
