#include "ConsoleApplication.h"
#include <iostream>
#include "Number.h"
#include "SquareMatrix.h"
#include <iomanip>

int ConsoleApplication::exec()
{

    SquareMatrix matrix(2);

    while(true)
    {

        int n = menu();

        std::cout << std::setw(10 * matrix.getN() + 2 + matrix.getN()) << std::setfill('-') << "" << std::endl;
        
        switch(n)
        {
        case 0:
            return 0;

        case 1:
            //заполнение матрицы значениями
            for (int i = 0; i < matrix.getN(); i++) {
                for (int j = 0; j < matrix.getN(); j++) {
                    std::cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
                    std::cin >> *matrix.getCell(i, j);
                }
            }

            break;

        case 2:
         
            std::cout << "The determinant of the matrix is " << matrix.determinant() << std::endl;
            break;

        case 3:
        {
            SquareMatrix* transporeMatrix = matrix.transpore();
            std::cout << *transporeMatrix << std::endl;
            delete transporeMatrix;
        }
            break;

        case 4:
            std::cout << "The rank of the matrix is " << matrix.rang() << std::endl;
            break;

        case 5:
            std::cout << matrix << std::endl;
            break;

        default:
            std::cout << "Error: the entered command does not exist!" << std::endl;
            break;
        }
        std::cout << std::setw(10 * matrix.getN() + 2 + matrix.getN()) << std::setfill('-') << "" << std::endl;
    }
}

int ConsoleApplication::menu()
{

    int n = 0;

    std::cout << "List of commands:" << std::endl;
    std::cout << "1) Enter the matrix." << std::endl;
    std::cout << "2) Calculate the determinant of the matrix." << std::endl;
    std::cout << "3) To form a transposed matrix." << std::endl;
    std::cout << "4) Calculate the rank of the matrix." << std::endl;
    std::cout << "5) Output the matrix." << std::endl;
    std::cout << "0) Exit the application." << std::endl;

    std::cout << "enter the command number: ";
    std::cin >> n;

    return n;
}
