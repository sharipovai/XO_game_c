#include <stdio.h>
void view_board(int array[10][10]);
int main(void) {
	int array[10][10];
	array[1][1] = 0;
	array[1][2] = 1;
	array[1][3] = 1;
	array[2][1] = 2;
	array[2][2] = 2;
	array[2][3] = 2;
	array[3][1] = 1;
	array[3][2] = 1;
	array[3][3] = 1;

	
	view_board(array);
	return 0;
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
