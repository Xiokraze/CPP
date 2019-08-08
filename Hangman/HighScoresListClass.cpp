#include "pch.h"
#include "Hangman.h"



// HIGH SCORES FUNCTIONS
// Class constructor, initializes node pointer values
HighScoresList::HighScoresList()	
{
	head = cur = prev = NULL;
}

// Add node to the list
void HighScoresList::addNode(std::string player, int score)
{
    node *newNode = new node;                                                   // Create a new node
	newNode->player = player;
	newNode->score = score;
	newNode->next = NULL;

    if (head == NULL) { head = newNode; }                                       // If there is no list, create head
    else
    {
        node *cur, *prev;                                                       // Initialize current and previous node pointers
        for (prev = cur = head;; cur = cur->next)                               // Iterate through the current list
        {
            if (newNode->score > cur->score && cur == head)                     // If current score > the head
            {
                newNode->next = head;                                           // Assign newnode's next pointer to the head
                head = newNode;                                                 // Assign the head to newnode
                break;
            }
            if (newNode->score > cur->score)                                    // If current score > current score
            {
                newNode->next = cur;                                            // Assign newnode's next to the current node
                prev->next = newNode;                                           // Assign the previous nodes next to newnode
                break;
            }
            if (cur->next == NULL)                                              // If we got to the end of the list
            {
                cur->next = newNode;                                            // Add the node to the end of the list
                break;
            }
            prev = cur;                                                         // Assign the previous node to the current one
        }
    }
}

// Print the high scores list
void HighScoresList::display(std::string startColor, std::string endColor)
{
	int scoreRank = 1;
	node *tmp;
	system("CLS");
	printHighScoreHeader(startColor, endColor);
    for (tmp = head; tmp != NULL; tmp = tmp->next)                              // Iterate through the high scores list
	{
		std::cout << startColor << std::setw(3) << scoreRank++;
        std::cout << ". " << tmp->player << "..........";                       // Print the player
        printf("%08d", tmp->score);                                             // Print the score
		std::cout << endColor << std::endl;
        Sleep(gamePrintDealy);                                                  // Delay the system (adds an old-school visual effect)
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return;
}

// Returns if the player's score is a new high score
bool HighScoresList::newHighScore(int totalScore)
{
    for (node* tmp = head; tmp != NULL; tmp = tmp->next)                        // Iterate through the high scores list
    {
        if (totalScore > tmp->score) { return true; }                           // Return true if player achieves a high score
    }
    return false;                                                               // Return false if player did not get a high score
}

// Writes the high scores list to the file
void HighScoresList::writeHighScores()
{
    std::ofstream writeScores;                                                  // Output stream for writing to the file
    std::string lockedPlayer = "";
    std::string lockedScore = "";
    writeScores.open(highScoresFile);                                           // Open the file for writing

    if (writeScores.is_open())                                                  // If the file opened correctly
    {
        for (node* tmp = head; tmp != NULL; tmp = tmp->next)                    // Iterate through the high scores linked list
        {
            if (defaultHighScores > 0)                                          // If the default number of high scores counter is > 0
            {
            lockedPlayer = getLockedString(tmp->player);                        // Get the player name
                lockedScore = getLockedString(std::to_string(tmp->score));      // Get the player score
                writeScores << lockedPlayer << " " << lockedScore << std::endl; // Write the name and score to the file
                defaultHighScores--;                                            // Decrement the default number of high scores counter
            }
            else { break; }                                                     // After the default number of scores have been written
        }
}
    else { writeFileError(); }                                                  // If the file failed to open correctly, write an error
    return;                                                                     // Return from the function
}

// Prints appropriate error message
void HighScoresList::writeFileError()
{
	system("CLS");
	std::cout << "Error saving high score." << std::endl;
	for (int i = 3; i > 0; i--)
	{
		std::cout << "Closing in... " << i << std::endl;
		Sleep(sleepOneSecond);
	}
	exit(1);
}

// Prints the header text for the high score page
void HighScoresList::printHighScoreHeader(std::string startColor, std::string endColor)
{
    for (int i = 0; i < sizeof(highScoreHeader) / sizeof(std::string); i++)     // Loop trough the title image array
    {
        for (int j = 0; j < int(highScoreHeader[i].length()); j++)              // Loop through each character in the array line
        {
            std::cout << startColor << highScoreHeader[i][j] << endColor;       // Print the character at the row/column
		}
		std::cout << std::endl;
        Sleep(gamePrintDealy);                                                  // Pause the system
	}
	std::cout << std::endl;
	std::cout << std::endl;

    return;                                                                     // Return from the function
}

// Encryption/Decryption
std::string HighScoresList::getLockedString(std::string lockUnlock)
{
    char key[11] = { 'H', 'A', 'N', 'G', 'M', 'A', 'N', 'g', 'a', 'm', 'e' };   // Key for encryption/decryption
    std::string output = lockUnlock;                                            // Set output to the string to be encrypted/decrypted

    for (int i = 0; i < int(lockUnlock.size()); i++)                            // Iterate through the string
    {
        if (lockUnlock[i] == ' ') { output[i] = ' '; }                          // Carry the spaces over
        else                                                                    // Encrypt/decrypt all other characters
        {
            output[i] = lockUnlock[i] ^ key[i % (sizeof(key) / sizeof(char))];  // Use XOR for encryption/decryption
        }
    }
    return output;                                                              // Return the encrypted/decrypted string
}

// Generates additional high scores
void HighScoresList::populateHighScores(HighScoresList highScores, int scoresNeeded)
{
    std::cout << "Score error in High Scores file detected." << std::endl;
    std::cout << "Fixing high scores";
    for (int i = 0; i < scoresNeeded; i++)                                      // Generate the required amount of high scores
    {
        std::cout << ".";
        highScores.addNode("JJW", getRandomScore());                            // Generate a random score and add it to the high scores list
        Sleep(sleepOneSecond);
    }
    highScores.writeHighScores();                                               // Write the high scores to the 
    return;
}

// Generates a random score
int HighScoresList::getRandomScore()                                            // Generates a random number
{
    srand((unsigned int)time(0));                                               // Seed the random number generator with system time
    return (rand() % defaultScoreMax) + defaultScoreMin;                        // Generate random number between min and max scores
}

// Returns a list of scores retrieved from a file.
HighScoresList HighScoresList::getScores()
{
    HighScoresList highScores;                                                  // Initialize linked list for saving scores
    std::fstream readScores;                                                    // Create file stream for reading/writing
    readScores.open(highScoresFile);                                            // Open the file for reading
    
    if (readScores.peek() == EOF)                                               // If the file is empty
    {
    	highScores = highScores.generateNewHighScores(highScores);              // Populate it with default high scores
    }
    else if (readScores.is_open())                                              // File is not empty, start reading scores
    {
        std::string lockedPlayer = "";
        std::string lockedScore = "";
        std::string player = "";
        std::string stringScore = "";
        int scoresNeeded = 0;
        
        while (defaultHighScores > 0)                                           // Read/generate 10 high scores
        {
            if (std::getline(readScores, lockedPlayer, ' '))                    // If a name is successfully read
	        {
                if (std::getline(readScores, lockedScore))                      // If a score is successfully read
                {
                    player = highScores.getLockedString(lockedPlayer);          // Decrypt the player
                    stringScore = highScores.getLockedString(lockedScore);      // Decrypt the score		
                    if (player.length() == 3 && stringScore != "")              // Validate the player and score
                    {
                        highScores.addNode(player, std::stoi(stringScore));     // Add score to the list
                    }
                    else { scoresNeeded++; }                                    // Player or score data was invalid, needs replaced
                }
                else { scoresNeeded++; }                                        // Score was not read successfully
            }
            else { scoresNeeded++; }                                            // Player was not read successfully
            defaultHighScores--;                                                // Decrement high score count tracker
        }
        
        if (scoresNeeded > 0)                                                   // If 10 scores were not successfully read
        {
            highScores.populateHighScores(highScores, scoresNeeded);            // Generate the additional scores needed
        }
    }
    readScores.close();                                                         // Close the buffer
    return highScores;                                                          // Return the high scores
}

// Populates default high scores if file is empty
HighScoresList HighScoresList::generateNewHighScores(HighScoresList highScores)
{
	for (int i = 0; i < defaultHighScores; i++)
	{
		highScores.addNode("JJW", defaultScoreMax);
		defaultScoreMax -= defaultScoreDecrement;
	}
	highScores.writeHighScores();

	return highScores;
}