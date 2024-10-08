#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using std::cin;
using std::string;
using std::cout;
using std::endl;

enum {game_size = 10, player_size = 2};

struct players {char pole[game_size][game_size]; short ship[4][1]; char pole_shoot[game_size][game_size]; };

void creating_pole(char ( *ar )[game_size])
{
    for(int i = 0; i < game_size; i++){
        for(int j = 0; j < game_size; j++){
            ar[i][j] = 'o';
        }
    }
}

void creating_ship( short (*ship)[1])
{
    ship[0][0] = 1;
    ship[1][0] = 2;
    ship[2][0] = 3;
    ship[3][0] = 4;
}

void print_pole(char ( *ar )[game_size])
{
    string symbol = "ABCDEFGHIJ";
    cout << ' ' << ' ' << ' ';

    for (auto c : symbol){
        cout << c << ' ';
    }
    
    cout << '\n';

    for(int i = 0; i < game_size; i++){
        if(i == 9){
            cout << i + 1 << ' ';
        }
        else{
            cout << ' ' << i + 1 << ' ';
        }
        for(int j = 0; j < game_size; j++){
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }
}

int transformashion_sumbol(char x, int y)
{
    int x1 = x;

    switch(x)
    {
        case 'A':
            x1 = 0;
            break;
        case 'B':
            x1 = 1;
            break;
        case 'C':
            x1 = 2;
            break;
        case 'D':
            x1 = 3;
            break;
        case 'E':
            x1 = 4;
            break;
        case 'F':
            x1 = 5;
            break;
        case 'G':
            x1 = 6;
            break;
        case 'H':
            x1 = 7;
            break;
        case 'I':
            x1 = 8;
            break;
        case 'J':
            x1 = 9;
            break;
        default:
            x1 = -1;
            break;
    }
    return x1;
}

int print_shoot(int x, int y, char ( *ar )[game_size])
{
    int x_new = transformashion_sumbol(x, y);

    ar[y][x_new] = 'x';
    print_pole(ar);

    return 0;
}

int add_ship(char x, int y, char x1, int y1, char ( *ar )[game_size], short (*ship)[1])
{
    int x_new = transformashion_sumbol(x, y);
    int x1_new = transformashion_sumbol(x1, y1);

    if(x_new < 0 || x1_new < 0 || y < 0 || y1 < 0) {
        cout << "Неверно введенные координаты!" << endl;
        return 1;
    }

    if(y + 1 > 10 || y1 + 1 > 10) {
        cout << "Неверно введенные координаты" << endl;
        return 1;
    }

    if(x != x1 && y != y1){
        cout << "Неверно введенные координаты" << endl;
        return 1;
    }

    if((abs((x_new) - (x1_new)) + 1 > 4) || (abs(y - y1) + 1 > 4)){
        cout << "Неверно введенные координаты" << endl;
        return 1;
    }

    if(x_new > x1_new || y > y1){
        cout << "Неверно введенные координаты" << endl;
        return 1;
    }

    if(x_new - x1_new == 0){

        for(int i = x_new; i <= x1_new; i++){
            for(int j=y; j <= y1;j++){
                if(ar[j][i] == '='){
                    cout << "Вы уже поставили сюда корабль" << '\n' << endl;
                    return 0;
                }
            }
        }

        switch(abs(y - y1) + 1)
        {
            case 1:
                if(ship[3][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[3][0]--;
                break;
            case 2:
                if(ship[2][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[2][0]--;
                break;
            case 3:
                if(ship[1][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[1][0]--;
                break;
            case 4:
                if(ship[0][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[0][0]--;
                break;
        }

        
        for(int i = x_new; i <= x1_new; i++){
            for(int j=y; j <= y1;j++){
                ar[j][i] = '=';
                }
            }
        return 0;
    }

    if(y - y1 == 0){

        for(int i = x_new; i <= x1_new; i++){
            for(int j=y; j <= y1;j++){
                if(ar[j][i] == '='){
                    cout << "Вы уже поставили сюда корабль" << '\n' << endl;
                    return 0;
                }
            }
        }

        switch(abs(x_new - x1_new) + 1)
        {
            case 1:
                if(ship[3][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[3][0]--;
                break;
            case 2:
                if(ship[2][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[2][0]--;
                break;
            case 3:
                if(ship[1][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[1][0]--;
                break;
            case 4:
                if(ship[0][0] - 1 < 0){
                    cout << "Больше кораблей нельзя поставить" << endl;
                    return 0;
                }
                ship[0][0]--;
                break;
        }

        for(int i = x_new; i <= x1_new; i++){
            for(int j=y; j <= y1;j++){
                ar[j][i] = '=';
            }
        }
        return 0;
    }

    return 0;
}

int ship_check(char ( *ar )[game_size])
{
    for(int i = 0; i < game_size; i++){
        for(int j = 0; j < game_size; j++){
            if(ar[i][j] == '=') return 1;
        }
    }
    return 0;
}

int play_shots(int x, int y, char ( *ar )[game_size])
{
    int flag = 0;
    int x_new = transformashion_sumbol(x, y);

    if(ar[y][x_new] == '=') flag = 1;

    if(ar[y][x_new] == 'x'){
        cout << "Вы уже стреляли сюда. Попробуйте снова" << endl;
        flag = 2;
        return flag;
    }

    ar[y][x_new] = 'x';
    return flag;
}

int main()
{
    system("chcp 65001 > nul");

    struct players player[player_size];

    creating_ship(player[0].ship);
    creating_ship(player[1].ship);

    char x, x1;
    int y, y1;

    creating_pole(player[0].pole);
    creating_pole(player[1].pole);

    creating_pole(player[0].pole_shoot);
    creating_pole(player[1].pole_shoot);

    cout << "Добро пожаловать в игру \"Морской бой\"" << '\n' << endl;
    cout << "Небольшой справочник" << '\n' << "Символ \"o\" - пустая клетка" << '\n' << "Символ \"=\" - клетка, на которой стоит ваш корабль" << '\n' << "Символ \"x\" - клетка, в которую попали выстрелом" << '\n' << endl;
    cout << "Перед тем как начать игру расставьте свои корабли" << '\n' << endl;
    cout << "Всего есть 4 вида короблей" << '\n' << "В 1 количестве - Линкор ряд из 4 клеток" << '\n' << "В 2 единицах - Крейсер ряд из 3 клеток" << '\n' << "В 3 единицах - Эсминцы ряд из 2 клеток" << '\n' << "В 4 единицах - Торпедные катера 1 клетка" << '\n' << endl;

    //Запрос у первого игрока расстановка кораблей
    while((player[0].ship[0][0] != 0) || (player[0].ship[1][0] != 0) || (player[0].ship[2][0] != 0) || (player[0].ship[3][0] != 0)){
        cout << "Игровое поле игрока номер 1" << '\n' << endl;
        print_pole(player[0].pole);

        cout << '\n' << "Осталось расставить:" << '\n' << "Линкор -" << ' ' << player[0].ship[0][0] << '\n' << "Крейсер -" << ' ' << player[0].ship[1][0] << '\n' << "Эсминец -" << ' ' << player[0].ship[2][0] << '\n' << "Торпедный катер -" << ' ' << player[0].ship[3][0];

        cout << '\n' << "Введите первые координаты для своего корабля (x, y):" << ' ';
        cin >> x >> y;

        cout << '\n' << "Введите вторые координаты для своего корабля (x, y):" << ' ';
        cin >> x1 >> y1;

        add_ship(x, y-1, x1, y1-1, player[0].pole, player[0].ship);

        write(1, "\E[H\E[2J", 7);
        
    }

    cout << "Всего есть 4 вида короблей" << '\n' << "1 единица - Линкор ряд из 4 клеток" << '\n' << "2 единиц - Крейсер ряд из 3 клеток" << '\n' << "3 единиц - Эсминцы ряд из 2 клеток" << '\n' << "4 единиц - Торпедные катера 1 клетка" << '\n' << endl;
    
    //Запрос у второго игрока расстановка кораблей
    while((player[1].ship[0][0] != 0) || (player[1].ship[1][0] != 0) || (player[1].ship[2][0] != 0) || (player[1].ship[3][0] != 0)){
        cout << "Игровое поле игрока номер 2" << '\n' << endl;
        print_pole(player[1].pole);

        cout << '\n' << "Осталось расставить:" << '\n' << "Линкор -" << ' ' << player[1].ship[0][0] << '\n' << "Крейсер -" << ' ' << player[1].ship[1][0] << '\n' << "Эсминец -" << ' ' << player[1].ship[2][0] << '\n' << "Торпедный катер -" << ' ' << player[1].ship[3][0];

        cout << '\n' << "Введите первые координаты для своего корабля (x, y):" << ' ';
        cin >> x >> y;

        cout << '\n' << "Введите вторые координаты для своего корабля (x, y):" << ' ';
        cin >> x1 >> y1;

        add_ship(x, y-1, x1, y1-1, player[1].pole, player[1].ship);

        write(1, "\E[H\E[2J", 7);

    }

    while((ship_check(player[0].pole) && ship_check(player[1].pole))){
        cout <<'\n' << "Игрок номер 1 введите координаты для выстрела: ";
        cin >> x >> y;
        

        print_shoot(x, y-1, player[0].pole_shoot);
        while(play_shots(x, y-1, player[1].pole) && ship_check(player[0].pole)){

            cout << "Есть попадание" << endl;
            cout << "Игрок номер 1 введите координаты для выстрела: ";
            cin >> x >> y;
            print_shoot(x, y-1, player[0].pole_shoot);
        }
        cout << '\n' << "Промах первого игрока" << endl;

        cout << '\n' << "Игрок номер 2 введите координаты для выстрела: ";
        cin >> x >> y;
        
        print_shoot(x, y-1, player[1].pole_shoot);
        while(play_shots(x, y-1, player[0].pole) && ship_check(player[1].pole)){

            cout << '\n' << "Есть попадание" << endl;
            cout << '\n' << "Игрок номер 2 введите координаты для выстрела: ";
            cin >> x >> y;
            print_shoot(x, y-1, player[1].pole_shoot);
        }
        cout << '\n' << "Промах второго игрока" << endl;
    }

    if(ship_check(player[0].pole)) cout << "Выиграл игрок номер 1" << endl;

    if(ship_check(player[1].pole)) cout << "Выиграл игрок номер 2" << endl;

    return 0;
}
