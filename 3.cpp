#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "2.h"

int generateProgression(std::vector<int>& progression) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(2, 5);

    int length = distribution(gen) * 2 + 1;
    int start = distribution(gen);
    int ratio = distribution(gen);

    for (int i = 0; i < length; ++i) {
        progression.push_back(start * pow(ratio, i));
    }

    return length;
}

void playGame() {
    std::string name;
    welcome();
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    std::vector<int> progression;
    int length = generateProgression(progression);
    int hiddenIndex = std::rand() % length;
    int hiddenNumber = progression[hiddenIndex];
    progression[hiddenIndex] = -1; // Hide the number with '-1'

    for (int i = 0; i < length; ++i) {
        if (progression[i] == -1) {
            std::cout << ".. ";
        } else {
            std::cout << progression[i] << " ";
        }
    }
    std::cout << std::endl;

    int userAnswer;
    std::cout << "Your answer: ";
    std::cin >> userAnswer;

    if (userAnswer == hiddenNumber) {
        std::cout << "Correct!" << std::endl;
        congratulations(name);
    } else {
        incorrectAnswer(name, hiddenNumber);
        tryAgain(name);
    }
}

int main() {
    playGame();
    return 0;
}
