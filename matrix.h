#pragma once

class matrix
{

private:
    int rows;
    int cols;
    double **data;

public:
    // 3 options to initialize a matrix object
    matrix(int rows, int cols);
    matrix(int rows, int cols, double **data);
    matrix(const matrix &m);

    // destructor
    ~matrix();

    // getters
    int **getMatrix() const;
    int calulate_Determinant() const;
    int *solve_Linear_Equation() const;

    // setters
    void setMatrix(int **matrix);
    void setMatrix(int rows, int cols, double **data);

    // overloaded operators
    matrix operator+(const matrix &m) const;
    matrix operator-(const matrix &m) const;
    matrix operator*(const matrix &m) const;
};