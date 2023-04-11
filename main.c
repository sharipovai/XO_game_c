int read_player_command(int arr[3][3]) {
    arr[3][3] = {0};
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
