#include <math.h>
#include <stdio.h>
#include <locale.h>

#define N 3

int check_winner(int arr[N][N]);
void view_board(int array[N][N]);
int read_player_command(int arr[N][N], int player_id);
void congratulations(int x);
void computer_move(int arr[N][N]);
void play(int arr[N][N], int play_id);
    
int main() {
    int play_id = 0;
    int arr[N][N] = {0};
    char ch[100];
    do {
	printf("Enter 'q' to exit\n");
        printf("Choose game mode: 1 - with human, 2 - with computer\n");
       	fgets(ch, 100, stdin);
        rewind(stdin);
    } while ((ch[0] > '2' || ch[0] < '1' || ch[1] != '\n') && (ch[0] != 'q' || ch[1] != '\n'));
    if (ch[0] != 'q') {
	play_id = ch[0] - '0';
        play(arr, play_id);
    } else {
        printf("THE END!\n");
    }
}
void play(int arr[N][N], int play_id) {
    int player_id = 0;
    int count = 0;
    while ((check_winner(arr) == 0) && (count != N*N)){
        count++;
        view_board(arr);
        if (play_id == 2 && player_id % 2 + 1 == 2) {
            printf("Computer move\n");
            computer_move(arr);
        } else {
            if (read_player_command(arr, player_id % 2 + 1) == 1) {
	        break;
	    }
        }
        player_id++;
    }
    view_board(arr);
    congratulations(check_winner(arr));
}

int check_winner(int arr[N][N]) {
    int res = 0;
    int mult_diag_rl = 1;
    int mult_diag_lr = 1;
    int pow_value = pow(2, N);
    for (int i = 0; i < N; i++) {
        int mult_vert = 1;
	int mult_gor = 1;
        for (int j = 0; j < N; j++) {
	    mult_vert *= arr[j][i];
	    mult_gor *= arr[i][j];
	}
	if (mult_vert == 1 || mult_gor == 1) {
	    res = 1;
	}
	if (mult_vert == pow_value || mult_gor == pow_value) {
	    res = 2;
	}
	mult_diag_lr *= arr[i][i];
        mult_diag_rl *= arr[i][N - i - 1];
    }
    if (mult_diag_lr == 1 || mult_diag_rl == 1) {
        res = 1;
    } else if (mult_diag_lr == pow_value || mult_diag_rl == pow_value) {
        res = 2;
    }
    return res;
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

int read_player_command(int arr[N][N], int player_id) {
    int x, y;
    int exit = 0;
    char ch[100];
    do {
        printf("Player %d's move\n", player_id);
        do {
            printf("Enter X coordinate\n");
            fgets(ch, 100, stdin);
            rewind(stdin);
        } while ((ch[0] > '2' || ch[0] < '0' || ch[1] != '\n') && (ch[0] != 'q' || ch[1] != '\n'));
        if (ch[0] != 'q') {
	    x = ch[0] - '0';
	} else {
	    break;
	}
        do {
            printf("Enter Y coordinate\n");
            fgets(ch, 100, stdin);
            rewind(stdin);
        } while ((ch[0] > '2' || ch[0] < '0' || ch[1] != '\n') && (ch[0] != 'q' || ch[1] != '\n'));
        if (ch[0] != 'q') {
	    y = ch[0] - '0';
	} else {
	    break;
	}
        if (arr[y][x] != 0) {
            printf("This X Y coordinate is already taken!\n");
            view_board(arr);
        }
    } while (arr[y][x] != 0);
    if (ch[0] == 'q') {
        exit = 1;
    } else {
        arr[y][x] = player_id;
    }
    return exit;
}
void congratulations(int x){
    if (x == 0)
        printf("Dead heat! Nobody is not win\n");
    else
        printf("Congratulations! Player %d is win!\n", x);
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
            mult_2 *= weight[arr[j][i]];            //Считаем для столбцов 
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
        mult_4 *= weight[arr[i][N - i - 1]];    //Считаем для второй диагонали 
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

    arr[y][x] = 2;
} 
