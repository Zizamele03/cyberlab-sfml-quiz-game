#include "QuestionBank.h"

// Default constructor
QuestionBank::QuestionBank() {}

QuestionBank::QuestionBank(Player& p) : player(&p) {}  // Initialize with player
Player QuestionBank::getPlayer() const
{
    return *player;
}
void QuestionBank::addQuestion(
    const string& question,
    vector<string> listOfOptions,
    int correctAnswerIndex,
    int questionLevel,
    string hint
)

{
    Question q(question, questionLevel, listOfOptions, correctAnswerIndex, hint);

    // Storing the question in the appropriate queue based on level
    if (questionLevel == 1) {
        queueLevelOne.push(q);
    }
    else if (questionLevel == 2) {
        queueLevelTwo.push(q);
    }
    else if (questionLevel == 3) {
        queueLevelThree.push(q);
    }
}

//Overloaded addQuestion function to handle title and narrative
void QuestionBank::addQuestion(
    const std::string& title,
    const std::string& narrative,
    const std::string& questionText,
    const std::vector<std::string>& options,
    int correctIndex,
    int level,
    const std::string& hint
) {
    Question q(questionText, level, options, correctIndex, hint, title, narrative);

    // Store based on level
    if (level == 1) {
        queueLevelOne.push(q);
    }
    else if (level == 2) {
        queueLevelTwo.push(q);
    }
    else if (level == 3) {
        queueLevelThree.push(q);
    }
}

//Constructor for initialising the questions 
QuestionBank::Question::Question(string question, int question_level, vector<string> options, int correct_index, string hint)
{
    this->question = question;
    this->options = options;
    this->correct_index = correct_index;
    this->hint = hint;
    this->question_level = question_level;
}

//Overloaded constructor for initialising the questions with title and narrative
QuestionBank::Question::Question(string question, int question_level, vector<string> options,
    int correct_index, string hint, string title, string narrative)
{
    this->question = question;
    this->question_level = question_level;
    this->options = options;
    this->correct_index = correct_index;
    this->hint = hint;
    this->title = title;
    this->narrative = narrative;
}

// Get the next question from the queue
QuestionBank::Question QuestionBank::getNextQuestion(int level) {
    if (level == 1 && !queueLevelOne.empty()) {
        Question q = queueLevelOne.front();
        queueLevelOne.pop();
        return q;
    }
    else if (level == 2 && !queueLevelTwo.empty()) {
        Question q = queueLevelTwo.front();
        queueLevelTwo.pop();
        return q;
    }
    else if (level == 3 && !queueLevelThree.empty()) {
        Question q = queueLevelThree.front();
        queueLevelThree.pop();
        return q;
    }
    return Question("No Further Questions Your Honor!", 0, {}, -1, ""); // Default question if none available
}

// Check if there are questions in the queue
bool QuestionBank::hasQuestions(int level) const {
    if (level == 1) return !queueLevelOne.empty();
    if (level == 2) return !queueLevelTwo.empty();
    if (level == 3) return !queueLevelThree.empty();
    return false;
}

// Get the question text
string QuestionBank::Question::getQuestionText() const {
    return question;
}

// Get the options for the question
vector<string> QuestionBank::Question::getOptions() const {
    return options;
}

string QuestionBank::Question::get_correct_answer() const
{
    return options[correct_index];
}

string QuestionBank::Question::get_hint(Player& player) const {
    if (player.getHints() > 0) {
        player.reduceHints();
        return hint;
    }
    return "No hints left!";
}