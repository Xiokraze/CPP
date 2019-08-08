#include "pch.h"
#include "IsoGrame.h"

Isogram IsoGrame;                               // Initialize game class

int main()                                      // Primary game function
{
    IsoGrame.printMainMenu();                   // Print the main menu
    do                                          // Keep playing while the player wants to play
    {
        system("CLS");                          // Clear the screen
        IsoGrame.reset();                       // Reset the game
        IsoGrame.playGame();                    // Run the game
    } while (IsoGrame.playAgain() == true);     // Check if player wants to play again

    return 0;                                   // Exit with status code 0
}
