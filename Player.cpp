#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
Player::Player(string username, Texture& t) {
	this->currentLvl = 0;
	this->score = 0;
	this->username = username;
	this->avator = &t; // Store reference as pointer
	this->hints = MAX_HINTS;
}
 