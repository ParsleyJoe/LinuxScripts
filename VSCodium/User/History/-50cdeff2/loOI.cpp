#include <iostream>
#include <string>
#include <array>
#include <random>

int Play()
{
}

class Game
{

private:
    int attempts = 5;
    std::array<std::string, 10> wordArray = {"snow", "cheek", "energy", "execute", "number", "pig", "whip", "snatch", "turkey", "mayor"};

public:
    void welcome()
    {
        std::cout << "Welcome to Console Hangman\n";
        std::cout << "Time to guess a word\n";
        std::cout << "You have " << attempts << " attempts\n";
    }
    std::string guessWord()
    {
        std::random_device rd{};
        std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
        std::mt19937 mt{ss};
        std::uniform_int_distribution die10{1, 10};

        return wordArray[die10(mt)];
    }
};

int main()
{
    // Select a word from array
    std::string word(guessWord());

    // Welcome and shit
    welcome();

    // Start the guessing game

    return 0;
}