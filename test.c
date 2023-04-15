#include <stdio.h>
#include <assert.h>




// Проверка поля
void test_create_game_board(int array[][10]) { 
    assert(view_board != NULL);
    assert((view_board, 1, 1) == 0);
    assert((view_board, 1, 2) == 0);
    assert((view_board, 1, 3) == 0);
    assert((view_board, 2, 1) == 0);
    assert((view_board, 2, 2) == 0);
    assert((view_board, 2, 3) == 0);
    assert((view_board, 3, 1) == 0);
    assert((view_board, 3, 2) == 0);
    assert((view_board, 3, 3) == 0);
}

// Тестирование хода игрока 
void test_make_move(int arr[][3])) { 
    make_move(game_board, 0, 0, X_PLAYER);
    assert(read_player_command(view_board, 0, 0) == X_PLAYER);
    assert(read_player_command(view_board, 1, 1) == EMPTY);
    assert(read_player_command(view_board, 2, 2) == EMPTY);
    make_move(view_board, 1, 1, O_PLAYER);
    assert(read_player_command(view_board, 1, 1) == O_PLAYER);
    assert(read_player_command(view_board, 0, 0) == X_PLAYER);
    assert(read_player_command(view_board, 2, 2) == EMPTY);
}
// Нужны будут правки, после пуша всех веток


