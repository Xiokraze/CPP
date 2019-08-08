#include "pch.h"
#include "Calculations.h"


void doPhysics()
{
	int physicsOption = physicsMenu();
	
	system("CLS");

	switch (physicsOption)
	{
	case 1:
		physicsAcceleration();
		break;
	case 2:
		physicsForceAcceleration();
		break;
	case 3:
		physicsAverageSpeed();
		break;
	case 4:
		physicsVelocity();
		break;
	default:
		break;
	}



	return;
}

// PHYSICS MENU
int physicsMenu()
{

	int physicsOption;
	do
	{
		system("CLS");
		physicsOption = physicsOptions();
		if (physicsOption < 1 || physicsOption > 4) { clearInputBuffer(); }
	} while (physicsOption < 1 || physicsOption > 4);
	//if (menuChoice == "exit") { exit(0); }
	return physicsOption;
}

int physicsOptions()
{
	int physicsOption = printPhysicsOptions();

	if (physicsOption == 1) { return 1; }
	else if (physicsOption == 2) { return 2; }
	else if (physicsOption == 3) { return 3; }
	else if (physicsOption == 4) { return 4; }
	else { return 0; }
}

int printPhysicsOptions()
{
	int physicsOption;
	do
	{
		std::cout << "What do you want to calculate? " << std::endl;
		std::cout << "1) Average Acceleration/Deceleration" << std::endl;
		std::cout << "2) Acceleration From Force" << std::endl;
		std::cout << "3) Average Speed" << std::endl;
		std::cout << "4) Velocity" << std::endl;
		std::cin >> physicsOption;
		if (physicsOption < 1 || physicsOption > 4) { clearInputBuffer(); }
	} while (physicsOption < 1 || physicsOption > 4);
	clearInputBuffer();
	return physicsOption;
}

void physicsAcceleration()
{
	float initialVelocity, finalVelocity, totalTime, acceleration;
	std::cout << "Calculating Average Acceleration/Deceleration: " << std::endl;
	std::cout << "Initial Velocity(m/s): ";
	std::cin >> initialVelocity;
	std::cout << "Final Velocity(m/s): ";
	std::cin >> finalVelocity;
	std::cout << "Time(s): ";
	std::cin >> totalTime;
	acceleration = (finalVelocity - initialVelocity) / totalTime;
	std::cout << "Acceleration = " << acceleration << " (m/s^)2" << std::endl;
	return;
}

void physicsForceAcceleration()
{
	float newtons, mass, acceleration;
	std::cout << "Calculating Acceleration from Force: " << std::endl;
	std::cout << "Force(newtons): ";
	std::cin >> newtons;
	std::cout << "Mass(kg): ";
	std::cin >> mass;
	acceleration = newtons / mass;
	std::cout << "Acceleration = " << acceleration << " (m/s)^2" << std::endl;
	return;
}

void physicsAverageSpeed()
{
	float distance, time, speed;
	std::cout << "Calculating Average Speed: " << std::endl;
	std::cout << "Distance(mi or km): ";
	std::cin >> distance;
	std::cout << "Time(hr): ";
	std::cin >> time;
	speed = distance / time;
	std::cout << speed << " (mi or km)/hr" << std::endl;
	return;
}

void physicsVelocity()
{
	float displacement, time, velocity;
	std::cout << "Calculating Velocity: " << std::endl;
	std::cout << "Displacement(m): ";
	std::cin >> displacement;
	std::cout << "Time(s): ";
	std::cin >> time;
	velocity = displacement / time;
	std::cout << "Velocity = " << velocity << " m/s" << std::endl;
	return;
}