#include "pch.h"
#include "Stories.h"

void VacationTime()
{
	// Clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	std::string Alarm1, Alarm2, Place, Time, Action, Movement1, Adjective1;
	std::string Clothing1, Clothing2, Size, Food, Adjective2, Vehicle;
	int Number;

	std::cout << "Answer the following prompts:" << std::endl;
	std::cout << std::endl;
	std::cout << "A sound: ";
	getline(std::cin, Alarm1);
	std::cout << "Another sound: ";
	getline(std::cin, Alarm2);
	std::cout << "A place: ";
	getline(std::cin, Place);
	std::cout << "A number greater than 1: ";
	std::cin >> Number;

	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');


	std::cout << "Plural measurement of time: ";
	getline(std::cin, Time);
	std::cout << "An action describing movement: ";
	getline(std::cin, Movement1);
	std::cout << "Action adjective in -ly: ";
	getline(std::cin, Adjective1);
	std::cout << "Something you wear, singular: ";
	getline(std::cin, Clothing1);
	std::cout << "Something you wear, plural: ";
	getline(std::cin, Clothing2);
	std::cout << "Adjective describing size: ";
	getline(std::cin, Size);
	std::cout << "A single food item: ";
	getline(std::cin, Food);
	std::cout << "An adjective: ";
	getline(std::cin, Adjective2);
	std::cout << "Something you drive: ";
	getline(std::cin, Vehicle);
	std::cout << std::endl;

	std::cout << Alarm1 + " " + Alarm2 + " " + Alarm1 + " " + Alarm2 + " ";
	std::cout << "... your alarm pulls you from a deep slumber..." << std::endl;
	std::cout << "Oh yea! It's time to get up and go to " + Place + "!" << std::endl;
	std::cout << "You've been looking foward to this for " + std::to_string(Number) + " whole " + Time + "!" << std::endl;
	std::cout << "You " + Movement1 + " yourself out of bed and " + Adjective1 + " run over to your dresser." << std::endl;
	std::cout << "So excited! What " + Clothing1 + " should I wear?" << std::endl;
	std::cout << "I know! I'll find something in my " + Clothing2 + " drawer!" << std::endl;
	std::cout << "You grab a " + Size + " " + Food + " and run out of the door with your keys." << std::endl;
	std::cout << "You jump down the stairs, head across the yard, and take off in your " + Adjective2 + " ";
	std::cout << Vehicle + " to go to " + Place + "!\n" << std::endl;

	return;
}