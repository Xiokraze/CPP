// FunWordStory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "FunWordStory.h"
#include "Stories.h"

int main()
{
	do {
		PlayIntro();
		PlayGame(ChooseGame());
	} while (PlayAgain() == true);

	return 0;
}

// Introduce the Game
void PlayIntro()
{
	std::cout << "\n\nWelcome to FunWordStory, where you decide the details of the story!\n" << std::endl;
	if (PlayTutorial())
	{
		std::string Color, Object;
		std::cout << "\nTutorial coming right up!\n" << std::endl;
		std::cout << "I'm going to tell a story and I'll ask you for keywords in certain locations." << std::endl;
		std::cout << "For example, I might have a sentence similar to the following:" << std::endl;
		std::cout << "\nI saw a small ____ today and it was an intersting shade of ____." << std::endl;
		std::cout << "However, the sentence would be hidden from you until I get all of your keywords." << std::endl;
		std::cout << "\nFor example, give me a color: ";
		std::getline(std::cin, Color);
		std::cout << "Great, now give me an object! ";
		std::getline(std::cin, Object);
		std::cout << "Now I'll take what you gave me and complete the sentence!\n" << std::endl;
		std::cout << "I saw a small " + Object + " today and it was an intersting shade of " + Color + ".\n" << std::endl;
		std::cout << "And that's all there is to it! Let's write a story together!\n\n" << std::endl;
	}
	else { std::cout << "\nAlrighty! Once upon a time... kidding!\n\n"; }
	return;
}


// Ask to play introduction
bool PlayTutorial()
{
	std::cout << "Would you like to see a quick tutorial (Y/N)? ";
	std::string Response;
	do {
		getline(std::cin, Response);
		tolower(Response[0]);
		if (Response[0] == 'y') { return true; }
		if (Response[0] == 'n') { return false; }
	} while (Response[0] != 'y' && Response[0] != 'n');
	return false;
}

// Ask to play again
bool PlayAgain()
{
	std::cout << "Would you like to play again (Y/N)? ";
	std::string Response;
	do {
		getline(std::cin, Response);
		tolower(Response[0]);
		if (Response[0] == 'y') { return true; }
		if (Response[0] == 'n') { return false; }
	} while (Response[0] != 'y' && Response[0] != 'n');
	return false;
}

int ChooseGame()
{
	int Choice;
	std::cout << "Which story would you like to play? " << std::endl;;
	std::cout << "1) Vacation Time!" << std::endl;
	do {
		std::cout << "\nEnter the story number: ";
		std::cin >> Choice;
	} while (Choice < 1 || Choice > 1);

	return Choice;
}

void PlayGame(int GameChoice)
{
	switch (GameChoice) {
	case 1: 
		VacationTime();
		break;
	}

	return;
}

