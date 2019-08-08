#include "pch.h"
#include "IsoGrame.h"


void Isogram::printMainMenu()                                   // Primary menu function
{
    int menuChoice;                                             // Initialize menu choice variable
    do                                                          // Get a choice from the player until valid
    {
        system("CLS");                                          // Clear the screen
        menuChoice = menuOptions();                             // Get player's menu option choice
        if (menuChoice == 1) { printTutorial(); }               // Player chose to see the tutorial
        if (menuChoice == 2) { changeColor(); }                 // Player chose to change the color
    } while (menuChoice == 1 || menuChoice == 2);               // If player chose tutorial or color, repeat the menu

    if (menuChoice == 6) { exit(0); }                           // Player chose to quit
    else                                                        // Player chose a difficulty
    { 
        system("CLS");                                          // Clear the screen
        setDifficulty(menuChoice);                              // Set the difficulty to their choice
    }
    return;                                                     // Return from the function
}								


int Isogram::menuOptions()                                      // Gets and returns player's menu choice after validating
{
    int menuOption;                                             // Initialize menu option variable
    std::string menu1 = " 1) Tutorial Message";                 // Initialize tutorial message option
    std::string menu2 = " 2) Change Text Color";                // Initialize change color option
    std::string menu3 = " 3) Easy:   4 Letter Words";           // Initialize easy option
    std::string menu4 = " 4) Medium: 5-6 Letter Words";         // Initialize medium option
    std::string menu5 = " 5) Hard:   7+ Letter Words";          // Initialize hard option
    std::string menu6 = " 6) Quit ";                            // Initialize quit option
    do                                                          // Print the menu options and get the player's choice
    {
        system("CLS");                                          // Clear the screen
        std::cout << startColor;                                // Turn text color encoding on, then print the menu options
		std::cout << menu1 << std::endl;
		std::cout << menu2 << std::endl;
		std::cout << menu3 << std::endl;
		std::cout << menu4 << std::endl;
		std::cout << menu5 << std::endl;
		std::cout << menu6 << std::endl;
        std::cout << endColor;                                  // turn text color encoding off
        std::cin >> menuOption;                                 // Get the menu option
        if (menuOption < 1 || menuOption > 6)                   // If user entered an invalid option
            { clearInputBuffer(); }                             // Clear the input buffer
    } while (menuOption < 1 || menuOption > 6);                 // Keep prompting for a choice if entry is invalid
    clearInputBuffer();                                         // Clear the input buffer
    return menuOption;                                          // Return the menu selection
}


void Isogram::printTutorial()                                   // Prints welcome message tutorial
{
    system("CLS");
    std::cout << startColor << "Welcome to IsoGrame, an Isogram guessing game!\n\n"
		"An Isogram is a word that does not repeat any letters.\n"
		"After you choose a difficulty, you'll have a specified\n"
		"number of guesses to figure out what the hidden word is.\n"
		"After your guess, you will be shown two messages:\n"
		"\"Hot\": How many letters are correct and in the right place.\n"
		"\"Warm\": How many letters are correct, but not in the right place.\n\n"
		"How many guesses will it take you this time?\n\n" << endColor;
    std::cout << std::endl;
    system("PAUSE");                                            // Pause the system so the player can read the tutorial
    return;                                                     // Return from the function
}


void Isogram::changeColor()                                     // Function for changing text color output
{
    system("CLS");                                              // Clear the screen
    int colorChoice = printColorOptions();                      // Print the color options and save the choice

    if (colorChoice == 1) { setColor("\033[1;92m"); }           // Set text color encoding to green
    else if (colorChoice == 2) { setColor("\033[1;94m"); }      // Set text color encoding to blue
    else if (colorChoice == 3) { setColor("\033[1;91m"); }      // Set text color encoding to red
    else if (colorChoice == 4) { setColor("\033[1;93m"); }      // Set text color encoding to yellow
    else if (colorChoice == 5) { setColor("\033[1;95m"); }      // Set text color encoding to magenta
    else if (colorChoice == 6) { setColor("\033[1;36m"); }      // Set text color encoding to cyan
    else { setColor(""); }                                      // Set text color encoding to default
    return;                                                     // Return from the function
}


int Isogram::printColorOptions()                                // Prints menu for player to choose a color
{
    int colorChoice;                                            // Initialize color choice variable
    do                                                          // Get input until a valid choice is entered
    {
        system("CLS");                                          // Clear the screen and print the color option
        std::cout << " Choose a color: " << std::endl;          // Green, blue, red, yellow, magenta, cyan, default
        std::cout << "\033[1;92m 1) Green \033[0m" << std::endl;
        std::cout << "\033[1;94m 2) Blue \033[0m" << std::endl;
        std::cout << "\033[1;91m 3) Red \033[0m" << std::endl;
        std::cout << "\033[1;93m 4) Yellow \033[0m" << std::endl;
        std::cout << "\033[1;95m 5) Magenta \033[0m" << std::endl;
        std::cout << "\033[1;36m 6) Cyan \033[0m" << std::endl;
        std::cout << " 7) Default" << std::endl;
        std::cin >> colorChoice;                                // Get the player's choice
        if (colorChoice < 1 || colorChoice > 7)                 // If input is not a menu option
        {
            clearInputBuffer();                                 // Clear the input buffer
        }
    } while (colorChoice < 1 || colorChoice > 7);               // Keep prompting for a choice until a valid one is given
    clearInputBuffer();                                         // Clear the input buffer
    return colorChoice;                                         // Return the color menu choice
}


void Isogram::setColor(std::string newColor)                    // Sets the chosen color to the class variable
{
    startColor = newColor;
    return;
}


bool Isogram::playAgain()                                       // Returns play again menu selection
{
    int playAgain;
    do                                                          // Get input until a valid choice is given 
    {
        std::cout << "Play again?" << std::endl;
        std::cout << "1) Yes" << std::endl;
        std::cout << "2) No" << std::endl;
        std::cin >> playAgain;                                  // Get the player's choice
        if (playAgain != 1 && playAgain != 2)                   // If input is not a menu option
        { 
            clearInputBuffer();                                 // Clear the input buffer
        }
    } while (playAgain != 1 && playAgain != 2);                 // Keep prompting for a choice until a valid one is given
    if (playAgain == 1) return true;                            // Player wants to play again, return true
    else { return false; }                                      // Player wants to quit, return false
}


void Isogram::reset()                                           // Reset key game variables
{
    gameWonStatus = false;
    currentGuesses = hot = warm = 0;
    hiddenWord = "";
    return;
}


void Isogram::playGame()                                        // Controls the gameplay functionality
{
    if (setHiddenWord() == false)                               // If setting the hidden word failed, print an error and exit
    {
        std::cout << "Error setting the hidden word." << std::endl;
        exit(1);
    }

    setMaxTries();                                              // Set the maximum number of tries
    while (!gameWonStatus && currentGuesses <= maxTries)        // Loop until player wins or exceeds the max number of guesses
    {
        std::string guess = getValidGuess();                    // Get a validated guess from the player
        submitGuess(guess);                                     // Submit the guess
        printClues();                                           // Print the clues to the screen
    }
    printGameSummary();                                         // Print the game summary
    return;                                                     // Return from the function
}


void Isogram::printGameSummary()                                // Print a summary after the game is won or lost
{
    if (gameWonStatus)
    {
        std::cout << startColor;
        std::cout << "Congratulations! You Won!" << std::endl;
        std::cout << endColor << std::endl;
    }
    else
    {
        std::cout << startColor;
        std::cout << "Sorry! Better luck next time!" << std::endl;
        std::cout << "Hidden Word: " << hiddenWord << std::endl;
        std::cout << endColor << std::endl;
    }
    return;
}


void Isogram::printClues()                                      // Prints the hot and warm clue counts
{
    std::cout << startColor;
    std::cout << "Hot: " << hot << std::endl;
    std::cout << "Warm: " << warm << std::endl;
    std::cout << endColor << std::endl;
    return;
}


void Isogram::printTries()                                      // Prints current guess attempt out of max guesses allowed
{
    std::cout << startColor;
    std::cout << "Guess " << currentGuesses;
    std::cout << " of " << maxTries << std::endl;
    std::cout << startColor << "Guess: ";
    std::cout << endColor;
}


void Isogram::setMaxTries()                                     // Set maximum number of tries depending on chosen difficulty
{
    if (difficulty == 3) { maxTries = easyTries; }              // Menu option 3 (easy)
    else if (difficulty == 4) { maxTries = mediumTries; }       // Menu option 4 (medium)
    else maxTries = hardTries;                                  // Menu option 5 (hard)
    return;                                                     // Return from the function
}


void Isogram::clearInputBuffer()                                // Clears the input buffer
{
    std::cin.clear();                                           // Clearn cin buffer
    std::cin.ignore(                                            // Ignore chars up to the max buffer stream size, stop at newline
    	std::numeric_limits<std::streamsize>::max(),
        '\n'
    );
    return;                                                     // Return from the function
}


void Isogram::submitGuess(std::string guess)                    // Compare player's guess to hidden word and tracks hot and warm clues
{
    currentGuesses++;                                           // Increment guess count
    hot = warm = 0;                                             // Reset hot and warm count (recounted with every guess)

    for (int i = 0; i < int(hiddenWord.length()); i++)          // Iterate through the hidden word
    {
        for (int j = 0; j < int(guess.length()); j++)           // Iterate through the guessed word
        {
            if (guess[j] == hiddenWord[i])                      // If a letter in the guessed word is equal to one in the hidden word
            {
                if (i == j) { hot++; }                          // If both positions are the same, increment hot 
                else { warm++; }                                // If both positions are not the same, increment warm
            }
        }
    }

    if (hot == hiddenWord.length())                             // If the number of correct letters = length of the hidden word
    {
        gameWonStatus = true;                                   // Set game won status to true 
    }
    else { gameWonStatus = false; }                             // Game has not yet been won
    return;                                                     // Return from the function
}


std::string Isogram::getValidGuess()                            // Get's player's input and tests validity
{
    std::string guess = "";                                     // Initialize player guess variable
    playerGuessValidity checkGuess = playerGuessValidity::initialized;  // Initialize guess status and set it to initialized

    do                                                          // Continue getting player input until valid
    {
        printTries();                                           // Print the current/max guess count
        std::getline(std::cin, guess);                          // Get player's guess
        checkGuess = checkGuessValidity(guess);                 // Get the validity status of the guess
        validitySwitch(checkGuess);                             // Print appropriate message depending on guess status
    } while (checkGuess != playerGuessValidity::valid);         // Continue getting input until it is valid
    return guess;                                               // Return valid guess
}


void Isogram::validitySwitch(playerGuessValidity validity)      // Responds depending on validity of player's guess
{
    switch (validity)
    {
    case playerGuessValidity::notIsogram:                       // Player entered repeating letters
        std::cout << "Please enter a word without repeating letters." << std::endl;
        std::cout << std::endl;
        break;
    case playerGuessValidity::notLowercase:                     // Player submitted non-lowercase characters
        std::cout << "Please enter only lower case letters." << std::endl;
        std::cout << std::endl;
        break;
    case playerGuessValidity::wrongLength:                      // Player did not submit the correct number of letters
        std::cout << "Please enter a " << hiddenWord.length() << " letter word." << std::endl;
        std::cout << std::endl;
        break;
    default:                                                    // Guess passed the above checks
        break;
    }
    return;                                                     // Return from the function
}


playerGuessValidity Isogram::checkGuessValidity(std::string guess)  // Returns status of player's guess
{
    if (!isIsogram(guess))                                      // If guess is not an isogram
    { 
        return playerGuessValidity::notIsogram;
    }
    else if (!allLower(guess))                                  // If guess contains non-lowercase letters
    { 
        return playerGuessValidity::notLowercase;           
    }
    else if (guess.length() != hiddenWord.length())             // If guess is not the correct length
    { 
        return playerGuessValidity::wrongLength; 
    }
    else { return playerGuessValidity::valid; }                 // Guess is valid
}


bool Isogram::allLower(std::string guess)                       // Tests if guess is all lowercase letters
{
    for (auto letter : guess)                                   // Iterate through all the letters in the guess
    {
        if (!islower(letter)) { return false; }                 // If any are non-lowercase characters, return false
    }
    return true;                                                // Guess characters are valid, return true
}


bool Isogram::isIsogram(std::string guess)                      // Tests if guess has repeating letters
{
    std::map<char, bool> letterSeen;                            // Set up a map for character comparison
    for (auto letter : guess)                                   // Iterate through all the letters in the guess
    {
        letter = tolower(letter);                               // Cast all the letters to one case for accurate comparison
        if (letterSeen[letter]) { return false; }               // If letter repeats, guess is not an isogram
        else { letterSeen[letter] = true; }                     // Else, add it to the map
    }
    return true;                                                // Word is an isogram, return true
}


void Isogram::setDifficulty(int menuChoice)                     // Set game class difficulty to user's choice
{
    
    difficulty = menuChoice;
    return;
}


bool Isogram::setHiddenWord()                                   // Sets hidden word depending on difficulty chosen
{
    int size = getSize();                                       // Get random number dependent on difficulty
    if (difficulty > 0)                                     
    {
        if (difficulty == 3) 
        { 
            hiddenWord = Easy[size]; 
        }
        else if (difficulty == 4) 
        { 
            hiddenWord = Medium[size]; 
        }
        else if (difficulty == 5) 
        { 
            hiddenWord = Hard[size]; 
        }
        return true;
    }
    return false;
}


int Isogram::getSize()                                          // Gets size of the corresponding difficulty array and returns a random word
{
    int difficultySize;
    if (difficulty == 1) 
    { 
        difficultySize = int(sizeof(Easy) / sizeof(Easy[0])); 
    }
    else if (difficulty == 2) 
    { 
        difficultySize = int(sizeof(Medium) / sizeof(Medium[0])); 
    }
    else 
    { 
        difficultySize = int(sizeof(Hard) / sizeof(Hard[0])); 
    }

    srand((unsigned int)time(0));							    // Initialize random number generator
    return rand() % difficultySize + 1;						    // Gets a random number between 1 and the array size
}