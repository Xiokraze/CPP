#include "pch.h"
#include "Calculations.h"

int main()
{
	int calculation = mainMenu();

	switch (calculation)
	{
	case 1:
		doPhysics();
		break;
	case 2:
		doChemistry();
		break;
	default:
		break;
	}

	return 0;
}

int mainMenu()
{
	int menuOption;
	do
	{
		system("CLS");
		menuOption = menuOptions();
		if (menuOption < 1 || menuOption > 2) { clearInputBuffer(); }
	} while (menuOption < 1 || menuOption > 2);
	//if (menuChoice == "exit") { exit(0); }
	return menuOption;
}

int menuOptions()
{
	int menuOption = printMenuOptions();

	if (menuOption == 1) { return 1; }
	else if (menuOption == 2) { return 2; }
	//else if (menuOption == 3) { return 3; }
	else { return 0; }

}

int printMenuOptions()
{
	int menuOption;
	do
	{
		std::cout << "Choose your subject: " << std::endl;
		std::cout << "1) Physics" << std::endl;
		std::cout << "2) Chemistry" << std::endl;
		std::cin >> menuOption;
		if (menuOption < 1 || menuOption > 2) { clearInputBuffer(); }
	} while (menuOption < 1 || menuOption > 2);
	clearInputBuffer();
	return menuOption;
}

// Clears the input buffer after players picked integer menu options
void clearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(
		std::numeric_limits<std::streamsize>::max(),
		'\n'
	);

	return;
}