#include <stdio.h>
void view_board(int array[10][10]);
int main(void) {
	int array[10][10];
	view_board(array);
	return 0;
}
	void view_board(int array[][10]){
	array[1][1] = 0;
	array[1][2] = 3;
	array[1][3] = 1;
	array[1][4] = 3;
	array[1][5] = 1;
	array[2][1] = 4;
	array[2][2] = 4;
	array[2][3] = 4;
	array[2][4] = 4;
	array[2][5] = 4;
	array[3][1] = 2;
	array[3][2] = 3;
	array[3][3] = 2;
	array[3][4] = 3;
	array[3][5] = 2;
	array[4][1] = 4;
	array[4][2] = 4;
	array[4][3] = 4;
	array[4][4] = 4;
	array[4][5] = 4;
	array[5][1] = 1;
	array[5][2] = 3;
	array[5][3] = 1;
	array[5][4] = 3;
	array[5][5] = 1;

	int i;
    	int j;
    	for (j = 1; j < 6; j++) {
        	for (i = 1; i < 6; i++) {
            	if (array[j][i] == 1)
               		printf("X");
		if (array[j][i] == 3)
			printf("|");
		if (array[j][i] == 2)
                	printf("0");
		if (array[j][i] == 4)
			printf("-");
		if(array[j][i] == 0)
			printf(" ");
        	}
       		printf("\n");
	
   	 }

}
