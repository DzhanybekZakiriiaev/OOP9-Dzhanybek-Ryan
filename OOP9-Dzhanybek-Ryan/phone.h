#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <fstream> 
#include <iostream> 
#include <sstream>
#include <vector>
// position enum
enum POSITION {
	FaceUp = 1,
	FaceDown = 2,
	Portrait = 3,
	PortraitUDown = 4,
	LandscapeLeft = 5,
	LandscapeRight = 6
};
// phone class
class Phone {
private:
	double x;
	double y;
	double z;
	enum POSITION position;
public:
    Phone(); // constructor
    Phone(double, double, double, POSITION); // parameterized constructor
    Phone(double, double, double, int); // parameterized constructor
    double getX() const; // getter X
    double getY() const; // getter Y
    double getZ() const; // getter Z
    void setX(double); // setter X
    void setY(double); // setter X
    void setZ(double); // setter X
    void setPosition(POSITION); // setter Position
    int getPositionInt() const; // setter Position value
    POSITION getPosition() const; // getter Position
};

std::vector<Phone> readFile(const std::string& filename); // read file
std::vector<Phone> readUnknownFile(const std::string& filename); // read file with uknown fields
void writeResult(const std::string& filename, const Phone& userphone); // write result
void getOrientation(const std::vector<Phone>& phones, double x, double y, double z); // get orientation
std::vector<Phone> getUnknownData(std::vector<Phone>& phones, const std::string& filename); // get uknown data
std::vector<Phone> getTestingData(std::vector<Phone>& phones); // get testing data
