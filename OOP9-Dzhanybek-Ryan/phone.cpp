#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "phone.h"

using namespace std;
// phone.h impl
std::vector<Phone> readFile(const std::string& filename) {
    ifstream fin(filename);
    vector<Phone> phones;
    if (fin.is_open()) {
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
        int pos = 0;
        char comma;
        while (fin >> x >> comma >> y >> comma >> z >> comma >> pos) {
            phones.push_back(Phone(x, y, z, pos));
        }
        fin.close();
    }
    return phones;
}

std::vector<Phone> getTestingData(std::vector<Phone>& phones) {
    vector<Phone> testingData = readFile("testingData.txt");
    for (Phone test : testingData) {
        phones.push_back(test);
    }
    return phones;
}

std::vector<Phone> readUnknownFile(const std::string& filename) {
    ifstream fin(filename);
    vector<Phone> phones;
    if (fin.is_open()) {
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
        char comma;
        while (fin >> x >> comma >> y >> comma >> z) {
            phones.push_back(Phone(x, y, z, FaceUp));
        }
        fin.close();
    }
    return phones;
}

void writeResult(const std::string& filename, const Phone& userphone) {
    string pos;
    switch (userphone.getPosition()) {
    case 1:
        pos = "FaceUp";
        break;
    case 2:
        pos = "FaceDown";
        break;
    case 3:
        pos = "Portrait";
        break;
    case 4:
        pos = "PortraitUDown";
        break;
    case 5:
        pos = "LandscapeLeft";
        break;
    case 6:
        pos = "LandscapeRight";
        break;
    default:
        pos = "FaceUp";
        break;
    }
    std::ofstream results(filename, std::ios::app);
    if (results.is_open()) {
        results << userphone.getX() << ','
            << userphone.getY() << ','
            << userphone.getZ() << ','
            << userphone.getPositionInt() <<',' 
            <<pos <<'\n';
        results.close();
    }
}

void getOrientation(const std::vector<Phone>& phones, double x, double y, double z) {
    vector<double> distances;
    for (const Phone& phone : phones) {
        double dx = phone.getX() - x;
        double dy = phone.getY() - y;
        double dz = phone.getZ() - z;
        double distance = sqrt(dx * dx + dy * dy + dz * dz);
        distances.push_back(distance);
    }

    double minDistance = distances[0];
    size_t minIndex = 0;

    for (size_t i = 1; i < distances.size(); i++) {
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
    }
    switch (phones[minIndex].getPosition()) {
    case 1:
        cout << "FaceUp";
        break;
    case 2:
        cout << "FaceDown";
        break;
    case 3:
        cout << "Portrait";
        break;
    case 4:
        cout << "PortraitUDown";
        break;
    case 5:
        cout << "LandscapeLeft";
        break;
    case 6:
        cout << "LandscapeRight";
        break;
    default:
        cout << "FaceUp";
        break;
    }
}

std::vector<Phone> getUnknownData(std::vector<Phone>& phones, const std::string& filename) {
    vector<Phone> unknownData = readUnknownFile(filename);
    for (Phone& unknownPhone : unknownData) {
        vector<double> distances;
        for (const Phone& phone : phones) {
            double dx = phone.getX() - unknownPhone.getX();
            double dy = phone.getY() - unknownPhone.getY();
            double dz = phone.getZ() - unknownPhone.getZ();
            double distance = sqrt(dx * dx + dy * dy + dz * dz);
            distances.push_back(distance);
        }

        double minDistance = distances[0];
        size_t minIndex = 0;

        for (size_t i = 1; i < distances.size(); i++) {
            if (distances[i] < minDistance) {
                minDistance = distances[i];
                minIndex = i;
            }
        }
        unknownPhone.setPosition(phones[minIndex].getPosition());
        writeResult("result.txt", unknownPhone);
    }
    return unknownData;
}

Phone::Phone() : x(0), y(0), z(0), position(FaceUp) {}

Phone::Phone(double initX, double initY, double initZ, int initPosition)
    : x(initX), y(initY), z(initZ) {
    switch (initPosition) {
    case 1:
        position = FaceUp;
        break;
    case 2:
        position = FaceDown;
        break;
    case 3:
        position = Portrait;
        break;
    case 4:
        position = PortraitUDown;
        break;
    case 5:
        position = LandscapeLeft;
        break;
    case 6:
        position = LandscapeRight;
        break;
    default:
        position = FaceUp;
        break;
    }
}

Phone::Phone(double initX, double initY, double initZ, POSITION initPosition)
    : x(initX), y(initY), z(initZ), position(initPosition) {}

double Phone::getX() const { return x; }

double Phone::getY() const { return y; }

double Phone::getZ() const { return z; }

void Phone::setX(double newX) { x = newX; }

void Phone::setY(double newY) { y = newY; }

void Phone::setZ(double newZ) { z = newZ; }

void Phone::setPosition(POSITION newPosition) { position = newPosition; }

POSITION Phone::getPosition() const { return position; }

int Phone::getPositionInt() const {
    switch (position) {
    case FaceUp:
        return 1;
    case FaceDown:
        return 2;
    case Portrait:
        return 3;
    case PortraitUDown:
        return 4;
    case LandscapeLeft:
        return 5;
    case LandscapeRight:
        return 6;
    default:
        return 1;
    }
}
