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
                cout << "The number is less than your guessed number\n";
                ++attempt;
            }
            else if (number > guess)
            {
                cout << "The number is greater than your guessed number\n";
                ++attempt;
            }

        } while (number != guess);

        cout << "Congratulations! Guessed the number in " << attempt << " attempt!!\n";
        cout << "Press 'y' to play again: ";
        cin >> option;
        system("cls");
    } while (option == 'y');

    return 0;
}