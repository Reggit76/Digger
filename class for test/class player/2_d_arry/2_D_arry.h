#include <iostream>
#include <vector>

class DoubleArray {
public:
    DoubleArray(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

    void set(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        }
    }

    int get(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            return 0;
        }
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;
};
