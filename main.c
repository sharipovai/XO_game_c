#include <math.h>
#include <stdio.h>

#define N 3

int check_winner(int arr[N][N]);
void view_board(int array[10][10]);

int main() {
    int arr[N][N] = {0};
    arr[0][2] = 2; arr[1][1] = 2; arr[2][0] = 2;
    printf("%d", check_winner(arr));
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

void view_board(int array[][10]){

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
