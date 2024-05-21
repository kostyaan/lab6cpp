#include <iostream>
#include "rhombus.h"

int main() {
    int x, y;
    double side;

    // Введення початкових параметрів ромба
    std::cout << "Enter the initial x coordinate: ";
    std::cin >> x;
    std::cout << "Enter the initial y coordinate: ";
    std::cin >> y;
    std::cout << "Enter the initial side length: ";
    std::cin >> side;

    Rhombus r(x, y, side);

    int choice;
    do {
        std::cout << "1. Move\n2. Resize\n3. Draw\n4. Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int dx, dy;
            std::cout << "Enter movement in x and y directions: ";
            std::cin >> dx >> dy;
            r.move(dx, dy);
            break;
        }
        case 2: {
            double new_side;
            std::cout << "Enter new side length: ";
            std::cin >> new_side;
            r.setSide(new_side);
            break;
        }
        case 3: {
            std::cout << "Drawing the rhombus..." << std::endl;
            r.draw();
            break;
        }
        case 4:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 4);

    return 0;
}
