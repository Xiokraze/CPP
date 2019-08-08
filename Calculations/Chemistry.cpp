#include "pch.h"
#include "Calculations.h"


void doChemistry()
{
	int chemistryOption = chemistryMenu();

	system("CLS");

	switch (chemistryOption)
	{
	case 1:
		chemistryDensity();
		break;
	/*case 2:
		chemistryMassFromMoles();
		break;*/
	default:
		break;
	}



return;
}

// CHEMISTRY MENU
int chemistryMenu()
{

	int chemistryOption;
	do
	{
		system("CLS");
		chemistryOption = chemistryOptions();
		if (chemistryOption < 1 || chemistryOption > 1) { clearInputBuffer(); }
	} while (chemistryOption < 1 || chemistryOption > 1);
	//if (menuChoice == "exit") { exit(0); }
	return chemistryOption;
}

int chemistryOptions()
{
	int chemistryOption = printChemistryOptions();

	if (chemistryOption == 1) { return 1; }
	//else if (chemistryOption == 2) { return 2; }
	else { return 0; }
}

int printChemistryOptions()
{
	int chemistryOption;
	do
	{
		std::cout << "What do you want to calculate? " << std::endl;
		std::cout << "1) Density" << std::endl;
		std::cin >> chemistryOption;
		if (chemistryOption < 1 || chemistryOption > 1) { clearInputBuffer(); }
	} while (chemistryOption < 1 || chemistryOption > 1);
	clearInputBuffer();
	return chemistryOption;
}

void chemistryDensity()
{
	float mass, volume, density;
	std::cout << "Calculating Density:" << std::endl;
	std::cout << "Mass(g): ";
	std::cin >> mass;
	std::cout << "Volume(mL): ";
	std::cin >> volume;
	density = mass / volume;
	std::cout << "Density = " << density << " g/mL" << std::endl;
	return;
}
