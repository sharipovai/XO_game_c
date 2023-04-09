#include <stdio.h>

// Сделал тестирование для создания игрового поля, жду Сашу

void test_create_game_board() { 
    GameBoard game_board = create_game_board();
    assert(game_board != NULL);
    assert(get_player_at(game_board, 0, 0) == EMPTY);
    assert(get_player_at(game_board, 1, 1) == EMPTY);
    assert(get_player_at(game_board, 2, 2) == EMPTY);
}


// Сделал тест хода игрока
void test_make_move() {
    GameBoard game_board = create_game_board();
    make_move(game_board, 0, 0, X_PLAYER);
    assert(get_player_at(game_board, 0, 0) == X_PLAYER);
    assert(get_player_at(game_board, 1, 1) == EMPTY);
    assert(get_player_at(game_board, 2, 2) == EMPTY);
    make_move(game_board, 1, 1, O_PLAYER);
    assert(get_player_at(game_board, 1, 1) == O_PLAYER);
    assert(get_player_at(game_board, 0, 0) == X_PLAYER);
    assert(get_player_at(game_board, 2, 2) == EMPTY);
}



