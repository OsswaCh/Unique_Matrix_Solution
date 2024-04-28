#pragma once

class matrix
{

private:
    int rows;
    int cols;
    double **data;

public:
    // 3 options to initialize a matrix object
    matrix(int);
    matrix(int, double **);
    matrix(const matrix &);

    // destructor
    ~matrix();

    // getters
    int **getMatrix() const;
    double calulate_Determinant(int, const matrix &) const;
    double *solve_Linear_Equation(double *) const;
    int get_Data(int, int) const;
    void print_Matrix() const;

    // setters
    void setMatrix(int **);
    void setMatrix(int, double **);
    void set_Data(int, int, double);

    // overloaded operators
    matrix operator+(const matrix &) const;
    matrix operator-(const matrix &) const;
    matrix operator*(const matrix &) const;
};