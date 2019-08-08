#include "pch.h"
#include "Hangman.h"

HangmanGame Hangman;                                    // Initialize the game class

int main()
{
    HighScoresList highScores;                          // Initialize highScores class
    highScores = highScores.getScores();                // Get the current high scores
    int totalScore = 0;                                 // Initialize game session score tracker
    bool newHighScore = false;                          // Inititlize high score flag

    Hangman.printMainMenu(highScores);                  // Print the main menu
    do                                                  // Keep playing while the player wants to
    {
        Hangman.reset();                                // Each play, reset the game
        Hangman.playGame();                             // Play the game
        Hangman.printGameSummary();                     // Each play, print the session summary
        totalScore += Hangman.getCurrentScore();        // Add the session score to the total score
        Hangman.getNewHighScoreStatus                   // Test if player has achieved a new high score
        (
            highScores.newHighScore(totalScore)
        );
        Hangman.printTotalScore(totalScore);            // Output the player's total score
    } while (Hangman.playAgain());                      // Ask if the player wants to play again

    if (highScores.newHighScore(totalScore))            // If the player achieved a new high score
    {
    std::string playerName = "";                        // Inititlize player name (initials) variable
        playerName = Hangman.getPlayerName();           // Get the player's initials
        highScores.addNode(playerName, totalScore);     // Add the score to the high scores list
    }

    highScores.display                                  // Print the high scores
    (
        Hangman.getStartColor(), 
        Hangman.getEndColor()
    );
    highScores.writeHighScores();                       // Save the high scores
    system("PAUSE");
    return 0;
}