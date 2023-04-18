#include <stdio.h>

#define N 3

void computer_move(int arr[N][N]);
void view_board(int array[N][N]);

int main() {
    int arr[N][N] = {0};
    view_board(arr);
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[2][0] = 2;
    arr[1][1] = 2;
    arr[1][2] = 1;
    computer_move(arr);
    view_board(arr);
}

void computer_move(int arr[N][N]) { 
    int weight[3] = {2, -5, 7};                             // Создаем массив, в который записываем вес приоритетности каждого символа
    int priority = -100;                                        // Приоритет решения
    int tmp_x1 = 0, tmp_x2 = 0, tmp_y1 = 0, tmp_y2 = 0; 
    int tmp_x3 = 0, tmp_x4 = 0, tmp_y3 = 0, tmp_y4 = 0; 
    int x = 0; int y = 0;                                            // Координаты пустой ячейки
    int mult_1 = 1, mult_2 = 1;                                   // Произведение элементов массива
    int mult_3 = 1, mult_4 = 1;                                    // Произведение элементов массива


    for (int i = 0; i < N; i++) {
        mult_1 = 1, mult_2 = 1;
        for (int j = 0; j < N; j++) { 
            mult_1 *= weight[arr[i][j]];            //Считаем для строк
            mult_2 *= weight[arr[j][i]]; 	    //Считаем для столбцов 
            if(arr[i][j] == 0) {
                tmp_x1 = j; tmp_y1 = i;
            }
            if(arr[j][i] == 0) {
                tmp_x2 = i; tmp_y2 = j;
            }
	}
        if ((mult_1 >= priority) && (mult_1 % weight[0] == 0)) {
            priority = mult_1;
            x = tmp_x1; y = tmp_y1;
        }
        if ((mult_2 >= priority) && (mult_2 % weight[0] == 0)) {
            priority = mult_2;
            x = tmp_x2; y = tmp_y2;
        } 
        mult_3 *= weight[arr[i][i]];            //Считаем для первой диагонали
        mult_4 *= weight[arr[i][N - i - 1]]; 	//Считаем для второй диагонали 
        if(arr[i][i] == 0) {
            tmp_x3 = i; tmp_y3 = i;
        }
        if(arr[i][N -i - 1] == 0) {
            tmp_x4 = N - i - 1; tmp_y4 = i;
        }
    }
    if ((mult_3 >= priority) && (mult_3 % weight[0] == 0)) {
        priority = mult_3;
        x = tmp_x3; y = tmp_y3;
    }
    if ((mult_4 >= priority) && (mult_4 % weight[0] == 0)) {
        priority = mult_4;
        x = tmp_x4; y = tmp_y4;
    }

    arr[y][x] = 2;                                // Осуществляем ход компьютера!
}

void view_board(int array[N][N]){
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (array[j][i] == 1)
               	printf("X");
		    if (array[j][i] == 2)
                printf("0");
		    if(array[j][i] == 0)
			    printf(" ");
		    if (i != 2)
			    printf("|");
        }
	if (j != 2)
	    printf("\n-----\n");
    }
    printf("\n");
}
