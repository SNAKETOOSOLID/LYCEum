#include <iostream>
#include <cstdlib>
#include <ctime>

int findGCD(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

void welcome() {
    std::cout << "Добро пожаловать в игру!" << std::endl;
    std::cout << "Назовите своё имя: ";
}

int main() {
    srand(time(0));
    welcome();
    
    std::string name;
    std::cin >> name;
    std::cout << "Здравствуйте, " << name << "!" << std::endl;
    std::cout << "Найдите НОК." << std::endl;

    int score = 0;
    for (int i = 0; i < 3; i++) {
        int num1 = rand() % 21;
        int num2 = rand() % 21;
        int num3 = rand() % 21;

        std::cout << "Вопрос: " << num1 << " " << num2 << " " << num3 << std::endl;
        
        int userAnswer;
        std::cout << "Ваш ответ: ";
        std::cin >> userAnswer;

        int correctAnswer = findLCM(findLCM(num1, num2), num3);

        if (userAnswer == correctAnswer) {
            std::cout << "Правильно, молодец!" << std::endl;
            score++;
        } else {
            std::cout << "'" << userAnswer << "' это неправильный ответ ;(. Правильным ответом было '" << correctAnswer << "'." << std::endl;
            std::cout << "Попробуйте заново, " << name << "!" << std::endl;
            break;
        }
    }

    if (score == 3) {
        std::cout << "Мои поздравления, " << name << "!" << std::endl;
    } else {
        std::cout << "Вы проиграли, " << name << "! Попробуйте заново." << std::endl;
    }

    return 0;
}
