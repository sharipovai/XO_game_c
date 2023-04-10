#include <stdio.h>
void view_board(int array[3][3]);
int main(void) {
	int array[3][3];
	view_board(array);
	return 0;
}
	void view_board(int array[][3]){
	array[1][1] = 1;
	array[1][2] = 1;
	array[1][3] = 1;
	array[2][1] = 2;
	array[2][2] = 2;
	array[2][3] = 2;
	array[3][1] = 1;
	array[3][2] = 1;
	array[3][3] = 1;
	int i;
    	int j;
    	for (j = 0; j < 3; j++) {
        	for (i = 0; i < 3; i++) {
            	if (array[j][i] == 1)
               		printf("X");
            	else
                	printf("0");
        	}
        	printf("\n");
   	 }
}
