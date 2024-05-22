#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Matrix {
private:
    vector<vector<T>> data;

public:
    Matrix(int rows, int cols) : data(rows, vector<T>(cols)) {}

    // Метод для введення значень матриці
    void inputMatrix() {
        cout << "Enter matrix elements row by row:" << endl;
        for (size_t i = 0; i < data.size(); ++i) {
            cout << "Row " << i + 1 << ": ";
            for (size_t j = 0; j < data[i].size(); ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Метод для визначення кількості рядків, де елементи розташовані по зростанню
    int countIncreasingRows() {
        int count = 0;
        for (const auto& row : data) {
            bool increasing = true;
            for (size_t i = 1; i < row.size(); ++i) {
                if (row[i] <= row[i - 1]) {  // Перевіряємо чи елементи рядка розташовані по зростанню
                    increasing = false;
                    break;
                }
            }
            if (increasing) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    Matrix<int> matrix(rows, cols);  // Використовуємо тип int для матриці
    matrix.inputMatrix();

    int increasingRows = matrix.countIncreasingRows();
    cout << "Number of rows with elements in increasing order: " << increasingRows << endl;

    return 0;
}
