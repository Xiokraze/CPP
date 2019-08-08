#pragma once
#include <string>

/*
	Define a node structure for creating
	a linked list of high score values. Each
	node will have a player and score component.
	Name the struct node for easier calling.
*/
typedef struct node
{
	std::string player;
	int score;
	node* next;
} node;

/*
	High scores list class. Handles required
	functions for the above node structure.
*/
class HighScoresList
{
private:
	node *head, *cur, *prev;								// Node pointers for the head, current node, and previous node
	int defaultScoreMax = 5000;
	int defaultScoreMin = 100;
	int defaultScoreDecrement = 500;
	int defaultHighScores = 10;
	int gamePrintDealy = 70;
	int sleepOneSecond = 1000;
	std::string highScoresFile = "highScores.txt";			// File for high scores
	std::string highScoreHeader[6] = {
	"  __     __    _____    __    __    _______   __       __     _____     __    __   ",
	" |  |   |  |  |  _  |  |  |  |  |  |  _____| |  |     |  |   |  _  |   |  |  |  |  ",
	" |  |___|  | |  |_|  | |   | |  | |  |  ___  |   |   |   |  |  |_|  |  |   | |  |  ",
	" |   ___   ||   ___   ||  | ||  ||  |  |__ | |  | |_| |  | |   ___   | |  | ||  |  ",
	" |  |   |  ||  |   |  ||  || |  | |  |___| | |  ||___||  | |  |   |  | |  || |  |  ",
	" |__|   |__||__|   |__||__| |___|  |______|  |__|     |__| |__|   |__| |__| |___|  "
	};
public:
	HighScoresList();										// Initialize node pointer values
	void addNode(std::string player, int score);			// Add node to the list
	void display(std::string, std::string);					// Print the list
	bool newHighScore(int);									// Returns if the player's score is a new high score
	void writeHighScores();									// Writes the high scores list to the file
	void writeFileError();									// Prints appropriate error message
	void printHighScoreHeader(std::string, std::string);	// Prints the header text for the high score page
	std::string getLockedString(std::string);				// Encryption/Decryption
	void populateHighScores(HighScoresList, int);			// Populates high scores if the file is blank
	int getRandomScore();									// Generates a random score
	HighScoresList generateNewHighScores(HighScoresList);	// Generates default high scores if file is empty
	HighScoresList getScores();								// Gets a list of 10 high scores from file and/or generation
};