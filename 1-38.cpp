#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countRowsWithDistinctElements(const vector<vector<int>>& matrix) {
    int count = 0;
    for (const auto& row : matrix) {
        unordered_set<int> uniqueElements;
        bool allDistinct = true;
        for (int element : row) {
            if (uniqueElements.count(element) > 0) {
                allDistinct = false;
                break;
            }
            uniqueElements.insert(element);
        }
        if (allDistinct) {
            count++;
        }
    }
    return count;
}

int main() {
    int M, N;
    cout << "Введіть кількість рядків матриці: ";
    cin >> M;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    int rowsWithDistinctElements = countRowsWithDistinctElements(matrix);
    cout << "Кількість рядків з унікальними елементами: " << rowsWithDistinctElements << endl;

    return 0;
}
