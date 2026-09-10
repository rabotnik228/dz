#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
//Дз к пятому уроку. Игра на угадывание чисел. Автор: Семченков Дмитрий 212 группа
int main() {
    // Инициализация генератора случайных чисел
    std::srand(std::time(nullptr));

    // Загаданное число от 0 до 99
    const int secret = std::rand() % 100;

    // Ввод имени игрока
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    int guess = 0; //предположение пользователя
    int attempts = 0; //число попыток для угадывания

    // Цикл угадывания
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;
        if (guess < secret) {
            std::cout << "guess is less than secret\n";
        } else if (guess > secret) {
            std::cout << "guess is greater than secret\n";
        } else {
            std::cout << "you win!\n";
            break;
        }
    }

    // Вывод результата
    std::cout << "Congratulations! " << name << " guessed " << secret << " in " << attempts << " attempts\n";

    // Запись в файл таблицы рекордов
    std::ofstream out("records.txt", std::ios::app);
    out << name << " - " << attempts << " attempts\n";
    out.close();

    // Вывод всей таблицы рекордов
    std::cout << "\nRecords:\n";
    std::ifstream in("records.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << '\n';
    }
    in.close();
    return 0;
}
