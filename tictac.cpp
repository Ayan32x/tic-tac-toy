#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turnn = 'x';
int row, coloum;
bool draw = false;
void display()
{
    system("cls");
    cout << "     TICK CROSS GAME" << endl;
    cout << "PLAYER [X]" << endl;
    cout << "PLAYER [O]" << endl;

    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "\t\t     |     |     " << endl;
}
void turn()
{
    int choice;
    if (turnn == 'x')
        cout << "player1 [x] turn:" << endl;
    else if (turnn == 'o')
        cout << "player2 [0] turn:" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        coloum = 0;
        break;
    case 2:
        row = 0;
        coloum = 1;
        break;
    case 3:
        row = 0;
        coloum = 2;
        break;
    case 4:
        row = 1;
        coloum = 0;
        break;
    case 5:
        row = 1;
        coloum = 1;
        break;
    case 6:
        row = 1;
        coloum = 2;
        break;
    case 7:
        row = 2;
        coloum = 0;
        break;
    case 8:
        row = 2;
        coloum = 1;
        break;
    case 9:
        row = 2;
        coloum = 2;
        break;

    default:
        cout << "invalid choice" << endl;
        break;
    }
    if (turnn == 'x' && board[row][coloum] != 'x' && board[row][coloum] != 'o')
    {
        board[row][coloum] = 'x';
        turnn = 'o';
    }
    else if (turnn == 'o' && board[row][coloum] != 'x' && board[row][coloum] != 'o')
    {
        board[row][coloum] = 'o';
        turnn = 'x';
    }
    else
    {
        cout << "box already filled" << endl;
        cout << "try another key word" << endl;
        turn();
    }
}

bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) // for return game win
            return false;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][0] == board[2][0])
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'x' && board[i][j] != 'o') // for there is any box filled
                return true;
        }
    }
    draw = true;
    return false;
}
int main()
{
    while (gameover())
    {
        display();
        turn();
        display();
    }
    if (turnn == 'x' && draw == false)
    {
        cout << "player 2 [o] wins!!" << endl;
    }
    else if (turnn == 'o' && draw == false)
    {
        cout << "player 1 [x] wins!!" << endl;
    }
    else
        cout << "draw game" << endl;
}