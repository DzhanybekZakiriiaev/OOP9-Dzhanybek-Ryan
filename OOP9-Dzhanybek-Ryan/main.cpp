#include <iostream>
#include <vector>
#include "phone.h"

using namespace std;
// main file 
int main() {
    int choice;
    vector<Phone> phones = readFile("trainingData.txt");
    phones = getTestingData(phones);
    cout << "1 - NN Classifier" << endl;
    cout << "2 - Another Classifier" << endl;
    cout << "3 - KNN Classifier" << endl;
    cout << "4 - Enter filename" << endl;
    cout << "Please choose between our classifiers: ";
    cin >> choice;
    string filename;
    vector<Phone> results;
    switch (choice) {
    case 1: {
        double x, y, z;
        cout << "You selected NN Classifier." << endl;
        cout << "Please enter 3 coordinates: ";
        cin >> x >> y >> z;
        getOrientation(phones, x, y, z);
        break;
    }
    case 2:
        cout << "You selected Another Classifier." << endl;
        cout << "It is not done yet." << endl;
        break;
    case 3:
        cout << "You selected KNN Classifier." << endl;
        cout << "It is not done yet." << endl;
        break;
    case 4:
        cout << "Please enter a filename: ";
        cin >> filename;
        results = getUnknownData(phones, filename);
        cout << "result.txt";
        break;
    default:
        cout << "Invalid choice. Please select a valid option." << endl;
        break;
    }

    return 0;
}
