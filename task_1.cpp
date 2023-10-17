/* Option 12 */
#include <iostream>
#include <cstring>

class Matrix
{
    int m_row;
    int m_column;
    int** m_matrix;

public:
    Matrix(int row, int column)
    {
        m_row = row;
        m_column = column;
        m_matrix = new int*[m_row];
        for (int i{}; i < m_row; ++i)
            m_matrix[i] = new int[m_column];

        for (int i{}; i < m_row; ++i)
            for (int j{}; j < m_column; ++j)
                std::cin >> m_matrix[i][j];
    }

    Matrix(int size)
    {
        m_row = size;
        m_column = size;
        m_matrix = new int*[m_row];
        for (int i{}; i < m_row; ++i)
            m_matrix[i] = new int[m_column];

        for (int i{}; i < m_row; ++i)
            for (int j{}; j < m_column; ++j)
                std::cin >> m_matrix[i][j];
    }

    ~Matrix()
    {
        for (int i{}; i < m_row; ++i)
            delete[] m_matrix[i];
        delete[] m_matrix;
    }

    void printMatrix(int rowQuantity, int columnsQuantity)
    {
        for (int i{}; i < rowQuantity; ++i)
        {
            for (int j{}; j < columnsQuantity; ++j)
                std::cout << m_matrix[i][j] << "\t";
            std::cout << std::endl;
        }
    }

    void resizeMatrix(int rowChange, int columnChange)
    {
        if (rowChange < m_row)
        {
            for (int i = rowChange; i < m_row; ++i)
                delete[] m_matrix[i];
            m_row = rowChange;
        }
        else if (rowChange >= m_row)
        {
            for (int i = m_row; i < rowChange; ++i)
                m_matrix[i] = new int[m_column];

            for (int i = m_row; i < rowChange; ++i)
                for (int j{}; j < m_column; ++j)
                    std::cin >> m_matrix[i][j];
            m_row = rowChange;
        }
        else
        {
            for (int i{}; i < m_row; ++i)
            {
                int *temporary = new int[columnChange];
                memcpy(temporary, m_matrix[i], columnChange * sizeof(int));
                delete[] m_matrix[i];
                m_matrix[i] = temporary;
            }
            if (columnChange >= m_column)
                for (int i{}; i < m_row; ++i)
                    for (int j = m_column; j < columnChange; ++j)
                        std::cin >> m_matrix[i][j];
            m_column = columnChange;
        }
    }
};

int main()
{
    int executionStatus{}, rows, columns;
    std::cin >> rows >> columns;
    Matrix example {rows, columns};
    do
    {
        std::cout << "Please, choose method to work with:\n";
        std::cout << "1) Print matrix (or submatrix).<rows, columns>\n";
        std::cout << "2) Resize matrix.<new rows, new columns>\n";
        std::cin >> executionStatus >> rows >> columns;
        switch (executionStatus)
        {
            case 1:
                example.printMatrix(rows, columns);
            case 2:
                example.resizeMatrix(rows, columns);
        }
    } while (executionStatus != 0);
    return 0;
}