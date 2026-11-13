#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Player
{
private:
	string username;		   // user name of the player
	int currentLvl;			   // level the player is currently on
	int score;			       // score of the player
	int hints;				   //  hints of player
	const int MAX_HINTS = 5;   // maximum hints
	Texture* avator;           // avatar player chooses
public:
	Player(string username, Texture& img);   // constructor will receive name and avator arguments, the other attributes are set to zero
	string getName() const { return username; }
	int getCurrentLvl() const { return currentLvl; }
	int getScore() const { return score; }
	int getHints() const { return hints; }
	void reduceHints() { hints--; };
	void setAvatar(Texture& t) { avator = &t; }
	void setScore(int score) { this->score = score; }
	void setLevel(int lvl) { this->currentLvl = lvl; }
};