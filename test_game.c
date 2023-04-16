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

// Тестирование проверки выигрыша
void test_check_win() {
    make_move(game_board, 1, 1, X_PLAYER);
    make_move(game_board, 0, 0, O_PLAYER);
    make_move(game_board, 0, 1, X_PLAYER);
    make_move(game_board, 2, 2, O_PLAYER);
    make_move(game_board, 2, 1, X_PLAYER);
    assert(check_win(game_board, X_PLAYER) == NO_WINNER);
    make_move(game_board, 2, 0, O_PLAYER);
    assert(check_win(game_board, O_PLAYER) == WINNER);
}

// Тестирование проверки ничьей

void test_check_draw() {
   
    make_move(game_board, 0, 0, X_PLAYER);
    make_move(game_board, 0, 1, O_PLAYER);
    make_move(game_board, 0, 2, X_PLAYER);
    make_move(game_board, 1, 1, O_PLAYER);
    make_move(game_board, 1, 0, X_PLAYER);
    make_move(game_board, 1, 2, O_PLAYER);
    make_move(game_board, 2, 0, X_PLAYER);
    make_move(game_board, 2, 2, O_PLAYER);
    assert(check_draw(game_board) == DRAW);
}

// Тестирование игрового цикла
void test_game_loop() {
    
    make_move(game_board, 0, 1, X_PLAYER);
    make_move(game_board, 0, 0, O_PLAYER);
    make_move(game_board, 1, 1, X_PLAYER);
    make_move(game_board, 0, 2, O_PLAYER);
    assert(check_game_over(game_board, X_PLAYER) == NO_WINNER);
    assert(check_game_over(game_board, O_PLAYER) == NO_WINNER);
    make_move(game_board, 2, 1, X_PLAYER);
    assert(check_game_over(game_board, X_PLAYER) == WINNER);
    assert(check_game_over(game_board, O_PLAYER) == LOSER);
}
