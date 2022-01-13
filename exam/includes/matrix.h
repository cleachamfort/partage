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
    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(int entier) const;
    Matrix operator*(const Matrix mat) const;
    /* question 2 */
    Matrix transpose() const;
    Matrix ligne(int i);
    int norme(Matrix mat);
    Matrix solve(Matrix A, Matrix b, Matrix x0) ;
    Matrix Id(int n);
    Matrix colonne(const Matrix mat);

    /* get */
    std::vector <int> getTab();
    


};
