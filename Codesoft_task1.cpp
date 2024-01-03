#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    char option;
    srand(time(0));

    do
    {
        int guess, attempt = 1;
        int number = rand() % 100 + 1;


        do
        {
            cout << "Attempt number " << attempt << "\nGuess the number between 1 to 100: ";
            cin >> guess;

            if (number < guess)
            {
                cout << "\t\033[1;31;40mThe number is less than your guessed number\033[0m \n";
                ++attempt;
            }
            else if (number > guess)
            {
                cout << "\t\033[1;31;40mThe number is greater than your guessed number\033[0m \n";
                ++attempt;
            }

        } while (number != guess);

        cout << "\e[0;32mCongratulations! You guessed the number in " << attempt << " attempt!!\033[0m\n";
        cout << "Press 'y' to play again: ";
        cin >> option;
        system("cls");
    } while (option == 'y');

    return 0;
}