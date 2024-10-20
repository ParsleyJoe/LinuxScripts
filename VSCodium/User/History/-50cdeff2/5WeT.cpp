#include <iostream>
#include <string>
#include <array>
#include <random>

class Game
{

private:
    int attempts = 5;
    std::array<std::string, 10> wordArray = {"snow", "cheek", "energy", "execute", "number", "pig", "whip", "snatch", "turkey", "mayor"};
    std::string word;
    bool isGameActive;

public:
    void welcome()
    {
        std::cout << "Welcome to Console Hangman\n";
        std::cout << "Time to guess a word\n";
        std::cout << "You have " << attempts << " attempts\n";
    }
    Game()
    {
        guessWord();
        isGameActive = true;
    }
    void guessWord()
    {
        std::random_device rd{};
        std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
        std::mt19937 mt{ss};
        std::uniform_int_distribution die10{1, 10};

        word = wordArray[die10(mt)];
    }
    void printDashes(std::vector<char> &guessArr)
    {
        if (guessArr.empty())
        {
            for (int i = 0; i < word.length(); i++)
            {
                std::cout << "_";
            }
        }
        else
        {
            for (int i = 0; i < word.length(); i++)
            {
                for (int j = 0; j < word.length(); j++)
                {
                    if (guessArr[i] == word[j])
                    {
                        std::cout << guessArr[i];
                    }
                }
                std::cout << "_";
            }
        }
    }
    void Play()
    {
        char guess{};
        std::vector<char> guessArr;
        std::cout << word;
        while (attempts > 0)
        {
            printDashes(guessArr);
            std::cout << "Guess a letter: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> guess;

            if (word.find(guess) != word.npos)
            {
                guessArr.push_back(guess);
            }
            else
            {
                attempts--;
                std::cout << "Wrong guess, now you have " << attempts << " attempts\n";
            }
        }
    }
};

int main()
{
    Game game;
    // Select a word from array

    // Welcome and shit
    game.welcome();

    // Start the guessing game
    game.Play();

    return 0;
}
