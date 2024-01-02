#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class Game
{
private:
    char board[3][3];
    string player1;
    string player2;

public:
    Game()
    {
        player1 = ' ';
        player2 = ' ';
        char number = '1';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = number++;
            }
        }
    }
    void set_players();
    string get_player1();
    string get_player2();
    char alternater(int counter);
    void move(int a, char c);
    bool cheak_winner();
    void display();
};
void Game::set_players()
{
    cout << "Enter the name of first player" << endl;
    cin >> player1;
    cout << "Enter the name of Secound player" << endl;
    cin >> player2;
}
string Game::get_player1() { return player1; }
string Game::get_player2() { return player2; }
bool Game::cheak_winner()
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }
    for (int j = 0; j < 3; j++)
    {
        if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))
        {
            return 1;
        }
        if (board[j][0] == board[j][1] && board[j][1] == board[j][2])
        {
            return 1;
        }
    }
    return 0;
}
void Game::display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
                cout << "\033[1;31;40mX\033[0m";
            else if (board[i][j] == 'O')
                cout << "\033[22;34mO\033[0m";
            else
                cout << "\033[1;32m"<<board[i][j]<<"\033[0m";

            if (j != 2)
                cout << " | ";
        }

        if (i != 2)
            cout << endl
                 << "----------";

        cout << endl;
    }
    cout << endl;
}

void Game::move(int a, char c)
{
    int x, y;
    if (a > 6 && a < 3)
    {
        x = 2;
        y = a - 7;
    }
    else if (a > 3 && a < 6)
    {
        x = 1;
        y = a - 4;
    }
    else
    {
        x = 0;
        y = a - 1;
    }
    if (board[x][y] != 'X' && board[x][y] != 'O')
    {
        board[x][y] = c;
    }
    else
        cout << "wrong move";
}
char Game::alternater(int counter)
{
    if (counter % 2 == 0)
    {
        ++counter;
        return 'O';
    }
    else
        ++counter;
    return 'X';
}
bool start()
{
    char option;
    cout << "TIC-TAC-TOE" << endl;
    cout << "Press S to start" << endl;
    cout << "Press anykey to Quit" << endl;
    option = getch();
    system("clear");
    if (option == 's')
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    char playagain;
    int no;
    string name;
    do
    {
        Game a;
        int counter = 1;
        if (start())
        {
            // system("cls");
            a.set_players();
            do
            {
                system("cls");
                a.display();
                name = (counter % 2 != 0) ? a.get_player1() : a.get_player2();
                cout << name << "\'s turn \nEnter the number of your spot : ";
                do
                {
                    cin >> no;
                    if (no > 9)
                    {
                        cout << "Wrong number try again" << endl;
                    }
                } while (no > 9);
                a.move(no, a.alternater(counter));
                ++counter;
            } while ((!(a.cheak_winner())) && counter < 10);
            if ((a.cheak_winner()))
            {
                system("clear");
                a.display();
                cout << "Congratulations!! " << name << " you win" << endl;
            }
            else
            {
                system("clear");
                a.display();
                cout << "DRAW" << endl;
            }
        }
        cout << "Press y to play again";
        playagain = getch();
        system("clear");
    } while (playagain == 'y');
    return 0;
}