#include <stdio.h>

// void congratulations(int x);

// int main () {
//     scanf("%d", &x);
//     congratulations(int x);

//     return 0;
// }  мы лучшие  


void congratulations(int x){
    if (x == 1) {
        printf("Конец игры! Победил игрок 1");
    } else if(x == 2) {
        printf("Конец игры! Победил игрок 2");
    } else {
        printf("Победителей нет")
    }
    
}
