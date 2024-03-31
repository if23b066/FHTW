#include <iostream>

struct point {
    int x;
    int y;
    int z;
};

int main() {
    point p1;

    std::cin >> p1.x;
    std::cin >> p1.y;
    std::cin >> p1.z;

    std::cout << "x: " << p1.x << " | " << "y: " << p1.y << " | " << "z: " << p1.z << std::endl;

    return 0;
}
