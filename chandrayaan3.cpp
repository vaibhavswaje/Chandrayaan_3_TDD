#include <iostream>
#include <vector>

class Spacecraft {
private:
    int x, y, z;
    char direction;

public:
    Spacecraft(int x, int y, int z, char direction) : x(x), y(y), z(z), direction(direction) {}

    void move(char command) {
        switch (command) {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
            case 'u':
                turnUp();
                break;
            case 'd':
                turnDown();
                break;
        }
    }

    void moveForward() {
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'U':
                z++;
                break;
            case 'D':
                z--;
                break;
        }
    }

    void moveBackward() {
        switch (direction) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x--;
                break;
            case 'W':
                x++;
                break;
            case 'U':
                z--;
                break;
            case 'D':
                z++;
                break;
        }
    }

    void turnLeft() {
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
        }
    }

    void turnRight() {
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
        }
    }

    void turnUp() {
        switch (direction) {
            case 'N':
            case 'S':
            case 'E':
            case 'W':
                direction = 'U';
                break;
            case 'U':
                direction = 'D';
                break;
            case 'D':
                direction = 'N';
                break;
        }
    }

    void turnDown() {
        switch (direction) {
            case 'N':
            case 'S':
            case 'E':
            case 'W':
                direction = 'D';
                break;
            case 'U':
                direction = 'N';
                break;
            case 'D':
                direction = 'U';
                break;
        }
    }

    void printPosition() {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }

    void printDirection() {
        std::cout << direction << "\n";
    }
};

int main() {
    int startX = 0, startY = 0, startZ = 0;
    char startDirection = 'N';

    std::vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    Spacecraft spacecraft(startX, startY, startZ, startDirection);

    for (char command : commands) {
        spacecraft.move(command);
    }

    std::cout << "Final Position: ";
    spacecraft.printPosition();
    std::cout << "Final Direction: ";
    spacecraft.printDirection();
    return 0;
}
