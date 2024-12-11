#include <iostream>
using namespace std;

const int MAX_QUESTIONS = 5;

struct Question {
    const char* questionText;
    const char* options[4];
    char correctOption;
};

void displayInstructions() {
    cout << "Welcome to COS201 Quiz Game\n";
    cout << "The following are the instructions:\n";
    cout << "1. Answer the questions by typing the option letter (A/B/C/D).\n";
    cout << "2. You can skip a question by typing 'S'.\n";
    cout << "3. You can revisit a skipped question later.\n";
    cout << "4. You will get your score at the end.\n";
    cout << "Start\n\n";
}

void loadQuestions(Question* questions) {
    questions[0] = {"What is the capital of Akwa Ibom?", {"A. Lagos", "B. Aba", "C. Oron", "D. Uyo"}, 'D'};
    questions[1] = {"What is 2 + 2?", {"A. 3", "B. 4", "C. 5", "D. 6"}, 'B'};
    questions[2] = {"What is the boiling point of water (in Celsius)?", {"A. 90", "B. 80", "C. 100", "D. 120"}, 'C'};
    questions[3] = {"Which of the following is not a programming language", {"A. COS", "B. CSS", "C. JS", "D. R"}, 'A'};
    questions[4] = {"What is the boiling point of water (in Celsius)?", {"A. 90", "B. 80", "C. 100", "D. 120"}, 'C'};
}

char getUserInput() {
    char input;
    cout << "Enter your choice (A/B/C/D or S to skip or K to go back): ";
    cin >> input;
    return toupper(input);
}

void askQuestion(Question* question, char* userResponse, bool* skipped, bool back) {
    cout << question->questionText << "\n";
    for (int i = 0; i < 4; i++) {
        cout << question->options[i] << "\n";
    }
    *userResponse = getUserInput();
    *skipped = (*userResponse == 'S');
    back = (*userResponse == 'K');
}

void displayScore(int score, int totalQuestions) {
    cout << "\nQuiz Completed!\n";
    cout << "Your Score: " << score << " out of " << totalQuestions << "\n";
}

void displayScript(const char* userResponses, const Question* questions, int totalQuestions) {
    cout << "\nYour Answers:\n";
    for (int i = 0; i < totalQuestions; i++) {
        cout << "Q" << i + 1 << ": " << questions[i].questionText << "\n";
        cout << "Your Answer: " << (userResponses[i] == 'S' ? "Skipped" : string(1, userResponses[i])) << "\n";
        cout << "Correct Answer: " << questions[i].correctOption << "\n\n";
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    char userResponses[MAX_QUESTIONS] = {'S', 'S', 'S', 'S', 'S'};
    bool skippedQuestions[MAX_QUESTIONS] = {true, true, true, true, true};
    bool backQuestions[MAX_QUESTIONS] = {true, true, true, true, true};
    int score = 0;

    loadQuestions(questions);
    displayInstructions();

    int currentQuestion = 0;


    main_loop:
        if (currentQuestion < MAX_QUESTIONS) {
            cout << "\nQuestion " << currentQuestion + 1 << ":\n";
            askQuestion(&questions[currentQuestion], &userResponses[currentQuestion], &skippedQuestions[currentQuestion], backQuestions[currentQuestion]);
            if (!skippedQuestions[currentQuestion] && userResponses[currentQuestion] == questions[currentQuestion].correctOption) {
                score++;
            }
            currentQuestion++;
            goto main_loop;
        }

        currentQuestion = 0;
    review_loop:
        if (currentQuestion < MAX_QUESTIONS) {
            if (skippedQuestions[currentQuestion]) {
                cout << "\nReviewing Skipped Question " << currentQuestion + 1 << ":\n";
                askQuestion(&questions[currentQuestion], &userResponses[currentQuestion], &skippedQuestions[currentQuestion], backQuestions[currentQuestion]);
                if (!skippedQuestions[currentQuestion] && userResponses[currentQuestion] == questions[currentQuestion].correctOption) {
                    score++;
                }
            }
            currentQuestion++;
            goto review_loop;
        }

    back_loop:
        if (currentQuestion < MAX_QUESTIONS) {
            if (backQuestions[currentQuestion]) {
                cout << "\nPrevious " << currentQuestion - 1 << ":\n";
                askQuestion(&questions[currentQuestion], &userResponses[currentQuestion], &skippedQuestions[currentQuestion], backQuestions[currentQuestion]);
                if (!backQuestions[currentQuestion] && userResponses[currentQuestion] == questions[currentQuestion].correctOption) {
                    score++;
                }
            }
            currentQuestion++;
            goto back_loop;
        }
    displayScore(score, MAX_QUESTIONS);
    displayScript(userResponses, questions, MAX_QUESTIONS);

    cout << "You can play again....\n";
    return 0;
}
