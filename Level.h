#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // For sound effects
#include <vector>
#include <fstream>
#include <string>
#include "QuestionBank.h"
#include "Player.h"
#include "Button.h"


class  Level{

private:

public:
	Level();
	~Level();

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	sf::Sprite avatar_sprite;

	std::string clickedButtonChar(Button& b)
	{
		return ((b.text).getString().toAnsiString());
	}

	Button start;
	Button nextButton;
	Button* buttonA, * buttonB, * buttonC, * buttonD;
	sf::Font nextFont;  //this is the font for the buttons because I cant't use the font defined in the level header file since my buttons need to be global


	std::string clickedCharAsString;

	bool nextLevelHome = false;
	bool nextLevelPage = false;
	bool nextLevelOnePage = false;
	bool nextLevelTwoPage = false;
	bool nextLevelThreePage = false;

	int introLevelNum;
	virtual void handleEvent(const sf::Event& event) = 0; //To pass th
	virtual void setSprites() = 0;
	virtual void render() ;
	void update();
	void setAnimation(bool& condition);
	void processEvents();
	void pollEvents();
	void skipAnimation();
	bool displayStory = false ;//when animating text to check which to be animated between narrativeStoryText(true) & questionText(false)
	
	//Function to load questions from a file
	void loadQuestionsFromFile(const std::string& filename, int level);

	//Structure to hold question outcome
	struct QuestionOutcome
	{
		std::string user_answer;
		std::string correct_answer;
		std::string question;

		bool isCorrect() const {
			return user_answer == correct_answer;
		}
	};

	//Function to get question outcome
	QuestionOutcome getQuestionOutcome(std::string ques, std::string user_ans, std::string correct_ans)
	{
		QuestionOutcome q;
		q.user_answer = user_ans;
		q.correct_answer = correct_ans;
		q.question = ques;
		q.isCorrect();

		return q;
	}

	//Question outcomes for each level
	std::vector<QuestionOutcome> outcomes;
	
	//level one intro level one page
	std::string level;
	std::string intro1,intro2,intro3;
	//From LEVEL ONE!!!!

	sf::Font font;
	sf::Text text, questionText, option1Text, option2Text, option3Text, option4Text,narrativeStoryText;
	QuestionBank questionBank;
	int currentLevel;
	//sf::RectangleShape rectangle;
	

	//Game sprite and texture was taken from game.cpp, which represented level three
	sf::Texture skullTexture,homeTexture,introTexture,levelpageTexture,GameTexture, backgroundTexture, textboxTexture, compTexture, serverTexture, avatarTexture;
	sf::Sprite  skullSprite,homeSprite,introSprite, LevelSprite,GameSprite, backgroundSprite, backgroundSprite2, textboxSprite, compSprite, serverSprite, avatarSprite;

	////NEW
	//sf::Text text, questionText, option1Text, option2Text, option3Text, option4Text, titleText, narrativeText, hintText;
	//std::vector<sf::Text> optionTexts;

	std::vector<std::string> messages;
	sf::Vector2f rectangleSize;

	//Typing sound effect functionality
	std::string fullQuestionText;  // Stores the full question
	std::string displayedQuestionText; // Stores text being animated
	sf::Clock typingClock; // Controls the speed of typing effect
	sf::SoundBuffer typingSoundBuffer; // Buffer to store sound data
	sf::Sound typingSound; // Sound effect for typing
	bool isTyping = false; // Flag to check if animation is ongoing

	std::vector<std::string> currentOptions; // Stores options
	bool optionsDisplayed = false; // Flag to track when to display options

	inline void clearOptions(); //Clears the options 

	//Handling timer atributes
	sf::Text timerText;
	sf::Clock gameClock;
	sf::Clock pulseClock;
	float levelTime;
	bool isTimerRunning;

	//void setSprites();
	void setFont();

	sf::Text message(const std::string& my_message);
	sf::Text message(const std::string& my_message, const sf::Font& font, const double& x, const double& y);
	sf::Text message(const std::string& my_message, const sf::Font& font, const double& x, const double& y, const int size);


	//FROM THE LEVEL ONE(PRIVATE)


	//Animated text function
	void animateText(const std::string& text, const std::vector<std::string>& options);

	//Handling timer functions
	void resetTimer();        // Reset the timer for a new level
	void updateTimer();       // Update the timer each frame
	void formatTime(float seconds, char* buffer); // Format seconds into MM:SS
	void handleTimerExpired(); // Handle what happens when time runs out

};

//Homepage class *******************************************************************************
class Home : public Level
{
private:
	
public:
	//HOME PAGE COSNTRUCTOR
	Home(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void render() override;


	void setSprites();

};
//STORY PAGE CLASS*****************************************************************************************************
//narrative story Home page**************************************************************************************************
class StoryPage : public Level
{

public:
	//Constructor For STORYPAGE

	StoryPage(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void setSprites();
	void render() override;
};
//Level one PageClass **** DISPLAYS NARRATIVE BEFORE LEVEL ONE***********************************************************
class LevelOnePage : public Level {

public:
	LevelOnePage(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void setSprites();
	void render() override;
	

};

//Level One class ****************************************************************************************************************
class LevelOne : public Level{

public:
	//Constructor For One Three
	LevelOne(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void setSprites();

};
// Level two PageClass * ***DISPLAYS NARRATIVE BEFORE LEVEL two * **********************************************************
class LevelTwoPage : public Level {

public:
	LevelTwoPage(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void setSprites();


};


//Level Two class *****************************************************************************************************************
class LevelTwo: public Level {

public:
	//Constructor For level Two
	LevelTwo(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void setSprites();

};

// Level THREE PageClass * ***DISPLAYS NARRATIVE BEFORE LEVEL THREE * **********************************************************
class LevelThreePage : public Level {

public:
	LevelThreePage(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void setSprites();


};





//Level Three Class ***************************************************************************************************************
class LevelThree : public Level {

public:
	//Constructor For level Three
	LevelThree(sf::RenderWindow* win);
	void handleEvent(const sf::Event& event);
	void setSprites();

};


//This is declared outside as a seperate function
template<typename T>
bool loadFile(T& type_of_file, const std::string& file_name)
{
	if (!type_of_file.loadFromFile(file_name))
	{
		std::cerr << "Error loading file: " << file_name << std::endl;
		return false;
	}
	return true;
}