#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <thread>   // for sleep animation
#include <chrono>   // for time delays
using namespace std;

// Simple typing animation function
void animateText(string text, int speed = 50) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Initialize random seed
    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess, attempts = 0;

    animateText("🎮 Welcome to the Number Guessing Game!");
    animateText("I'm thinking of a number between 1 and 100...");
    animateText("Can you guess what it is? 🤔");

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            animateText("Too low! Try again. ⬇️", 40);
        } else if (guess > secretNumber) {
            animateText("Too high! Try again. ⬆️", 40);
        } else {
            animateText("🎉 Congratulations! You guessed the number! 🎉", 30);
            cout << "It took you " << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    animateText("Thanks for playing! 😄");

    return 0;
}
