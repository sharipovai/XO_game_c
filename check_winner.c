#include <stdio.h>

int check_winner(int arr[3][3]);

int main() {
    int arr[3][3] = {0};
    arr[0][2] = 2; arr[1][1] = 2; arr[2][0] = 2;
    printf("%d", check_winner(arr));
}

int check_winner(int arr[3][3]) {
    int res = 0;
    // Проверяем строки
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 1) {
            res = 1;
        }
        if (arr[i][0] == 2 && arr[i][1] == 2 && arr[i][2] == 2) {
            res = 2;
        }
    }
    // Проверяем столбцы
    for (int j = 0; j < 3; j++) {
        if (arr[0][j] == 1 && arr[1][j] == 1 && arr[2][j] == 1) {
            res = 1;
        }
        if (arr[0][j] == 2 && arr[1][j] == 2 && arr[2][j] == 2) {
            res = 2;
        }
    }
    // Проверяем диагонали
    if ((arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1) || (arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1)) {
        res = 1;
    }
    if ((arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 2) || (arr[0][2] == 2 && arr[1][1] == 2 && arr[2][0] == 2)) {
        res = 2;
    }

    return res;
}