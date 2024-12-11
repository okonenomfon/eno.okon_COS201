#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX_QUESTIONS = 5;

struct Question {
    string questionText;
    string correctWord;
    string scrambledWord;
};

void displayInstructions() {
    cout << "Instructions:\n";
    cout << "1. Unscramble the word presented to you.\n";
    cout << "2. You have 5 attempts per word.\n";
    cout << "3. Enter 'N' to skip the question or 'H' for a hint.\n";
    cout << "4. Your final score will be displayed at the end.\n";
    cout << "Enter 1 to begin or 0 to exit.\n";
}

string scramble(const string& text) {
    string scrambled = text;
    random_device rd;
    mt19937 generator(rd());
    shuffle(scrambled.begin(), scrambled.end(), generator);
    return scrambled;
}

void displayScore(int score, int totalQuestions) {
    cout << "\nQuiz Completed!\n";
    cout << "Your Score: " << score << " out of " << totalQuestions << "\n";
}


void playQuiz(Question questions[], int totalQuestions) {
    int score = 0;

    for (int i = 0; i < totalQuestions; i++) {
        cout << "\nQuestion " << i + 1 << ": Unscramble this word: " << questions[i].scrambledWord << "\n";
        int attempts = 5;
        string guess;

        while (attempts > 0) {
            cout << "Your guess: ";
            cin >> guess;

            if (guess == "N") {
                cout << "You skipped this question.\n";
                break;
            } else if (guess == "H") {
                cout << "Hint: The word starts with '" << questions[i].correctWord[0] << "' and ends with '"
                     << questions[i].correctWord.back() << "'.\n";
                continue;
            } else if (guess == questions[i].correctWord) {
                cout << "Correct!\n";
                score++;
                break;
            } else {
                attempts--;
                cout << "Incorrect. Attempts remaining: " << attempts << "\n";
            }
        }

        if (attempts == 0) {
            cout << "The correct word was: " << questions[i].correctWord << "\n";
        }
    }

    displayScore(score, totalQuestions);
}

int main() {
    displayInstructions();

    int choice;
    cin >> choice;

    if (choice != 1) {
        cout << "Goodbye!\n";
        return 0;
    }

    Question questions[MAX_QUESTIONS] = {
        {"Unscramble the word:", "memorise", scramble("memorise")},
        {"Unscramble the word:", "pacify", scramble("pacify")},
        {"Unscramble the word:", "strangle", scramble("strangle")},
        {"Unscramble the word:", "marianna", scramble("marianna")},
        {"Unscramble the word:", "enomfon", scramble("enomfon")}
    };

    playQuiz(questions, MAX_QUESTIONS);

    return 0;
}
