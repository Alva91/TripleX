#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) 
{
    // Print welcome messages to the terminal
    std::cout << "The door to the catacombs level " << Difficulty;
    std::cout << " entrance stands in front of you.\nYou see a control panel where you can enter a code.\nThe control panel lights up...\n";
}

bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code.\n";
    std::cout << "+ The sum of the digits is " << CodeSum << std::endl;
    std::cout << "+ The product of the digits is " << CodeProduct << std::endl << std::endl;

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessProduct = GuessA * GuessB * GuessC;
    int GuessSum = GuessA + GuessB + GuessC;

    if (GuessProduct == CodeProduct && GuessSum == CodeSum) // Correct sequence
    {
        std::cout << "The door begins to rumble and move.\n";
        return true;
    }
    else // Incorrect sequence
    {
        std::cout << "The door remains static.\n";
        return false;
    }
}

int main()  
{
    srand (time(NULL)); // seeding random value

    const int MaxLevel = 5;

    int LevelDifficulty = 1;

    // ASCII door
    std::cout << "      _________\n    _|         |_\n  _|             |_\n_|                 |_\n|     WELCOME TO    |\n|        THE        |\n|     CATACOMBS     |\n|                   |\n|                   |\n|                   |\n|                   |\n|-------------------|\n\n";

    // Playing the game
    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "You have fully explored the catacombs!";

    return 0;
}




