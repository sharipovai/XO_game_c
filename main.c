#include <math.h>
#include <stdio.h>

#define N 3

int check_winner(int arr[N][N]);
void view_board(int array[N][N]);
int read_player_command(int arr[3][3]);
void congratulations(int x);

int main() {
    int arr[N][N] = {0};
    while (check_winner(arr) == 0) {
        view_board(arr);
        while (read_player_command(arr) == 1){}
        
    }
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

	int i;
    	int j;
    	for (j = 1; j < 4; j++) {

        	for (i = 1; i < 4; i++) {
            	if (array[j][i] == 1)
               		printf("X");
		if (array[j][i] == 2)
                	printf("0");


		if(array[j][i] == 0)
			printf(" ");
		if (i != 3)
			printf("|");
        	}
		if (j != 3)
			printf("\n-----\n");
       
	
   	 }
}

int read_player_command(int arr[3][3]) {
    printf("Ход игрока 1» «Введите координату Х");
    int x, y, x2, y2, z;
    int error_check = 0;
    int a = scanf("%d.%d", &x, &z);
    printf("Введите координату Y");
    int b = scanf("%d.%d", &y, &z);
    printf("Ход игрока 2» «Введите координату Х");
    int c = scanf("%d.%d", &x2, &z);
    printf("Введите координату Y");
    int d = scanf("%d.%d", &y2, &z);
    if (a != 1 || b != 1 || c != 1 || d != 1) {
        error_check = 1;
    } else {
        arr[x][y] = 1;
        arr[x2][y2] = 2;
    }
    return error_check;
}


void congratulations(int x){
    if (x == 1) {
        printf("Конец игры! Победил игрок 1");
    } else if(x == 2) {
        printf("Конец игры! Победил игрок 2");
    } else {
        printf("Победителей нет");
    }
}