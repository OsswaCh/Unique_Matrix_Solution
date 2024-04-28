#include "matrix.h"
#include <iostream>
#include <cmath>

// constructors
matrix::matrix(int rows, int cols) : rows(rows), cols(cols)
{
    this->data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        this->data[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            // initialize all elements to 0
            this->data[i][j] = 0;
        }
    }
}

matrix::matrix(int rows, int cols, double **data) : rows(rows), cols(cols)
{
    this->data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        this->data[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            // fill the new matrix with the data from the input
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

void matrix::setMatrix(int rows, int cols, double **data)
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

// overloaded operators
matrix matrix::operator+(const matrix &m) const
{
    matrix result(rows, cols);
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
    matrix result(rows, cols);
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
    matrix result(rows, m.cols);
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
