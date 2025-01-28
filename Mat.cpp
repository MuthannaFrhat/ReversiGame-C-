#include "Mat.h"
#include "iostream"
using namespace std;

Mat::Mat(int _size) {
    size = _size;
    mat = new char*[size];
    for (int i = 0; i < size; ++i) {
        mat[i] = new char[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            mat[i][j] = 'O';
        }
    }
}

Mat::~Mat() {
    for (int i = 0; i < size; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

int Mat::getsize() const {
    return size;
}

void Mat::SetColor(int row, char column, char color) {
    int colIndex = column - 'A';
    mat[row - 1][colIndex] = color;
}

char Mat::GetColor(int row, char column) {
    int colIndex = column - 'A';
    return mat[row - 1][colIndex];
}

void Mat::print() {


    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            if (j!=size-1) {
                cout << mat[i][j] << " ";
            }
            else{
                cout << mat[i][j];
            }

        }
        cout << '\n';
    }
}



bool Mat::ValidateMove(int row, char column, char color) {
    int colIndex = column - 'A';
    int rowIndex = row - 1;
    bool isValid = false;


    int directions[8][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
            {-1, -1},
            {-1, 1},
            {1, -1},
            {1, 1}
    };

    for (int d = 0; d < 8; ++d) {
        int dx = directions[d][0];
        int dy = directions[d][1];

        int x = rowIndex + dx;
        int y = colIndex + dy;
        bool hasOpponentDisk = false;


        while (x >= 0 && x < size && y >= 0 && y < size) {
            if (mat[x][y] == 'O') {
                break;
            }

            if (mat[x][y] != color) {
                hasOpponentDisk = true;
            } else {

                if (hasOpponentDisk) {
                    isValid = true;
                }
                break;
            }

            x += dx;
            y += dy;
        }
    }

    return isValid;
}

void Mat::FlipDisks(int row, char column, char color) {
    int colIndex = column - 'A';
    int rowIndex = row - 1;


    int directions[8][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
            {-1, -1},
            {-1, 1},
            {1, -1},
            {1, 1}
    };

    for (int d = 0; d < 8; ++d) {
        int dx = directions[d][0];
        int dy = directions[d][1];

        int x = rowIndex + dx;
        int y = colIndex + dy;
        bool hasOpponentDisk = false;


        int toFlip[64][2];
        int flipCount = 0;


        while (x >= 0 && x < size && y >= 0 && y < size) {
            if (mat[x][y] == 'O') {
                break;
            }

            if (mat[x][y] != color) {
                hasOpponentDisk = true;
                toFlip[flipCount][0] = x;
                toFlip[flipCount][1] = y;
                flipCount++;
            } else {

                if (hasOpponentDisk) {
                    for (int i = 0; i < flipCount; ++i) {
                        int flipX = toFlip[i][0];
                        int flipY = toFlip[i][1];
                        mat[flipX][flipY] = color;
                    }
                }
                break;
            }

            x += dx;
            y += dy;
        }
    }


    mat[rowIndex][colIndex] = color;
}

bool Mat::HasValidMoves(char color) {
    for (int row = 1; row <= size; ++row) {
        for (char column = 'A'; column < 'A' + size; ++column) {

            if (mat[row - 1][column - 'A'] == 'O' && ValidateMove(row, column, color)) {
                return true;
            }
        }
    }
    return false;
}
