# include "Game.h"

using namespace sf;

Game::Game() {};

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(1360, 750), "Game");
    window.setFramerateLimit(60);

    // Initialize the first level
    Level* currentLevel = new Home(&window);

    while (window.isOpen()) {
        // Handle events (key presses, window events)
        currentLevel->processEvents();

        // Update the game state (avatar movement, timer, etc.)
        currentLevel->update();

        // Render the game to the window
        currentLevel->render();

        // Check for key presses to change levels
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            delete currentLevel;  // Free the memory for the previous level
            currentLevel = new Home(&window);  // Create a new level
        }
        if (/*sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||*/ (currentLevel->nextLevelHome == true))
        {
            delete currentLevel;  // Free the memory for the previous level
            currentLevel = new StoryPage(&window);  // Create a new level
            currentLevel->nextLevelHome = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (currentLevel->nextLevelPage == true))
        {
            delete currentLevel;  // Free the memory for the previous level
            currentLevel = new LevelOnePage(&window);  // Create a new level
            currentLevel->nextLevelPage = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) || (currentLevel->nextLevelOnePage == true))
        {
            delete currentLevel;  // Free the memory for the previous level
            currentLevel = new LevelOne(&window);  // Create a new level
            currentLevel->nextLevelOnePage = false;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            delete currentLevel;  // Free the memory for the previous level
            currentLevel = new LevelTwoPage(&window);  // Create a new level
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) || (currentLevel->nextLevelTwoPage == true))
        {
            delete currentLevel;
            currentLevel = new LevelTwo(&window);
            currentLevel->nextLevelTwoPage = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            delete currentLevel;  // Free the memory for the previous level
            currentLevel = new LevelThreePage(&window);  // Create a new level
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) || (currentLevel->nextLevelThreePage == true))
        {
            delete currentLevel;
            currentLevel = new LevelThree(&window);
            currentLevel->nextLevelThreePage = false;
        }
    }

   //delete currentLevel;  // Free the memory for the current level when done
}
Game::~Game() {}