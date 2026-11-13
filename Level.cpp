#include "Level.h"
#include "QuestionBank.h"
#include "Button.h"

//Constructors and setting sprites for levels
 


//FOR HOME PAGE********************************************************************************************S
Home::Home(sf::RenderWindow* win)
{
	window = win;
	start = Button("Start", { 200,50 }, 20, font, sf::Color::Red, sf::Color::Black);
	start.setPosition({ 570,600 });
	setSprites();
	setFont();

}

void Home::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {
		if (start.isMouseOver(*window)) {
			start.setBackColor(sf::Color::White);
		}
		else {
			start.setBackColor(sf::Color::Red); // default back
		}
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		if (start.isMouseOver(*window)) {
			nextLevelHome = true;
			std::cout << "You are moving to the page that supposed to have narrative\n";
		}
	}
}

void Home::render()
{
	window->clear();


	//Draw the home page
	window->draw(homeSprite);
	//std::cout << "Mouse position:" << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << "\n";
	start.drawTo(*window);

	window->display();                   //display the window

}

void Home::setSprites()
{
	::loadFile(homeTexture, "Skull1.png");
	homeSprite.setTexture(homeTexture);
}
//For StoryPage **************************************************************************
StoryPage::StoryPage(sf::RenderWindow* win)
{
	window = win;
	setSprites();
	start = Button("Continue", { 200,50 }, 20, font, sf::Color::Red, sf::Color::Black);
	start.setPosition({ 570,600 });
	setFont();
	displayStory = true;
	std::string story =
		"It was supposed to be an ordinary night at the university computer lab.\n"
		"You, a skilled but unsuspecting IT student, stayed back to work on an important project.\n"
		"But just as you were about to leave, the lights flickered,\n"
		"the screens glowed red, and an eerie robotic voice echoed through the room.\n"
		"WARNING! SYSTEM BREACH DETECTED! VIRUS ACTIVATED!\n"
		"Before you could react, the lab doors locked, trapping you inside.\n"
		"Every screen displayed corrupted code, and a sinister AI named MalX introduced itself.\n"
		"It was an advanced cyber-virus designed to take control of the entire network.\n"
		"If it spreads beyond the lab, it could wipe out years of research\n"
		"and plunge the institution into digital chaos.\n"
		"Your only chance of escape? Find the antivirus hidden deep in the lab's systems\n"
		"before MalX evolves beyond containment.\n"
		"But it won't be easy. The virus has encrypted every terminal\n"
		"and corrupted the security protocols.\n"
		"To unlock each phase of the system,\n"
		"you must solve IT-related puzzles and programming challenges,\n"
		"each more difficult than the last.";
	/*String story2 = "Before you could react, the lab doors locked, trapping you inside. Every screen \ndisplayed corrupted code, and a sinister AI named MalX introduced itself, an advanced\ncyber-virus designed to take control of the entire university network. If it spreads \nbeyond the lab, it could wipe out years of research and plunge the institution into \ndigital chaos.\n\n";
	String story3 = "Your only chance of escape? Find the antivirus hidden deep within the labs systems \nbefore MalX evolves beyond containment. But it wont be easy. The virus has encrypted \nevery terminal and corrupted the security protocols. To unlock each phase of the \nsystem, you must solve IT-related puzzles and programming challenges, each more \ndifficult than the last.";*/
	animateText(story, { "", "", "", "" });
}

void StoryPage::handleEvent(const sf::Event& event)
{
	bool TextAnimationSkipped = false;
	if (event.type == sf::Event::MouseMoved) {
		if (start.isMouseOver(*window)) {
			start.setBackColor(sf::Color::White);
		}
		else {
			start.setBackColor(sf::Color::Red); // default back
		}
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		if (start.isMouseOver(*window)) {
			if (isTyping) {
				skipAnimation();
			}
			else {
				nextLevelPage = true;
				std::cout << "You Clicked the button\n";
			}
		}
	}
}

void StoryPage::setSprites()

{
	narrativeStoryText.setFillColor(sf::Color::Red);

	narrativeStoryText.setFont(font);

	loadFile(introTexture, "IntroPage.png");
	introSprite.setTexture(introTexture);
	//animateText();
}

void StoryPage::render()
{
	window->clear();

	//Draw the background
	window->draw(introSprite);
	start.drawTo(*window);
	//Set color for text
	narrativeStoryText.setFillColor(sf::Color::Red);
	//Set the font for the text
	narrativeStoryText.setFont(font);
	//Display the message
	window->draw(narrativeStoryText);

	window->display();                    //display the window

}

//FOR level one narrative page******************************************************************************
//constructor for level1 narrative page/intro page
LevelOnePage::LevelOnePage(sf::RenderWindow* win)
{
	window = win;
	setSprites();
	setFont();
	start = Button("Start", { 200,50 }, 20, font, sf::Color::Red, sf::Color::Black);
	start.setPosition({ 570,570 });
	introLevelNum = 1;

}
void LevelOnePage::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {
		if (start.isMouseOver(*window)) {
			start.setBackColor(sf::Color::White);
		}
		else {
			start.setBackColor(sf::Color::Red); // default back
		}
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		if (start.isMouseOver(*window)) {
			nextLevelOnePage = true;
			std::cout << "You Clicked the button\n";
		}
	}
}


void LevelOnePage::setSprites()
{

	level = "LEVEL 1";
	intro1 = "The first layer of security is the firewall, now corrupted by MalX. \nTo restore it, you must solve basic IT trivia, logic puzzles, and simple coding riddles. \nAs you progress, MalX tries to slow you down with glitches and deceptive clues.";
	loadFile(levelpageTexture, "LevelPage.png");
	LevelSprite.setTexture(levelpageTexture);


}
void LevelOnePage::render()
{

	window->clear();
	window->draw(LevelSprite);
	window->draw(message(level, font, 550, 50, 80));
	window->draw(message(intro1, font, 200, 380, 20));
	start.drawTo(*window);
	window->display();

}
//For level One **************************************************************************************************************
LevelOne::LevelOne(sf::RenderWindow* win)
{

	//
	
	//Creating the buttons
	nextButton = Button("Next", sf::Vector2f(150, 50), 24, nextFont, sf::Color::Red, sf::Color::Yellow);	window = win;
	setFont();
	setSprites();

	//Load the questions from a file
	loadQuestionsFromFile("questions1.txt", currentLevel);
}

void LevelOne::handleEvent(const sf::Event& event)
{
}

void LevelOne::setSprites()
{
	//rectangle.setPosition(170, 5);
	//rectangle.setFillColor(sf::Color::Black);


	if (!loadFile(font, "arial.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}

	//Load images
	loadFile(backgroundTexture, "LevelOne.jpg");
	loadFile(textboxTexture, "textbox2.png");
	loadFile(avatarTexture, "avatar.png");

	//Scaling the top half of the background to fit 40%% of the screen
	sf::Vector2u windowSize = window->getSize();
	float targetHeight = windowSize.y * 0.30f;  // 40% of screen height
	textboxSprite.setTexture(textboxTexture);
	sf::Vector2u imageSize = textboxTexture.getSize();
	float scaleY = targetHeight / static_cast<float>(imageSize.y);
	float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(imageSize.x); // optional full stretch
	textboxSprite.setScale(scaleX, scaleY);
	textboxSprite.setPosition(0, 0);  // starts at 40% down


	//Scaling the bottom half of the background to fit 60% of the screen
	targetHeight = windowSize.y * 0.70f;  // 60% of screen height
	backgroundSprite.setTexture(backgroundTexture);
	imageSize = backgroundTexture.getSize();
	scaleY = targetHeight / static_cast<float>(imageSize.y);
	scaleX = static_cast<float>(windowSize.x) / static_cast<float>(imageSize.x); // optional full stretch
	backgroundSprite.setScale(scaleX, scaleY);
	backgroundSprite.setPosition(0.f, windowSize.y * 0.3f);  // starts at 40% down


	//Set the texture for the sprites
	textboxSprite.setTexture(textboxTexture);
	avatarSprite.setTexture(avatarTexture);
	avatarSprite.setPosition(600, 400);

	////Add Questions to the question bank
	//questionBank.addQuestion("What is the capital of Nigeria", { "A. Lagos", "B. Abuja", "C. Kano", "D. Ibadan" }, 1, 1, "No hint!!");
	//questionBank.addQuestion("What is the capital of Ghana?", { "A. Accra", "B. Kumasi", "C. Tamale", "D. Takoradi" }, 0, 1, "No hint!!");
	//questionBank.addQuestion("What is the capital of South Africa?", { "A. Johannesburg", "B. Cape Town", "C. Pretoria", "D. Durban" }, 2, 1, "No hint!!");
	//questionBank.addQuestion("What is the capital of Kenya?", { "A. Nairobi", "B. Mombasa", "C. Kisumu", "D. Nakuru" }, 0, 1, "No hint!!");
	///*questionBank.addQuestion("What is the capital of Nigeria?", { "A. Lagos", "B. Abuja", "C. Kano", "D. Ibadan" }, 1, 2, "No hint!!");*/

	currentLevel = 1; //initialise the level to level 1

	// Set up timer text
	timerText.setFont(font);
	timerText.setCharacterSize(30);
	timerText.setFillColor(sf::Color::Red);
	timerText.setPosition(1110, 160);

	resetTimer(); // Initialize the timer

	//Initiallise text message to be displayed at the start of the game
	clearOptions();
	animateText("Welcome To Level 1 Let The Game Begin!", { "", "", "", "" });

}
//Level two Intro page ********************************************************************************************************************************************
LevelTwoPage::LevelTwoPage(sf::RenderWindow* win)
{
	window = win;
	setSprites();
	setFont();
	start = Button("Start", { 200,50 }, 20, font, sf::Color::Red, sf::Color::Black);
	start.setPosition({ 570,600 });
	introLevelNum = 2;
}
void LevelTwoPage::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {
		if (start.isMouseOver(*window)) {
			start.setBackColor(sf::Color::White);
		}
		else {
			start.setBackColor(sf::Color::Red); // default back
		}
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		if (start.isMouseOver(*window)) {
			nextLevelTwoPage = true;
			std::cout << "You Clicked the button\n";

		}
	}
}
;

void LevelTwoPage::setSprites()
{
	level = "LEVEL 2";
	intro2 = "With the firewall restored, you gain deeper access into the system, but \nMalX has fragmented the antivirus into encrypted pieces hidden \nacross multiple servers.You must navigate a virtual maze, solving intermediate \nprogramming problems, debugging errors, and cracking cryptographic \npuzzles to reassemble the antivirus.";
	loadFile(levelpageTexture, "LevelPage.png");
	LevelSprite.setTexture(levelpageTexture);
}


//For level two******************************************************************************************************************
LevelTwo::LevelTwo(sf::RenderWindow* win)
{

	//Creating the buttons
	nextButton = Button("Next", sf::Vector2f(150, 50), 24, nextFont, sf::Color::Red, sf::Color::White);

	window = win;
	setSprites();
	setFont();

	//Load the questions from a file
	loadQuestionsFromFile("questions1.txt", currentLevel);
}

void LevelTwo::handleEvent(const sf::Event& event)
{
}


void LevelTwo::setSprites()
{
	//rectangle.setPosition(170, 5);
	//rectangle.setFillColor(sf::Color::Black);

	if (!loadFile(font, "arial.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}

	//Load images
	loadFile(GameTexture, "virus_image3.png");
	loadFile(backgroundTexture, "LevelTwo.jpg");
	loadFile(textboxTexture, "textbox2.png");
	loadFile(avatarTexture, "avatar.png");

	//Scaling the top half of the background to fit 40%% of the screen
	sf::Vector2u windowSize = window->getSize();
	float targetHeight = windowSize.y * 0.30f;  // 40% of screen height
	textboxSprite.setTexture(textboxTexture);
	sf::Vector2u imageSize = textboxTexture.getSize();
	float scaleY = targetHeight / static_cast<float>(imageSize.y);
	float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(imageSize.x); // optional full stretch
	textboxSprite.setScale(scaleX, scaleY);
	textboxSprite.setPosition(0, 0);


	//Scaling the bottom half of the background to fit 70% of the screen
	targetHeight = windowSize.y * 0.70f;  // 70% of screen height
	backgroundSprite.setTexture(backgroundTexture);
	imageSize = backgroundTexture.getSize();
	scaleY = targetHeight / static_cast<float>(imageSize.y);
	scaleX = static_cast<float>(windowSize.x) / static_cast<float>(imageSize.x); // optional full stretch
	backgroundSprite.setScale(scaleX, scaleY);
	backgroundSprite.setPosition(0.f, windowSize.y * 0.3f);  // starts at 30% down


	//Set the texture for the sprites
	avatarSprite.setTexture(avatarTexture);
	avatarSprite.setPosition(600, 400);

	currentLevel = 1; //initialise the level to level 1

	// Set up timer text
	timerText.setFont(font);
	timerText.setCharacterSize(30);
	timerText.setFillColor(sf::Color::Red);
	timerText.setPosition(1110, 160);

	resetTimer(); // Initialize the timer

	//Initiallise text message to be displayed at the start of the game
	clearOptions();
	animateText("Welcome To Level 2 Let The Game Begin!", { "", "", "", "" });

}

//for level 3 page******************************************************************************************************************
LevelThreePage::LevelThreePage(sf::RenderWindow* win)
{
	window = win;
	setSprites();
	setFont();
	start = Button("Start", { 200,50 }, 20, font, sf::Color::Red, sf::Color::Black);
	start.setPosition({ 570,600 });
	introLevelNum = 3;
}

void LevelThreePage::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {
		if (start.isMouseOver(*window)) {
			start.setBackColor(sf::Color::White);
		}
		else {
			start.setBackColor(sf::Color::Red); // default back
		}
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		if (start.isMouseOver(*window)) {
			nextLevelThreePage = true;
			std::cout << "You Clicked the button\n";

		}
	}
}



void LevelThreePage::setSprites()
{
	level = "LEVEL 3";
	intro3 = "The final piece of the antivirus is within reach, but MalX transforms into a \nself-learning AI, challenging you directly";
	loadFile(levelpageTexture, "LevelPage.png");
	LevelSprite.setTexture(levelpageTexture);

}
//For level three*********************************************************************************************
LevelThree::LevelThree(sf::RenderWindow* win)
{
	

	//Creating the buttons
	nextButton = Button("Next", sf::Vector2f(150, 50), 24, nextFont, sf::Color::Red, sf::Color::White);	window = win;
	setSprites();
	setFont();

	//Load the questions from a file
	loadQuestionsFromFile("questions1.txt", currentLevel);
}

void LevelThree::handleEvent(const sf::Event& event)
{
}


//Sprites for level Three
void LevelThree::setSprites()
{
	//rectangle.setPosition(170, 5);
	//rectangle.setFillColor(sf::Color::Black);

	if (!loadFile(font, "arial.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}

	//Load images
	loadFile(backgroundTexture, "LevelThree.jpg");
	loadFile(textboxTexture, "textbox1.png");
	loadFile(avatarTexture, "avatar.png");

	//Scaling the top half of the background to fit 40%% of the screen
	sf::Vector2u windowSize = window->getSize();
	float targetHeight = windowSize.y * 0.40f;  // 40% of screen height
	textboxSprite.setTexture(textboxTexture);
	sf::Vector2u imageSize = textboxTexture.getSize();
	float scaleY = targetHeight / static_cast<float>(imageSize.y);
	float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(imageSize.x); // optional full stretch
	textboxSprite.setScale(scaleX, scaleY);
	textboxSprite.setPosition(0, 0);  // starts at 40% down


	//Scaling the bottom half of the background to fit 60% of the screen
	targetHeight = windowSize.y * 0.60f;  // 60% of screen height
	backgroundSprite.setTexture(backgroundTexture);
	imageSize = backgroundTexture.getSize();
	scaleY = targetHeight / static_cast<float>(imageSize.y);
	scaleX = static_cast<float>(windowSize.x) / static_cast<float>(imageSize.x); // optional full stretch
	backgroundSprite.setScale(scaleX, scaleY);
	backgroundSprite.setPosition(0.f, windowSize.y * 0.4f);  // starts at 40% down

	//Set the texture for the sprites
	avatarSprite.setTexture(avatarTexture);
	avatarSprite.setPosition(600, 400);

	//Add Questions to the question bank
	questionBank.addQuestion("What is the capital of Nigeria", { "A. Lagos", "B. Abuja", "C. Kano", "D. Ibadan" }, 1, 1, "No hint!!");
	questionBank.addQuestion("What is the capital of Ghana?", { "A. Accra", "B. Kumasi", "C. Tamale", "D. Takoradi" }, 0, 1, "No hint!!");
	questionBank.addQuestion("What is the capital of South Africa?", { "A. Johannesburg", "B. Cape Town", "C. Pretoria", "D. Durban" }, 2, 1, "No hint!!");
	questionBank.addQuestion("What is the capital of Kenya?", { "A. Nairobi", "B. Mombasa", "C. Kisumu", "D. Nakuru" }, 0, 1, "No hint!!");
	questionBank.addQuestion("What is the capital of Nigeria?", { "A. Lagos", "B. Abuja", "C. Kano", "D. Ibadan" }, 1, 2, "No hint!!");

	currentLevel = 1; //initialise the level to level 1

	// Set up timer text
	timerText.setFont(font);
	timerText.setCharacterSize(30);
	timerText.setFillColor(sf::Color::Red);
	timerText.setPosition(600, 0);

	resetTimer(); // Initialize the timer

	//Initiallise text message to be displayed at the start of the game
	clearOptions();
	animateText("Welcome To Level 3 Let The Game Begin!", { "", "", "", "" });

}


//Implementing all the level functions


void Level::pollEvents() {
	//These are not events it just checks if a key is pressed down 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { avatar_sprite.move(0, -2); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) avatar_sprite.move(0, 2);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) avatar_sprite.move(-2, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))avatar_sprite.move(2, 0);
	while (window->pollEvent(event))
	{

		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)//Closes window if esc pressed
				window->close();
			break;
		}

	}

}
void Level::skipAnimation()
{
	if (isTyping) {
		// Immediately complete the text.
		displayedQuestionText = fullQuestionText;
		if (displayStory)
			narrativeStoryText.setString(fullQuestionText);
		else
			questionText.setString(fullQuestionText);

		// Stop the animation and sound.
		isTyping = false;
		typingSound.stop();
		optionsDisplayed = true;
	}
}
;

//Load questions from a file
void Level::loadQuestionsFromFile(const std::string& filename, int level) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Could not open question file: " << filename << std::endl;
		return;
	}

	std::string line;
	std::string title, narrative, hint, questionText, correctAnswer;
	std::vector<std::string> options;

	while (std::getline(file, line)) {
		if (line == "BEGIN_QUESTION") {
			title.clear();
			narrative.clear();
			hint.clear();
			questionText.clear();
			correctAnswer.clear();
			options.clear(); // Clear vector for each question
		}
		else if (line.rfind("Question_title|", 0) == 0) {
			title = line.substr(15);
		}
		else if (line.rfind("Narrative|", 0) == 0) {
			narrative = line.substr(10);
		}
		else if (line.rfind("Hint|", 0) == 0) {
			hint = line.substr(5);
		}
		else if (line.rfind("Question|", 0) == 0) {
			questionText = line.substr(9);
		}
		else if (line.rfind("Correct_answer|", 0) == 0) {
			correctAnswer = line.substr(15);
		}
		else if (line.rfind("A|", 0) == 0) {
			options.push_back("A) " + line.substr(2));
		}
		else if (line.rfind("B|", 0) == 0) {
			options.push_back("B) " + line.substr(2));
		}
		else if (line.rfind("C|", 0) == 0) {
			options.push_back("C) " + line.substr(2));
		}
		else if (line.rfind("D|", 0) == 0) {
			options.push_back("D) " + line.substr(2));
		}
		else if (line == "END_QUESTION") {
			int correctIndex = -1;

			// Match correct answer string with the labeled options
			for (int i = 0; i < options.size(); ++i) {
				if (correctAnswer == options[i]) {
					correctIndex = i;
					break;
				}
			}

			if (correctIndex != -1) {
				questionBank.addQuestion(title, narrative, questionText, options, correctIndex, level, hint);
			}
			else {
				std::cerr << "Invalid correct answer format: " << correctAnswer << std::endl;
			}
		}
	}

	file.close();
}




//Level Constructor
void Level::setFont()
{
	::loadFile(font, "arial.ttf");
	text.setFont(font);
}

sf::Text Level::message(const std::string& my_message, const sf::Font& font, const double& x, const double& y)
{
	sf::Text message;
	message.setFont(font);
	message.setString(my_message);
	message.setFillColor(sf::Color::White);
	message.setCharacterSize(20);
	message.setPosition(x, y);
	return message;
}

// Displays narrative messages
sf::Text Level::message(const std::string& my_message) {
	sf::Text message;
	message.setFont(font);
	message.setString(my_message);
	message.setFillColor(sf::Color::Green);
	message.setCharacterSize(20);
	message.setPosition(290, 30);
	return message;
}
sf::Text Level::message(const std::string& my_message, const sf::Font& font, const double& x, const double& y, const int size)
{
	sf::Text message;
	message.setFont(font);
	message.setString(my_message);
	message.setFillColor(sf::Color::Red);
	message.setCharacterSize(size);
	message.setPosition(x, y);
	return message;
}




void Level::render()          //Level render
{
	window->clear();

	//Draw intro page for specified level
	if (introLevelNum == 1 || introLevelNum == 2 || introLevelNum == 3) {
		window->draw(LevelSprite);
		window->draw(message(level, font, 550, 50, 80));
		start.drawTo(*window);
	}
	switch (introLevelNum) {
	case 1:
		window->draw(message(intro1, font, 200, 380, 20));
		break;
	case 2:
		window->draw(message(intro2, font, 200, 380, 20));
		break;
	case 3:
		window->draw(message(intro3, font, 200, 380, 20));
		break;
	}

	// *********************************************************************
	//Draw the background

	window->draw(backgroundSprite);
	window->draw(textboxSprite);
	//Draw the rectangle
	//window->draw(rectangle);

	skullSprite.setTexture(skullTexture);
	int a = 0;
	for (int i = 0; i < 2; i++) {
		skullSprite.setPosition(a, 0);
		window->draw(skullSprite);
		a += 1160;
	}

	//Set color for text
	questionText.setFillColor(sf::Color::Red);
	option1Text.setFillColor(sf::Color::Yellow);
	option2Text.setFillColor(sf::Color::Yellow);
	option3Text.setFillColor(sf::Color::Yellow);
	option4Text.setFillColor(sf::Color::Yellow);

	//Set the font for the text
	questionText.setFont(font);
	option1Text.setFont(font);
	option2Text.setFont(font);
	option3Text.setFont(font);
	option4Text.setFont(font);
	//Set the positions of the text

	questionText.setPosition(210, 10);
	option1Text.setPosition(210, 70);
	option2Text.setPosition(210, 100);
	option3Text.setPosition(210, 130);
	option4Text.setPosition(210, 160);

	//Display the message
	window->draw(text);
	window->draw(questionText);
	window->draw(option1Text);
	window->draw(option2Text);
	window->draw(option3Text);
	window->draw(option4Text);
	window->draw(timerText);

	
	//Drawing the buttons
	if (!loadFile(nextFont, "arial.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}

	//Setting the positions for the buttons
	nextButton.setPosition(sf::Vector2f(1200, 675));   //setting the position of the next button


	//Drawing the buttons
	nextButton.drawTo(*window);
	buttonA->drawTo(*window);
	buttonB->drawTo(*window);
	buttonC->drawTo(*window);
	buttonD->drawTo(*window);


	window->draw(avatarSprite);          //draw the avatar
	window->display();                   //display the window
}

inline void Level::clearOptions() {
	/*vector<sf::Text> optionTexts = { option1Text, option2Text, option3Text, option4Text };
	for (size_t i = 0; i < currentOptions.size(); i++) {
		optionTexts[i].setString("");
	}*/

	if (currentOptions.size() < 2) {
		option1Text.setString("");
		option2Text.setString("");
	}
	else {
		option1Text.setString("");
		option2Text.setString("");
		option3Text.setString("");
		option4Text.setString("");
	}
}

//Sets up for text animation.Animation is actually done in the update method 
void Level::animateText(const std::string& text, const std::vector<std::string>& options) {
	fullQuestionText = text;  // Store the full question
	displayedQuestionText = ""; // Start with an empty string
	currentOptions = options;  // Store options
	isTyping = true;  // Start animation
	optionsDisplayed = false;  // Hide options until the question finishes

	typingClock.restart();  // Reset the timer

	// Load and play the typing sound
	if (typingSoundBuffer.loadFromFile("typing_sound.wav")) {
		typingSound.setBuffer(typingSoundBuffer);
		typingSound.setLoop(true); // Keep playing while typing
		typingSound.play();
	}
	else {
		std::cerr << "Failed to load typing sound!" << std::endl;
	}
}

//Process user input
void Level::processEvents() {

	sf::Event event;

	while (window->pollEvent(event)) {
		handleEvent(event);//Calls the handle event method depending on which level is created
		//rectangle.setSize(rectangleSize);

		buttonA->handleClick(*window, event);
		buttonB->handleClick(*window, event);
		buttonC->handleClick(*window, event);
		buttonD->handleClick(*window, event);


		if (buttonA->isClicked())
		{
			clickedCharAsString = clickedButtonChar(*buttonA);
			buttonA->unclick();
		}
		if (buttonB->isClicked())
		{
			clickedCharAsString = clickedButtonChar(*buttonB);
			buttonB->unclick();
		}
		if (buttonC->isClicked())
		{
			clickedCharAsString = clickedButtonChar(*buttonC);
			buttonC->unclick();
		}
		if (buttonC->isClicked())
		{
			clickedCharAsString = clickedButtonChar(*buttonD);
			buttonD->unclick();
		}


		if (event.type == sf::Event::Closed)
			window->close();

		//if (event.type == sf::Event::KeyPressed) {

		if (nextButton.isButtonClicked(*window) || event.key.code == sf::Keyboard::Enter) {     //isMouseOver() will only work if the window is minimised

			avatarSprite.setPosition(600, 400);
				if (isTyping) {
					skipAnimation();
				}
				else if (questionBank.hasQuestions(currentLevel)) {
					displayStory = false;
					auto q = questionBank.getNextQuestion(currentLevel);

					QuestionOutcome ot = getQuestionOutcome(
						q.getQuestionText(),
						clickedCharAsString,
						questionBank.getCorrectAnswer(q.get_correct_answer()));
					animateText(q.getQuestionText(), q.getOptions());

					outcomes.push_back(ot);

				}
				else {
					for (QuestionOutcome q : outcomes)
					{
						std::cout << "QUESTIONS:: " << std::endl;
						std::cout << q.question << " <--> " << "Correct_Answer: " << q.correct_answer << "<---> " << "Your Answer: " << q.user_answer << "  ----> 0(Wrong) - 1((Correct) ->" << q.isCorrect() << std::endl;
					}
					outcomes.clear();
					animateText("No Further Questions.", { "", "", "", "" });
				}
				// Check if timer is running 
				if (!isTimerRunning) {
					currentLevel++;
					resetTimer();
				}

			}
	}
}


//Update the game state
void Level::update()
{
	processEvents();

	if (buttonA->isButtonClicked(*window))
	{
		avatarSprite.move(-30, -7);
	}
	if (buttonB->isButtonClicked(*window))
	{
		avatarSprite.move(-30, 13);
	}

	if (buttonB->isButtonClicked(*window))
	{
		avatarSprite.move(16, -7);
	}

	if (buttonD->isButtonClicked(*window))
	{
		avatarSprite.move(16, 15);
	}
	updateTimer();

	// Check if typing animation is ongoing
	if (isTyping) {
		// Clear options while typing
		clearOptions();

		// Control typing speed, add one character at a time
		if (typingClock.getElapsedTime().asSeconds() > 0.08) {

			if (displayedQuestionText.length() < fullQuestionText.length()) {

				displayedQuestionText += fullQuestionText[displayedQuestionText.length()]; // Add next character
				if (displayStory == true) {
					narrativeStoryText.setString(displayedQuestionText);
				}
				else {
					questionText.setString(displayedQuestionText);
				}
				// Update displayed text

				typingClock.restart();  // Reset clock for next character

			}

			else {
				isTyping = false; // Typing animation finished
				typingSound.stop(); // Stop the typing sound
				optionsDisplayed = true; // Show options after typing is complete
			}
		}
	}


	// Display options only after question finishes typing
	if (optionsDisplayed && !currentOptions.empty()) {
	
		vector<sf::Text> optionTexts = { option1Text, option2Text, option3Text, option4Text };
		for (size_t i = 0; i < currentOptions.size(); i++) {
			optionTexts[i].setString(currentOptions[i]);
		}

		if (currentOptions.size() < 2) {
			option1Text.setString(currentOptions[0]);
			option2Text.setString(currentOptions[1]);
		}
		else {
			option1Text.setString(currentOptions[0]);
			option2Text.setString(currentOptions[1]);
			option3Text.setString(currentOptions[2]);
			option4Text.setString(currentOptions[3]);
		}
	}


}

void Level::setAnimation(bool& condition)
{
	displayStory = condition;

}


void Level::resetTimer() {
	levelTime = 8 * 60; // 8 minutes in seconds
	gameClock.restart();
	isTimerRunning = true;
}

//Used for the timer in each level
void Level::updateTimer() {
	if (isTimerRunning) {
		float elapsedTime = gameClock.getElapsedTime().asSeconds(); //Measures how much time has passed since the last frame.
		gameClock.restart();

		levelTime -= elapsedTime; //responsible for reducing the remaining time in the countdown timer.

		// Check if time has expired
		if (levelTime <= 0) {
			levelTime = 0;
			isTimerRunning = false;
			handleTimerExpired();
		}

		// Update timer display
		char timeBuffer[10];
		formatTime(levelTime, timeBuffer); // converts the seconds into the right MM:SS format
		timerText.setString(timeBuffer);

		// Change color when time is running low (less than 1 minute)
		if (levelTime < 60) {
			timerText.setFillColor(sf::Color(255, 0, 0)); // Bright red
			float pusleTime = pulseClock.getElapsedTime().asSeconds();
			float scaleFactor = 1.0f + 1.0f * std::sin(pusleTime * 5);
			timerText.setScale(scaleFactor, scaleFactor);
		}
		else {
			timerText.setFillColor(sf::Color(220, 220, 0)); // Yellow
			timerText.setScale(1.0f, 1.0f);

		}
	}
}

// Format seconds into MM:SS
void Level::formatTime(float seconds, char* buffer) {
	int minutes = static_cast<int>(seconds) / 60;
	int secs = static_cast<int>(seconds) % 60;
	sprintf_s(buffer, 10, "%02d:%02d", minutes, secs);
}

// Handle what happens when time runs out
void Level::handleTimerExpired() {
	// What happens when time runs out - implement game logic here
	text = message("Time's up! Press Enter to continue to next level...");
}
Level::Level()
{
	buttonA = new Button("A", sf::Vector2f(100.f, 60.f), 35, font, sf::Color::Transparent, sf::Color::Yellow);
	buttonB = new Button("B", sf::Vector2f(100.f, 60.f), 35, font, sf::Color::Transparent, sf::Color::Yellow);
	buttonC = new Button("C", sf::Vector2f(100.f, 60.f), 35, font, sf::Color::Transparent, sf::Color::Yellow);
	buttonD = new Button("D", sf::Vector2f(100.f, 60.f), 35, font, sf::Color::Transparent, sf::Color::Yellow);

	buttonA->setPosition(sf::Vector2f(20.f, 300.f));
	buttonB->setPosition(sf::Vector2f(20.f, 600.f));
	buttonC->setPosition(sf::Vector2f(1000.f, 300.f));
	buttonD->setPosition(sf::Vector2f(1000.f, 600.f));

	std::vector<std::vector<QuestionOutcome>> outcomes(3);

	loadFile(skullTexture, "virus_image.png");
}
Level::~Level()
{
	delete buttonD;
	delete buttonC;
	delete buttonB;
	delete buttonA;
}


