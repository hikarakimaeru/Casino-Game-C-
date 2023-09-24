#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int startBankRoll = 100;
    int bankRoll = startBankRoll;
    int betAmount;
    int numOfGuess;
    char playAgain;

    srand(time(0));

    do {
        cout << "Your bank roll: " << bankRoll << "$" << "\n";

        while (true) {
            cout << "Enter the bet amount: ";
            cin >> betAmount;

            if (betAmount > bankRoll || betAmount < 1) {
                cout << "Wrong Bet! Please enter a valid bet amount.\n";
            }
            else {
                break;
            }
        }

        bankRoll -= betAmount;

        while (true) {
            cout << "Enter the number that you're betting on (1 to 10): ";
            cin >> numOfGuess;

            if (numOfGuess > 10 || numOfGuess < 1) {
                cout << "Wrong number! Please enter a number between 1 and 10.\n";
            }
            else {
                break;
            }
        }

        int randomNumber = std::rand() % 10 + 1;
        if (numOfGuess == randomNumber) {
            int win = betAmount * 10;
            bankRoll += win;
            cout << "The number was: " << randomNumber << "\n";
            cout << "You won " << win << "$! Your bankroll now is: " << bankRoll << "$\n";
        }
        else {
            cout << "The number was: " << randomNumber << "\n";
            cout << "You lost " << betAmount << "$! Your bankroll now is: " << bankRoll << "$\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' && bankRoll > 0);

    cout << "Thank you for playing! Your final bankroll is: " << bankRoll << "$\n";

    return 0;
}