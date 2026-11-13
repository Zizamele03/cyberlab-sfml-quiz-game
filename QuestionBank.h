#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "Player.h"
using namespace std;

class QuestionBank  // outer class
{
public:
    QuestionBank();  // Default constructor
    QuestionBank(Player& p);

    void addQuestion(
        const string& question,
        vector<string> listOfOptions,
        int correctAnswerIndex,
        int questionLevel,
        string hint
    );

    // Overloaded function to add question with title and narrative
    void addQuestion(
        const std::string& title,
        const std::string& narrative,
        const std::string& questionText,
        const std::vector<std::string>& options,
        int correctIndex,
        int level,
        const std::string& hint
    );

    Player getPlayer() const; // getter method for player

private:
    class Question  // inner class
    {
    public:
        Question() {}
        Question(string question, int question_level, vector<string> options, int correct_index, string hint);
        Question(string question, int questionLevel, vector<string> options, int correctIndex, string hint, string title, string narrative);
        
        string get_correct_answer() const;
        string get_hint(Player& player) const;

        //added functions
        string getQuestionText() const;
        vector<string> getOptions() const;


    private:   // attributes of the Question
        string question;
        vector<string> options;
        int correct_index;
        string hint;
        int question_level;
        string title;
        string narrative;
    };


    // List of queues for the questions (private attributes of the QuestionBank class)
    vector<queue<Question>> listOfQuestions;
    queue<Question> queueLevelOne;
    queue<Question> queueLevelTwo;
    queue<Question> queueLevelThree;
    Player* player;  // Reference to Player class

public:
    Question getNextQuestion(int level);
    bool hasQuestions(int level) const;
    std::string answer()
    {
        Question q;
        return q.get_correct_answer();
    }
    std::string getCorrectAnswer(std::string selected)
    {
        char character = ' ';
        switch (selected[0]) {
        case 'A':
            character = 'A';
            break;
        case 'B':
            character = 'B';
            break;
        case 'C':
            character = 'C';
            break;
        case 'D':
            character = 'D';
            break;
        }
        return std::string(1, character);
    }

}; 