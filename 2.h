#include <iostream>
#include <string>

void welcome() {
    std::cout << "Добро пожаловать в игру!" << std::endl;
    std::cout << "Назовите своё имя: ";
}


void congratulations(const std::string& name) {
    std::cout << "Мои поздравления, " << name << "!" << std::endl;
}


void tryAgain(const std::string& name) {
    std::cout << "Вы проиграли, " << name << "! Попробуйте заново." << std::endl;
}


void incorrectAnswer(const std::string& name, int correctAnswer) {
    std::cout << " это неправильный ответ ;(. Правильным ответом было '" << correctAnswer << "'." << std::endl;
    std::cout << "Попробуйте заново, " << name << "!" << std::endl;
}