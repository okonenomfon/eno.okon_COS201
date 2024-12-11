#include <iostream>
#include <map>
#include <list>
using namespace std;

const int MAX_QUESTIONS = 10;

struct Question {
    const char* questionText;
    const char* options[4];
    char correctOption;
};

union UserResponse {
    char response;
    int questionNumber;
};

enum Status { START, EXIT };

void displayInstructions() {
    cout << "Welcome to COS201 Quiz Game\n";
    cout << "The following are the instructions:\n";
    cout << "1. Answer the questions by typing the option letter (A/B/C/D).\n";
    cout << "2. Type 'S' to skip a question.\n";
    cout << "3. Type 'P' to go back to a previous question by entering the question number.\n";
    cout << "4. Your score will be displayed at the end.\n";
    cout << "Type '1' to Start or '0' to Exit.\n\n";
}

void loadQuestions(Question* questions) {
    questions[0] = {"What is the capital of Akwa Ibom?", {"A. Lagos", "B. Aba", "C. Oron", "D. Uyo"}, 'D'};
    questions[1] = {"What is 2 + 2?", {"A. 3", "B. 4", "C. 5", "D. 6"}, 'B'};
    questions[2] = {"What is the boiling point of water (in Celsius)?", {"A. 90", "B. 80", "C. 100", "D. 120"}, 'C'};
    questions[3] = {"Which is not a programming language?", {"A. COS", "B. CSS", "C. JS", "D. R"}, 'A'};
    questions[4] = {"Who developed C++?", {"A. Guido", "B. Dennis", "C. Bjarne", "D. James"}, 'C'};
    questions[5] = {"What does RAM stand for?", {"A. Read and Modify", "B. Random Access Memory", "C. Random Area Memory", "D. Read Address Memory"}, 'B'};
    questions[6] = {"Which is not a database?", {"A. MySQL", "B. Oracle", "C. Linux", "D. MongoDB"}, 'C'};
    questions[7] = {"What is the value of Pi?", {"A. 3.12", "B. 3.14", "C. 3.15", "D. 3.16"}, 'B'};
    questions[8] = {"HTML stands for?", {"A. HyperText Markup Language", "B. High Transfer Mark Language", "C. Hyper Transfer Mark Language", "D. HighText Markup Language"}, 'A'};
    questions[9] = {"Which is a scripting language?", {"A. Python", "B. Java", "C. C++", "D. Rust"}, 'A'};
}

void displayScore(int score, int totalQuestions) {
    cout << "\nQuiz Completed!\n";
    cout << "Your Score: " << score << " out of " << totalQuestions << "\n";
}

void displayScript(const char* userResponses, const Question* questions) {
    cout << "\nYour Answers:\n";
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        cout << "Q" << i + 1 << ": " << questions[i].questionText << "\n";
        cout << "Your Answer: " << (userResponses[i] == 'S' ? "Skipped" : string(1, userResponses[i])) << "\n";
        cout << "Correct Answer: " << questions[i].correctOption << "\n\n";
    }
}

void askQuestion(Question* question, char* userResponse, bool* skipped) {
    cout << question->questionText << "\n";
    for (int i = 0; i < 4; i++) {
        cout << question->options[i] << "\n";
    }
    cout << "Enter your choice (A/B/C/D, S to skip, P for previous question): ";
    cin >> *userResponse;
    *userResponse = toupper(*userResponse);
    *skipped = (*userResponse == 'S');
}

int main() {
    Question* questions = new Question[MAX_QUESTIONS];
    char userResponses[MAX_QUESTIONS] = {'S'};
    bool skippedQuestions[MAX_QUESTIONS] = {true};
    map<int, list<char>> questionMap;
    UserResponse response;
    int score = 0;
    Status gameStatus;

    loadQuestions(questions);

    displayInstructions();
    int choice;
    cin >> choice;
    gameStatus = (choice == 1) ? START : EXIT;

    if (gameStatus == EXIT) {
        cout << "Get the hell outta here...\n";
        delete[] questions;
        return 0;
    }

    for (int i = 0; i < MAX_QUESTIONS;) {
        cout << "\nQuestion " << i + 1 << ":\n";
        askQuestion(&questions[i], &userResponses[i], &skippedQuestions[i]);

        if (userResponses[i] == 'P') {
            cout << "Enter the question number you want to go back to: ";
            int qNum;
            cin >> qNum;
            if (qNum >= 1 && qNum <= MAX_QUESTIONS) {
                i = qNum - 1;
                continue;
            } else {
                cout << "Invalid question number! Try again.\n";
                continue;
            }
        }

        if (!skippedQuestions[i] && userResponses[i] == questions[i].correctOption) {
            score++;
        }
        i++;
    }

    displayScore(score, MAX_QUESTIONS);
    displayScript(userResponses, questions);

    delete[] questions;
    return 0;
}