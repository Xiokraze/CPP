#include "pch.h"
#include "Hangman.h"

// MAIN MENU****************************************************************
void HangmanGame::printMainMenu(HighScoresList highScores)              // Prints the main menu options          
{
    int menuChoice;                                                     // Initialize choice variable
    do                                                                  // Get user input until a valid choie is entered
    {
        system("CLS");                                                  // Clear the screen
        printTitleImage();                                              // Print the title image
        menuChoice = getMenuOptions();                                  // Get the menu choice input from the player
        if (menuChoice == 2) { changeColor(); }                         // Player chose to change the text color
        if (menuChoice == 3) { printHighScores(highScores); }           // Player chose to see the high scores
    } while (menuChoice != 1 && menuChoice != 4);                       // Keep repeating the menu until player chooses to play or quit

    if (menuChoice == 4) { exit(0); }                                   // Player chose to quit
    else { system("CLS"); }                                             // Player chose to play, clear the screen
    return;                                                             // Return from the function
}

void HangmanGame::printHighScores(HighScoresList highScores) const      // Controls printing the high scores list
{
    highScores.display(startColor, endColor);                           // Print the high scores
    system("PAUSE");                                                    // Pause the system until the player is ready to continue
    return;                                                             // Return from the function
}

void HangmanGame::printTitleImage() const                               // Prints the Hangman title and gallows image
{
    std::string titleImage[15] = {
		"  __     __    _____    __    __    _______   __       __     _____     __    __   ",
		" |  |   |  |  |  _  |  |  |  |  |  |  _____| |  |     |  |   |  _  |   |  |  |  |  ",
		" |  |___|  | |  |_|  | |   | |  | |  |  ___  |   |   |   |  |  |_|  |  |   | |  |  ",
		" |   ___   ||   ___   ||  | ||  ||  |  |__ | |  | |_| |  | |   ___   | |  | ||  |  ",
		" |  |   |  ||  |   |  ||  || |  | |  |___| | |  ||___||  | |  |   |  | |  || |  |  ",
		" |__|   |__||__|   |__||__| |___|  |______|  |__|     |__| |__|   |__| |__| |___|  ",
		"     ___________                                                   ___________     ",
		"    | /        Y                                                   Y        \\ |    ",
		"    |/                                                                       \\|    ",
		"    |                                                                         |    ",
		"    |                                                                         |    ",
		"    |                                                                         |    ",
		"    |                                                                         |    ",
		"   /|\\                                                                      /|\\    ",
		" _/_|_\\____________________________________________________________________/_|_\\_  "
    };

    for (int i = 0; i < sizeof(titleImage) / sizeof(std::string); i++)	// Loop trough the title image array
    {
        for (int j = 0; j < int(titleImage[i].length()); j++)           // Loop through each character in the array line
        {
            std::cout << startColor << titleImage[i][j] << endColor;    // Print the character at the row/column location
        }
        std::cout << std::endl;                                         // Print an additional newline
        Sleep(70);                                                      // Delay the system
    }
    std::cout << std::endl;                                             // Print an additional newline
    std::cout << std::endl;                                             // Print an additional newline
    return;                                                             // Return from the function
}

int HangmanGame::getMenuOptions()                                       // Gets and returns appropriate menu option selection
{
    return printMenuOptions();
}

void HangmanGame::changeColor()                                         // Controls changing the text color encoder
{
    system("CLS");                                                      // Get player's color choice
    int colorChoice = printColorOptions();

    if (colorChoice == 1) { setColor("\033[1;92m"); }                   // Green
    else if (colorChoice == 2) { setColor("\033[1;94m"); }              // Blue
    else if (colorChoice == 3) { setColor("\033[1;91m"); }              // Red
    else if (colorChoice == 4) { setColor("\033[1;93m"); }              // Yellow
    else if (colorChoice == 5) { setColor("\033[1;95m"); }              // Magenta
    else if (colorChoice == 6) { setColor("\033[1;36m"); }              // Cyan
    else { setColor(""); }                                              // Default
    return;                                                             // Return from the function
}

int HangmanGame::printColorOptions()                                    // Prints and get's the player
{
    int colorChoice;                                                    // Initialize variable for player's color choice
    std::string colorOptions[8] = {                                     // Initialize array for holding color options
        " Choose a color: ",
        "\033[1;92m 1) Green \033[0m",                                  // Green
        "\033[1;94m 2) Blue \033[0m",                                   // Blue
        "\033[1;91m 3) Red \033[0m",                                    // Red
        "\033[1;93m 4) Yellow \033[0m",                                 // Yellow
        "\033[1;95m 5) Magenta \033[0m",                                // Magenta
        "\033[1;36m 6) Cyan \033[0m",                                   // Cyan
        " 7) Default"                                                   // Default
    };
    
    do                                                                  // Get input from player until a valid choice is entered   
    {
        system("CLS");                                                  // Clear the screen
        int size = (sizeof(colorOptions) / sizeof(colorOptions[0]));    // Save the size of the first array row
        for (int i = 0; i < size; i++)                                  // Iterate through the array rows
        {
            std::cout << colorOptions[i] << std::endl;                  // Print the row
            Sleep(70);                                                  // Delay the system
        }
        std::cin >> colorChoice;                                        // Get the player's color choice
        if (colorChoice < 1 || colorChoice > 7)                         // If the choice is not a valid entry
        {
            clearInputBuffer();                                         // Clear the input buffer
        }
    } while (colorChoice < 1 || colorChoice > 7);                       // Get player's choice until it's valid
    clearInputBuffer();                                                 // Clear the input buffer
    return colorChoice;                                                 // Return the player's color choice
}

int HangmanGame::printMenuOptions()                                     // Prints the main menu options and returns player's choice
{
    int menuOption;                                                     // Initialize menu option variable
    do                                                                  // Get player's input until a valid choice is entered
    {
        std::cout << startColor;                                        // Turn text color encoding on
        std::cout << " 1) Play Game" << std::endl;
        std::cout << " 2) Change Text Color" << std::endl;
        std::cout << " 3) High Scores" << std::endl;
        std::cout << " 4) Quit " << std::endl;
        std::cout << endColor;                                          // Turn text color encoding off
        std::cin >> menuOption;                                         // Get player's input choice
        if (menuOption < 1 || menuOption > 4)                           // If player's choice is not a valid option
        { 
            clearInputBuffer();                                         // Clear the input buffer
        }
    } while (menuOption < 1 || menuOption > 4);                         // Get player's choice until it's valid
    clearInputBuffer();                                                 // Clear the input buffer
    return menuOption;                                                  // Return the player's menu choice
}


// GAME CONTROL*************************************************************
void HangmanGame::reset()                                               // Resets the key game variables
{
    gameScore = 0;                                                      // Reset session score to 0
    gameWonStatus = false;                                              // Reset game won to false
    currentWrongGuesses = 0;                                            // Reset wrong guess count
    guessedLetters.clear();                                             // Clear guessed letters vector
    correctLetters.clear();                                             // Clear correct letters vector
    incorrectLetters.clear();                                           // Clear incorrect letters vector
    return;                                                             // Return from the function
}

void HangmanGame::playGame()                                            // Controls primary game loop
{
    setHiddenWord();                                                    // Generate and set the hidden word
    while (1)                                                           // Play until the game is won or lost
    {
        system("CLS");                                                  // Clear the screen
        printGallows();                                                 // Print the gallows image
        if (currentWrongGuesses < 6)                                    // If player has guesses left
        {
            printLetters();                                             // Print the letters
            if (!gameWonStatus)                                         // If game is not won
            {
                submitGuesses();                                        // Get and submit a guess
            }
            else { break; }                                             // Game was won, exit loop
        }
        else { break; }                                                 // Game was lost, exit loop
    }
    return;                                                             // Return from the function
}

std::string HangmanGame::generateHiddenWord()                           // Generates and returns the hidden word
{
    int wordBankSize = (sizeof(wordBank) / sizeof(std::string));        // Get the size of the word bank array
    srand((unsigned int)time(0));                                       // Seed the random number generator
    int randomNumber = (((rand() % wordBankSize) + 1));                 // Generate a random number (1-# of total words)
    return wordBank[randomNumber];                                      // Return the randomly generated word
}

void HangmanGame::clearInputBuffer()                                    // Clears the input buffer
{
    std::cin.clear();                                                   // Clear cin
    std::cin.ignore(                                                    // Clear ignore anything up to a newline
	    std::numeric_limits<std::streamsize>::max(),
	    '\n'
    );
    return;                                                             // Return from the function
}


// PLAY AGAIN **************************************************************
bool HangmanGame::playAgain()                                           // Asks if the player wants to play again
{
    int playAgainOption;                                                // Initialize play again variable
    do                                                                  // Get player's choice
    {
        playAgainOption = printPlayAgainOptions();                      // Get player's choice
        if (playAgainOption != 1 && playAgainOption != 2)               // If choice is not valid
        { 
            clearInputBuffer();                                         // Clear the input buffer
        }
    } while (playAgainOption != 1 && playAgainOption != 2);             // Exit loop if choice is valid
    if (playAgainOption == 1)                                           // If player wants to play again
    {
        if (newColor()) { changeColor(); }                              // See if the player wants to change the text color
        return true;                                                    // Return True
    }
    return false;                                                       // Player wants to quit
}

int HangmanGame::printPlayAgainOptions()                                // Prints and returns the play again options
{
    int playAgainOption;                                                // Initialize play again variable
    do                                                                  // Get player's choice
    {
        std::cout << startColor;                                        // Turn on text color encoding
        std::cout << "Play again?" << std::endl;
        std::cout << " 1) Yes" << std::endl;
        std::cout << " 2) No" << std::endl;
        std::cout << endColor;                                          // Turn off text color encoding
        std::cin >> playAgainOption;                                    // Get player's choice
        if (playAgainOption != 1 && playAgainOption != 2)               // If player's choice is not valid
        {
            clearInputBuffer();                                         // Clear the input buffer
        }
    } while (playAgainOption != 1 && playAgainOption != 2);             // Get input until valid
    clearInputBuffer();                                                 // Clear the input buffer
    return playAgainOption;                                             // Return the play again choice
}

bool HangmanGame::newColor()                                            // Returns true or false if player wants to pick a new text color
{
    int newColorOption;                                                 // Initialize player choice variable
    do                                                                  // Get player's choice
    {
        newColorOption = printNewColorOptions();                        // Check if player wants to pick a new color
        if (newColorOption != 1 && newColorOption != 2)                 // If player's choice is not valid
        { 
            clearInputBuffer();                                         // Clear the input buffer
        }
    } while (newColorOption != 1 && newColorOption != 2);               // Get player's choice until valid
    if (newColorOption == 1) { return true; }                           // Player wants to pick a new color, return true
    else { return false; }                                              // Player doesn't want a new color, return false
}

int HangmanGame::printNewColorOptions()                                 // Prints new color prompt and returns input
{
	int newColorOption;
	std::cout << startColor << "Would you like to choose a new text color?" << endColor << std::endl;
	std::cout << startColor << " 1) Yes" << endColor << std::endl;
	std::cout << startColor << " 2) No" << endColor << std::endl;
	std::cin >> newColorOption;
	clearInputBuffer();
	return newColorOption;
}


// GAME SUMMARY ************************************************************
std::string HangmanGame::getPlayerName()                                // Get's player's initials for saving their high score
{
    std::string playerName = "";                                        // Initialze player name variable
    bool onlyLetters = false;                                           // Flag for input validation
    do                                                                  // Get player initials input
    {
        std::cout << startColor << "Enter player name (3 letters): " << endColor;
        std::getline(std::cin, playerName);
        onlyLetters = checkName(playerName);                            // Validate the input
    } while (playerName.length() != 3 || onlyLetters == false);         // Get input until valid
    return playerName;                                                  // Return the player's name
}

bool HangmanGame::checkName(std::string name)                           // Checks that only letters have been entered in the player's name
{
    for (int i = 0; i < int(name.length()); i++)                        // Iterate through the player's name
        if (!isalpha(name[i]))                                          // If a character is not a letter
        {
            return false;                                               // Return false
        }
    return true;                                                        // Name is valid, return true
}

void HangmanGame::printGameSummary()                                    // Prints the game summary
{
	if (gameWonStatus)
	{
        std::cout << startColor;
        std::cout << "Congratulations! You Won!" << std::endl;
        std::cout << endColor;
	}
	else
	{
        std::cout << startColor;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Sorry, better luck next time!" << std::endl;
		std::cout << std::endl;
		std::cout << "The hidden word was: " << hiddenWord << std::endl;
		std::cout << std::endl;
        std::cout << endColor;
	}
	return;
}

void HangmanGame::printTotalScore(int totalScore)                       // Prints the total score or new high score message
{
	if (newHighScore)
	{
		std::cout << startColor << "NEW HIGH SCORE! " << endColor;
	}
	else
	{
		std::cout << startColor << "Total Score: " << endColor;
	}
	std::cout << startColor << totalScore << endColor << std::endl;
	std::cout << std::endl;
	return;
}


// CLUE/INFORMATION ********************************************************
void HangmanGame::printGallows() const                                  // Prints the gallows image
{
    std::string getGallows[9] = {                                       // Initialize the gallows image
		"     ___________",
		"    | /        Y",
		"    |/         ",
		"    |         ",
		"    |         ",
		"    |         ",
		"    |           ",
		"   /|\\         ",
		" _/_|_\\________"
	};

    int size = (sizeof(getGallows) / sizeof(getGallows[0]));            // Size of the first row of the gallows
    for (int i = 0; i < size; i++)                                      // Loop through each gallows row
	{
        switch (i) {                                                    // Print each line of the image depented upon number of wrong guesses
        case 0:                                                         // Print the top of the gallows
            std::cout << startColor;
            std::cout << getGallows[i] << std::endl;
            std::cout << endColor;
            break;
        case 1:                                                         // Print the noose and next row of the gallows
            std::cout << startColor;
            std::cout << getGallows[i] << std::endl;
            std::cout << endColor;
            break;
        case 2:                                                         // Prints the head or a blank
            if (currentWrongGuesses >= 1)                               // If there is one or more wrong answers
            {
                std::cout << startColor;
                std::cout << getGallows[i] << "O" << std::endl;         // Print the head
                std::cout << endColor;
            }
            else {                                                      // If there are no wrong guesses
                std::cout << startColor;
                std::cout << getGallows[i] << std::endl;                // Print the corresponding empty gallows line
                std::cout << endColor;
            }
            break;
        case 3:                                                         // Prints the chest, left arm, right arm, or empty gallows line
            if (currentWrongGuesses == 2)                               // If there are two wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << " |" << std::endl;        // Print the chest
                std::cout << endColor;
            }
            else if (currentWrongGuesses == 3)                          // If there are three wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << "\\|" << std::endl;       // Print the chest and left arm
                std::cout << endColor;
            }
            else if (currentWrongGuesses >= 4)                          // If there are 4 wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << "\\|/" << std::endl;      // Print the chest, left arm, and right arm
                std::cout << endColor;
            }
            else                                                        // If there are less than 2 wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << std::endl;                // Print the corresponding empty gallows line
                std::cout << endColor;
            }
            break;
        case 4:                                                         // Prints the lower body or empty gallows line
            if (currentWrongGuesses >= 2)                               // If there are more than 2 wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << " |" << std::endl;        // Print the lower body
                std::cout << endColor;
            }
            else                                                        // If there are 2 or fewer wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << std::endl;                // Print the corresponding empty gallows line
                std::cout << endColor;
            }
            break;
        case 5:                                                         // Prints the left leg, right leg, or empty gallows line
            if (currentWrongGuesses == 5)                               // If there are 5 wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << "/" << std::endl;         // Print the left leg
                std::cout << endColor;
            }
            else if (currentWrongGuesses == 6)                          // If there are six wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << "/ \\" << std::endl;      // Print the left and right legs
                std::cout << endColor;
            }
            else                                                        // If there are less than 5 wrong guesses
            {
                std::cout << startColor;
                std::cout << getGallows[i] << std::endl;                // Print the corresponding empty gallows line
                std::cout << endColor;
            }
            break;
        case 6:                                                         // Print the rest of the gallows image
            std::cout << startColor;
            std::cout << getGallows[i] << std::endl;
            std::cout << endColor;
			break;
		case 7:
            std::cout << startColor;
            std::cout << getGallows[i] << std::endl;
            std::cout << endColor;
			break;
		case 8:
            std::cout << startColor;
            std::cout << getGallows[i] << std::endl;
            std::cout << endColor;
			break;
		case 9:
            std::cout << startColor;
            std::cout << getGallows[i] << std::endl;
            std::cout << endColor;
			break;
		}
	}
	return;
}

void HangmanGame::printLetters()                                        // Prints the score, correct and incorrect letters
{
	printIncorrectLetters();
	printCorrectLetters();
	printScore();
	return;
}

void HangmanGame::printScore() const                                    // Prints new high score message and current score
{
	if (newHighScore)                                                   
	{
		std::cout << startColor << "NEW HIGH SCORE! " << endColor;
	}
	std::cout << startColor << "Current Score: " << gameScore << endColor;
	std::cout << std::endl;
	return;
}

void HangmanGame::printCorrectLetters()
{
	std::cout << std::endl;
	std::cout << std::endl;
    bool found = false;                                                 // Initialize flag for character comparision
    int hangmanVictoryCheck = 0;                                        // Victory status flag
    for (int i = 0; i < int(hiddenWord.length()); i++)                  // Iterate through each character in the hidden word
    {
        found = false;                                                  // Reset the found flag to false each iteration
        for (int j = 0; j < int(correctLetters.size()); j++)            // Iterate through the correct letters
        {
            if (correctLetters.at(j) == hiddenWord[i])                  // If the current letter matches the hidden word character
            {
            	++hangmanVictoryCheck;                                  // Increment the correct letter victory counter
            	if (hangmanVictoryCheck == hiddenWord.length())         // If all the letters have been found
            	{
            	    gameScore += winBonus;
            	    gameScore += getGuessesLeftBonus();
            	    setVictory();                                       // Then the player won!
            	}
            	found = true;                                           // Set found to true
            	break;
            }
    	}
		/*
			If the letter is found, the guess matches a letter in the
			hidden word. Add it to the correct letters
		*/
		if (found) { std::cout << startColor << " " << hiddenWord[i] << " " << endColor; }
		else { std::cout << startColor << " _ " << endColor; }
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return;
}

void HangmanGame::printIncorrectLetters()
{
	// If there are wrong answers, print a newline and print the incorrect letters
	std::cout << std::endl;
	std::cout << startColor << "Incorrect Letters:" << endColor;
	for (int i = 0; i < int(incorrectLetters.size()); i++)
	{
		std::cout << startColor << " " << char(incorrectLetters.at(i)) << " " << endColor;
	}

	return;
}


// PLAYER GUESS ************************************************************
void HangmanGame::submitGuesses()                                       // Assigns game class guess variable to the player's input guess
{
	char guess = getPlayerGuess();
	return;
}

char HangmanGame::getPlayerGuess()                                      // Checks guess validity, then returns the character
{
    std::string playerGuess;                                            // Initialize the player guess variable
    validGuess checkLetter = validGuess::initialized;                   // Initialize validity status variable
    do
    {
        std::cout << startColor << "Guess a letter: " << endColor;
        std::getline(std::cin, playerGuess);
        checkLetter = checkGuessValidity(playerGuess);
        if (checkLetter != validGuess::valid)                           // If the guess is not valid
        {
            printGuessStatus(checkLetter);                              // Print corresponding invalid message
        }
    } while (checkLetter != validGuess::valid);                         // Loop until user enters a valid character
    saveGuesses(playerGuess[0]);                                        // Save the guessed character
    return playerGuess[0];                                              // Return the guessed character
}

void HangmanGame::saveGuesses(char playerGuess)                         // Saves the player's guesses and adds consecutive guess bonus
{
    guessedLetters.push_back(playerGuess);                              // Add the guessed character to the guessed letters vector
    if (correctGuess(playerGuess))                                      // If the guess is correct
    {
        correctLetters.push_back(playerGuess);                          // Add the guessed character to the correct letters vector
        if (consecutiveCorrectGuesses)                                  // If correct letters are guessed consecutively
        {
            gameScore += consecutiveGuessBonus;                         // Add the consecutive guess bonus to the game score
        }
        consecutiveCorrectGuesses = true;                               // Set consecutive guess flag to true with correct guesses
    }
    else                                                                // If the guess is incorrect
    {
        consecutiveCorrectGuesses = false;                              // Set consecutive guess flag to false
        incorrectLetters.push_back(playerGuess);                        // Add the letter to the incorrect letters vector
        ++currentWrongGuesses;                                          // Increment incorrect guesses count
    }
    return;                                                             // Return from the function
}

bool HangmanGame::correctGuess(char playerGuess)                        // Checks if the guessed letter is correct
{
    bool correctGuess = false;                                          // Correct guess flag
    for (int i = 0; i < int(hiddenWord.length()); i++)                  // Iterate through the hidden word
    {
        if (playerGuess == hiddenWord[i])                               // If the guess matches a letter (duplicates count)
        {
            correctGuess = true;                                        // Set correct guess flag to true
            gameScore += correctGuessBonus;                             // Add correct guess bonus to the game score
        }
    }
    return correctGuess;                                                // Return the letter
}

void HangmanGame::printGuessStatus(validGuess playerGuessStatus)
{
    switch (playerGuessStatus)
    {
    case validGuess::noInput:                                           // No input was given
        std::cout << startColor;
    	std::cout <<"Guess a letter!" << std::endl;
        std::cout << endColor;
    	break;
    case validGuess::moreThanOneLetter:                                 // Entered too many letters
        std::cout << startColor;
    	std::cout << "Enter only one letter!" << std::endl;
        std::cout << endColor;
    	break;
    case validGuess::notALowercaseLetter:                               // Entered uppercase letters
        std::cout << startColor;
    	std::cout << "Enter only lowercase letters! " << std::endl;
        std::cout << endColor;
    	break;
    case validGuess::notLetter:                                         // A non-letter character was entered
        std::cout << startColor;
    	std::cout << "Enter only letters!" << std::endl;
        std::cout << endColor;
    	break;
    case validGuess::duplicate:                                         // Entered a duplicate letter
        std::cout << startColor;
    	std::cout << "You already gussed that letter!" << std::endl;
        std::cout << endColor;
    	break;
    default:
    	break;
    }
    return;
}

validGuess HangmanGame::checkGuessValidity(std::string playerGuess)
{
    if (playerGuess.length() == 0 || playerGuess[0] == 0)               // No input was given
    {
    	return validGuess::noInput;
    }
    else if (playerGuess.length() > 1)                                  // More than one character was entered
    {
    	return validGuess::moreThanOneLetter;
    }
    else if (playerGuess[0] >= 65 && playerGuess[0] <= 90)              // Uppercase letter was entered
    {
    	return validGuess::notALowercaseLetter;
    }
    else if (playerGuess[0] < 97 || playerGuess[0] > 122)               // Non-lowercase and non-letter character was entered
    {
    	return validGuess::notLetter;
    }
    else if (checkDuplicate(playerGuess[0]))                            // If the checkDuplicate function returns true, the letter has already been guessed
    {
    	return validGuess::duplicate;
    }
    else                                                                // If previous checks passed, guess is valid
    {
    	return validGuess::valid;
    }
}

bool HangmanGame::checkDuplicate(char letter) const                     // Checks for repeated guessed letters
{
    for (int i = 0; i < int(guessedLetters.size()); i++)                // Iterate through the guessed letters vector
    {
        if (letter == int(guessedLetters.at(i)))                        // If the guess is found in the vector
        {
            return true;                                                // Duplicate found
        }
    }
    return false;                                                       // If we got through the vector, no duplicate was found
}


// GETTERS******************************************************************
std::string HangmanGame::getStartColor() { return startColor; }

std::string HangmanGame::getEndColor() { return endColor; }

int HangmanGame::getCurrentScore() { return gameScore; }

int HangmanGame::getGuessesLeftBonus()
{
	return (maxWrongGuesses - currentWrongGuesses) * remainingGuessBonus;
}

void HangmanGame::getNewHighScoreStatus(bool highScore)
{
	if (highScore) { newHighScore = true; }
	return;
}


// SETTERS******************************************************************
void HangmanGame::setColor(std::string newColor)
{
	startColor = newColor;
	return;
}

void HangmanGame::setHiddenWord()
{
	hiddenWord = generateHiddenWord();
	return;
}

void HangmanGame::setVictory() { gameWonStatus = true; }