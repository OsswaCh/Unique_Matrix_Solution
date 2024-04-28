#include "matrix.h"
#include <iostream>

// constructors
matrix::matrix(int n) : rows(n), cols(n)
{
    this->data = new double *[n];
    for (int i = 0; i < n; i++)
    {
        this->data[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            // initialize all elements to 0
            this->data[i][j] = 0;
        }
    }
}
matrix::matrix(int n, double **data) : rows(n), cols(n)
{
    this->data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        this->data[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            this->data[i][j] = data[i][j];
        }
    }
}

// making a matrix from an old  matrix
matrix::matrix(const matrix &m) : rows(m.rows), cols(m.cols)
{
    this->data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        this->data[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            // fill the new matrix with the data from the input
            this->data[i][j] = m.data[i][j];
        }
    }
}

// destructor
matrix::~matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;
}

// setters
void matrix::setMatrix(int **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            this->data[i][j] = matrix[i][j];
        }
    }
}

void matrix::setMatrix(int n, double **data)
{
    this->rows = rows;
    this->cols = cols;
    this->data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        this->data[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            this->data[i][j] = data[i][j];
        }
    }
}

void matrix::set_Data(int i, int j, double value)
{
    this->data[i][j] = value;
}

// overloaded operators
matrix matrix::operator+(const matrix &m) const
{
    matrix result(rows);
    if (rows == m.rows && cols == m.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = this->data[i][j] + m.data[i][j];
            }
        }
    }
    else
    {
        std::cout << "The matrices are not the same size" << std::endl;
    }
    return result;
}

matrix matrix::operator-(const matrix &m) const
{
    matrix result(rows);
    if (rows == m.rows && cols == m.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = this->data[i][j] - m.data[i][j];
            }
        }
    }
    else
    {
        std::cout << "The matrices are not the same size" << std::endl;
    }
    return result;
}

matrix matrix::operator*(const matrix &m) const
{
    matrix result(rows);
    if (cols == m.rows)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    result.data[i][j] += this->data[i][k] * m.data[k][j];
                }
            }
        }
    }
    else
    {
        std::cout << "The matrices are not the same size" << std::endl;
    }
    return result;
}

// getters
int **matrix::getMatrix() const
{
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = this->data[i][j];
        }
    }

    return matrix;
}

int matrix::get_Data(int i, int j) const
{
    return this->data[i][j];
}

void matrix::print_Matrix() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << this->data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double matrix::calulate_Determinant(int n, const matrix &mat) const
{
    if (n == 1)
    {
        return mat.get_Data(0, 0);
    }
    else if (n == 2)
    {
        return mat.get_Data(0, 0) * mat.get_Data(1, 1) - mat.get_Data(0, 1) * mat.get_Data(1, 0);
    }
    else
    {
        int sign = 1;
        int det = 0;

        for (int i = 0; i < n; i++)
        {
            matrix cofac(n - 1);
            int cofac_row = 0, cofac_col = 0;

            for (int j = 1; j < n; j++)
            {
                cofac_col = 0;
                for (int k = 0; k < n; k++)
                {
                    if (k != i)
                    {
                        cofac.set_Data(cofac_row, cofac_col, mat.get_Data(j, k));
                        cofac_col++;
                    }
                }
                cofac_row++;
            }

            det += sign * mat.get_Data(0, i) * calulate_Determinant(n - 1, cofac);
            sign = -sign;
        }
        return det;
    }
}

// using Cramer's rule to solve the linear equation
double *matrix::solve_Linear_Equation(double *coef) const
{
    double *result = new double[rows];
    double det = calulate_Determinant(rows, *this);

    if (det == 0)
    {
        std::cout << "Determinant is zero, cannot solve the system." << std::endl;
        delete[] result;
        return nullptr;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix temp(*this); // Create a copy of the original matrix

        for (int j = 0; j < rows; j++)
        {
            temp.set_Data(j, i, coef[j]); // Set the value in the ith column to coef[j]
        }

        double sub_det = calulate_Determinant(rows, temp);
        result[i] = sub_det / det;
    }

    return result;
}