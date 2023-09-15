#include <iostream>
#include <stdexcept>
#include "gtest/gtest.h"

class Chandrayaan3 {
public:
    Chandrayaan3(int x, int y, int z, char direction);

    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();

    int getX() const;
    int getY() const;
    int getZ() const;
    char getDirection() const;

private:
    int x_;
    int y_;
    int z_;
    char direction_;
};

Chandrayaan3::Chandrayaan3(int x, int y, int z, char direction)
    : x_(x), y_(y), z_(z), direction_(direction) {}

void Chandrayaan3::moveForward() {
    if (direction_ == 'N') {
        y_++;
    } else if (direction_ == 'S') {
        y_--;
    } else if (direction_ == 'E') {
        x_++;
    } else if (direction_ == 'W') {
        x_--;
    } else if (direction_ == 'U') {
        z_++;
    } else if (direction_ == 'D') {
        z_--;
    }
}

void Chandrayaan3::moveBackward() {
    // Implement backward movement logic here
    // This will be the opposite of forward movement
    if (direction_ == 'N') {
        y_--;
    } else if (direction_ == 'S') {
        y_++;
    } else if (direction_ == 'E') {
        x_--;
    } else if (direction_ == 'W') {
        x_++;
    } else if (direction_ == 'U') {
        z_--;
    } else if (direction_ == 'D') {
        z_++;
    }
}

void Chandrayaan3::turnLeft() {
    // Implement left turn logic here
    if (direction_ == 'N') {
        direction_ = 'W';
    } else if (direction_ == 'S') {
        direction_ = 'E';
    } else if (direction_ == 'E') {
        direction_ = 'N';
    } else if (direction_ == 'W') {
        direction_ = 'S';
    }
}

void Chandrayaan3::turnRight() {
    // Implement right turn logic here
    // This will be the opposite of left turn
    if (direction_ == 'N') {
        direction_ = 'E';
    } else if (direction_ == 'S') {
        direction_ = 'W';
    } else if (direction_ == 'E') {
        direction_ = 'S';
    } else if (direction_ == 'W') {
        direction_ = 'N';
    }
}

void Chandrayaan3::turnUp() {
    // Implement upward turn logic here
    if (direction_ == 'N' || direction_ == 'S' || direction_ == 'E' || direction_ == 'W') {
        direction_ = 'U';
    }
}

void Chandrayaan3::turnDown() {
    // Implement downward turn logic here
    // This will be the opposite of upward turn
    if (direction_ == 'N' || direction_ == 'S' || direction_ == 'E' || direction_ == 'W') {
        direction_ = 'D';
    }
}

int Chandrayaan3::getX() const {
    return x_;
}

int Chandrayaan3::getY() const {
    return y_;
}

int Chandrayaan3::getZ() const {
    return z_;
}

char Chandrayaan3::getDirection() const {
    return direction_;
}

TEST(Chandrayaan3Test, CommandSequence) {
    Chandrayaan3 chandrayaan(0, 0, 0, 'N');
    
    // Execute the command sequence
    chandrayaan.moveForward(); // "f"
    EXPECT_EQ(chandrayaan.getX(), 0);
    EXPECT_EQ(chandrayaan.getY(), 1);
    EXPECT_EQ(chandrayaan.getZ(), 0);
    EXPECT_EQ(chandrayaan.getDirection(), 'N');
    
    chandrayaan.turnRight(); // "r"
    EXPECT_EQ(chandrayaan.getX(), 0);
    EXPECT_EQ(chandrayaan.getY(), 1);
    EXPECT_EQ(chandrayaan.getZ(), 0);
    EXPECT_EQ(chandrayaan.getDirection(), 'E');
    
    chandrayaan.turnUp(); // "u"
    EXPECT_EQ(chandrayaan.getX(), 0);
    EXPECT_EQ(chandrayaan.getY(), 1);
    EXPECT_EQ(chandrayaan.getZ(), 0);
    EXPECT_EQ(chandrayaan.getDirection(), 'U');
    
    chandrayaan.moveBackward(); // "b"
    EXPECT_EQ(chandrayaan.getX(), 0);
    EXPECT_EQ(chandrayaan.getY(), 1);
    EXPECT_EQ(chandrayaan.getZ(), -1);
    EXPECT_EQ(chandrayaan.getDirection(), 'U');
    
    chandrayaan.turnLeft(); // "l"
    EXPECT_EQ(chandrayaan.getX(), 0);
    EXPECT_EQ(chandrayaan.getY(), 1);
    EXPECT_EQ(chandrayaan.getZ(), -1);
    EXPECT_EQ(chandrayaan.getDirection(), 'N');
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
