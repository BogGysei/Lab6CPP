#include <iostream>
#include <vector>
#include<Windows.h>
using namespace std;

class Matrix {
private:

    int rows;
    int cols;

public:
    vector<vector<int>> data;

    Matrix() : rows(0), cols(0) {}


    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(r, vector<int>(c, 0));
    }

    Matrix add(Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Розміри матриць не співпадають!" << endl;
            return Matrix();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix divide(int divisor) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] / divisor;
            }
        }
        return result;
    }

    bool isEqual(Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    int choice;
    int rows, cols;
    cout << "Введіть кількість рядків та стовпців матриць: ";
    cin >> rows >> cols;

    Matrix matrix1(rows, cols);
    Matrix matrix2(rows, cols);

    cout << "Введіть елементи першої матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix1.data[i][j];
        }
    }

    cout << "Введіть елементи другої матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix2.data[i][j];
        }
    }

    cout << "Оберіть операцію:" << endl;
    cout << "1. Додавання матриць" << endl;
    cout << "2. Обчислення частки матриці на число" << endl;
    cout << "3. Порівняння матриць" << endl;
    cin >> choice;

    Matrix result;
    switch (choice) {
    case 1:
        result = matrix1.add(matrix2);
        cout << "Результат додавання:" << endl;
        result.print();
        break;
    case 2:
        int divisor;
        cout << "Введіть число, на яке потрібно поділити матрицю: ";
        cin >> divisor;
        result = matrix1.divide(divisor);
        cout << "Результат обчислення частки:" << endl;
        result.print();
        break;
    case 3:
        if (matrix1.isEqual(matrix2)) {
            cout << "Матриці рівні" << endl;
        }
        else {
            cout << "Матриці не рівні" << endl;
        }
        break;
    default:
        cout << "Неправильний вибір операції!" << endl;
    }
}
