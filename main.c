#include <math.h>
#include <stdio.h>
#include <locale.h>

#define N 3

int check_winner(int arr[N][N]);
void view_board(int array[N][N]);
void read_player_command(int arr[N][N], int player_id);
void congratulations(int x);

int main() {
    int arr[N][N] = {0};
    int player_id = 0;
    while (check_winner(arr) == 0) {
        view_board(arr);
        read_player_command(arr, player_id % 2 + 1);
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

void read_player_command(int arr[N][N], int player_id) {
    int x, y, z, a;
    char ch[100];
    do {
        printf("Player %d's move\n", player_id);
        do {
            printf("Enter X coordinate\n");
            a = scanf("%d.%d", &x, &z);
            fgets(ch, 100, stdin);
            rewind(stdin);
        } while (a != 1 || x < 0 || x > 2);
        do {
            printf("Enter Y coordinate\n");
            a = scanf("%d.%d", &y, &z);
            fgets(ch, 100, stdin);
            rewind(stdin);
        } while (a != 1 || y < 0 || y > 2);
        if (arr[y][x] != 0) {
            printf("This X Y coordinate is already taken!\n");
            view_board(arr);
        }
    } while (arr[y][x] != 0);
    arr[y][x] = player_id;
}

void congratulations(int x){
    printf("Congratulations! Player %d is win!\n", x);

}
