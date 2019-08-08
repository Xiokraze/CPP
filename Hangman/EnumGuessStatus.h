#pragma once

// Enum class for handling guess validation statuses
enum class validGuess
{
	initialized,
	notALowercaseLetter,
	notLetter,
	noInput,
	moreThanOneLetter,
	duplicate,
	valid
};