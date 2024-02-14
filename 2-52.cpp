#include <iostream>
#include <vector>

using namespace std;

// Функція для знаходження індексу максимального елементу в рядку
int findMaxIndex(const vector<int>& row) {
    int maxIndex = 0;
    for (int i = 1; i < row.size(); ++i) {
        if (row[i] > row[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функція для знаходження індексу мінімального елементу в рядку
int findMinIndex(const vector<int>& row) {
    int minIndex = 0;
    for (int i = 1; i < row.size(); ++i) {
        if (row[i] < row[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int M, N;
    cout << "Введіть розмір матриці MxN: ";
    cin >> M >> N;

    // Ініціалізуємо матрицю та заповнюємо її значеннями
    vector<vector<int>> matrix(M, vector<int>(N));
    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Знаходимо максимальний та мінімальний елементи матриці та їхні індекси
    int maxRowIndex = 0, maxColIndex = 0;
    int minRowIndex = 0, minColIndex = 0;
    int maxValue = matrix[0][0];
    int minValue = matrix[0][0];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                maxRowIndex = i;
                maxColIndex = j;
            }
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minRowIndex = i;
                minColIndex = j;
            }
        }
    }

    // Міняємо місцями стовпці
    for (int i = 0; i < M; ++i) {
        swap(matrix[i][maxColIndex], matrix[i][minColIndex]);
    }

    // Виводимо змінену матрицю
    cout << "Матриця після заміни стовпців:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
