#include <iostream>
#include <cstdlib>
#include <ctime>

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
            std::cout << "Attempt number " << attempt << "\nGuess the number between 1 to 100: ";
            std::cin >> guess;

            if (number < guess)
            {
                std::cout << "The number is less than your guessed number\n";
                ++attempt;
            }
            else if (number > guess)
            {
                std::cout << "The number is greater than your guessed number\n";
                ++attempt;
            }

        } while (number != guess);

        std::cout << "Congratulations! Guessed the number in " << attempt << " attempt!!\n";
        std::cout << "Press 'y' to play again: ";
        std::cin >> option;
        system("cls");
    } while (option == 'y');

    return 0;
}