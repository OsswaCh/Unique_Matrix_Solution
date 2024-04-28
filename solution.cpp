#include <iostream>
#include "matrix.cpp"

int main()
{
    int choice;
    std::cout << "so you want to " << std::endl
              << "1.solve the excercices" << std::endl
              << "2.solve a new matrix" << std::endl;
    std::cin >> choice;
    if (choice == 1)
    {

        std::cout << "Exercise 25: " << std::endl;
        double input[4][4] = {{3, -2, 9, 4}, {-1, 0, -9, -6}, {0, 0, 3, 1}, {2, 2, 0, 8}};

        double **data = new double *[4];
        for (int i = 0; i < 4; i++)
        {
            data[i] = new double[4];
        }

        // fill data with input
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                data[i][j] = input[i][j];
            }
        }
        // output the data in the matrix
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        matrix m1(4, (double **)data);
        // print the determinant of the matrix
        std::cout << "Determinant: " << m1.calulate_Determinant(4, m1) << std::endl;

        double constants[4] = {35, -17, 5, -4};
        double *solution = m1.solve_Linear_Equation(constants);

        std::cout << "Solution using Cramer's rule: ";
        for (int i = 0; i < 4; i++)
        {
            std::cout << solution[i] << " ";
        }

        ////////////////excercie 26///////////////
        std::cout << "Exercise 26: " << std::endl;
        double input2[4][4] = {{-1, -1, 0, 1}, {3, 5, 5, 0}, {0, 0, 2, 1}, {-2, -3, -3, 0}};

        double **data2 = new double *[4];
        for (int i = 0; i < 4; i++)
        {
            data2[i] = new double[4];
        }

        // fill data2 with input2
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                data2[i][j] = input2[i][j];
            }
        }
        // output the data2 in the matrix
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cout << data2[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        matrix m2(4, (double **)data2);
        // print the determinant of the matrix
        std::cout << "Determinant: " << m2.calulate_Determinant(4, m2) << std::endl;

        double constants2[4] = {-8, 24, -6, -15};
        double *solution2 = m2.solve_Linear_Equation(constants2);

        std::cout << "Solution using Cramer's rule: ";
        for (int i = 0; i < 4; i++)
        {
            std::cout << solution2[i] << " ";
        }
    }

    else if (choice == 2)
    {

        int size;
        std::cout << "Enter the size of the matrix: ";
        std::cin >> size;
        double **data = new double *[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = new double[size];
        }
        // use input to fill the matrix
        std::cout << "Enter the elements of the matrix going row by row: " << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << "Enter the element at position (" << i << "," << j << "): ";
                std::cin >> data[i][j];
            }
        }
        // output the data in the matrix
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        // solve the matrix
        matrix m(size, (double **)data);
        // print the determinant of the matrix
        std::cout << "Determinant: " << m.calulate_Determinant(size, m) << std::endl;
        double *constants = new double[size];
        std::cout << "Enter the constants of the linear equation: " << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << "Enter the constant at position (" << i << "): ";
            std::cin >> constants[i];
        }
        double *solution2 = m.solve_Linear_Equation(constants);
        // print the solution
        std::cout << "Solution using Cramer's rule: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << solution2[i] << " ";
        }
    }

    else
    {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}