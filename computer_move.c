#include <stdio.h>

#define N 3

void computer_move(int arr[N][N]);
void view_board(int array[N][N]);

int main() {
    int arr[N][N] = {0};
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[2][0] = 2;
    arr[1][1] = 2;
    arr[1][2] = 1;
    computer_move(arr);
    view_board(arr);
}

void computer_move(int arr[N][N]) { 
    double new[N][N];                             // Создаем массив, в который записываем вес приоритетности каждого символа
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(arr[i][j] == 0) new[i][j] = 0.1;
            if(arr[i][j] == 1) new[i][j] = -0.5;
            if(arr[i][j] == 2) new[i][j] = 0.7;
        }
    }

    double priority = -0.035;                     // Приоритет решения
    int a = 0; int b = 0; 
    int x = 0; int y = 0;                         // Координаты пустой ячейки
    double mult = 1;                              // Произведение элементов массива
    int check_zero = 0;                           // Счетчик проверки, что есть пустая ячейка

    for (int i = 0; i < N; i++) {                 // Считаем для строк
        check_zero = 0; mult = 1;
        for (int j = 0; j < N; j++) { 
            mult *= new[i][j];                   
            if(new[i][j] == 0.1) {
                check_zero++;
                a = i; b = j;
            }
        }
        if(check_zero != 0 && mult >= priority) {
            priority = mult;
            x = a; y = b;
        }
    } 
    
    for (int j = 0; j < N; j++) {                 // Считаем для столбцов  
        check_zero = 0; mult = 1;                   
        for (int i = 0; i < N; i++) {  
            mult *= new[i][j];                   
            if(new[i][j] == 0.1) {
                check_zero++;
                a = i; b = j;
            }
        }
        if(check_zero != 0 && mult >= priority) {
            priority = mult;
            x = a; y = b;
        }
    }
    check_zero = 0; mult = 1; 
    for (int i = 0; i < N; i++) {                 // Считаем для первой диагонали 
        mult *= new[i][i];
        if(new[i][i] == 0.1) {
            check_zero++;
            a = i; b = i;
        }
    }
    if(check_zero != 0 && mult >= priority) {
        priority = mult;
        x = a; y = b;
    }
    check_zero = 0; mult = 1; 
    for (int i = 0; i < N; i++) {                 // Считаем для второй диагонали 
        mult *= new[i][N - i - 1];
        if(new[i][N - i - 1] == 0.1) {
            check_zero++;
            a = i; b = N - i - 1;
        }
    }
    if(check_zero != 0 && mult >= priority) {
        priority = mult;
        x = a; y = b;
    }

    arr[x][y] = 2;                                // Осуществляем ход компьютера!
    //printf("%lf\n", priority);
    //printf("%d %d\n", x, y);
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