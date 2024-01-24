#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandom();
int getUserInput();
int compareFunc(int guess, int answer);
void winFunction(int remainingGuesses);


int main(){
    cout << "Welcome to the guessing game. The system guesses a random number from 0 to 99 inclusive.\n";
    cout << "Your job is to figure out that number.\n";
    cout << "You have 5 guesses. GO!\n";

    int generated_number = getRandom();
    int guesses = 5;
    while(guesses > 0){
        int userInput = getUserInput();
        int furtherAction = compareFunc(userInput, generated_number);
        if(furtherAction == 0){
            int guessRemaining = 5 - guesses;
            winFunction(guessRemaining);
            break;
        }

        else if(furtherAction == 1){
            cout <<"Wrong! Too low.\n";
            guesses--;
        }

        else{
            cout <<"Wrong! Too high.\n";
            guesses--;
        }
    }
    if (guesses == 0){
        cout << "\n";
        cout << "You lost! The answer was " <<generated_number<<endl;
    }
    

    return 0;
}

int getRandom(){
    srand(time(0));
    int random_number = rand() % 100;
    return random_number;
}

int getUserInput(){
    int userInput;
    cout << "Enter your first guess: ";
    cin >> userInput;
    return userInput;
}

int compareFunc(int guess, int answer){
    if(guess == answer){
        return 0;
    }
    else if(guess < answer){
        return 1;
    }

    else{
        return 2;
    }
}

void winFunction(int remainingGuesses){
    cout << "\n";
    cout << "You guessed right! Took you " << remainingGuesses << " guesses" << endl;
}





