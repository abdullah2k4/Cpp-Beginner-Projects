#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   char option;
   do
   {
      int guess, attempt = 1;
      int number;
      number = (rand() % 100) + 1;
      system("clear");
      do
      {
         cout << "Attempt number " << attempt << "\nGuess the number between 1 to 100 : ";
         cin >> guess;
         if (number < guess)
         {
            system("cls");
            cout << "The number is less than your gussed number\n";
            ++attempt;
         }
         else if (number > guess)
         {
            system("cls");
            cout << "The number is greater than your gussed number\n";
            ++attempt;
         }
      } while (number != guess);
      cout << "Congratulation guessed the number in " << attempt << " attempt!!\n";
      cout << "Press y to play again : ";
      cin >> option;
   } while (option == 'y');
   return 0;
}