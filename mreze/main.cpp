#include <iostream>

void runServer();
void runClient();

int main() {
    int choice;

    std::cout << "============================\n";
    std::cout << " Postanski sanducici sistem \n";
    std::cout << "============================\n";
    std::cout << "1 - Pokreni SERVER\n";
    std::cout << "2 - Pokreni KLIJENT\n";
    std::cout << "> ";

    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1)
        runServer();
    else if (choice == 2)
        runClient();
    else
        std::cout << "Pogresan izbor\n";

    return 0;
}
