#include <iostream>
#include <fstream>
#include "Rcmatrix.h"

using namespace std;

int main() {
    try {
        fstream input ("mat4.txt");
        Rcmatrix C1(2, 2);
        Rcmatrix C2(2, 2);
        input >> C1;
        input >> C2;
        cout << "---------" << endl;
        cout << C1;
        cout << "---------" << endl;
        cout << C2;
        cout << "---------" << endl;
        Rcmatrix C3 = C1 * C2;
        cout << C3;
        cout << "-------------------------------" << endl;
    }
    catch (exception& e) {
        cout << "-------------------------------" << endl;
        cout << e.what() << endl;
        cout << "-------------------------------" << endl;
    }
    try {
        fstream input ("mat4.txt");
        Rcmatrix C1(2, 3);
        Rcmatrix C2(2, 3);
        input >> C1;
        input >> C2;
        cout << "---------" << endl;
        cout << C1;
        cout << "---------" << endl;
        cout << C2;
        cout << "---------" << endl;
        Rcmatrix C3 = C1 + C2;
        cout << C3;
        cout << "-------------------------------" << endl;
    }
    catch (exception& e) {
        cout << "-------------------------------" << endl;
        cout << e.what() << endl;
        cout << "-------------------------------" << endl;
    }

    try {
        fstream input ("mat4.txt");
        Rcmatrix C1(2, 2);
        Rcmatrix C2(2, 2);
        input >> C1;
        input >> C2;
        cout << "---------" << endl;
        cout << C1;
        cout << "---------" << endl;
        cout << C2;
        cout << "---------" << endl;
        Rcmatrix C3 = C1 - C2;
        cout << C3;
        cout << "-------------------------------" << endl;
    }
    catch (exception& e) {
        cout << "-------------------------------" << endl;
        cout << e.what() << endl;
        cout << "-------------------------------" << endl;
    }

    try {
        fstream input ("mat4.txt");
        Rcmatrix C1(2, 1);
        Rcmatrix C2(3, 4);
        input >> C1;
        input >> C2;
        cout << "---------" << endl;
        cout << C1;
        cout << "---------" << endl;
        cout << C2;
        cout << "---------" << endl;
        Rcmatrix C3 = C1 - C2;
        cout << C3;
        cout << "-------------------------------" << endl;
    }
    catch (exception& e) {
        cout << "-------------------------------" << endl;
        cout << e.what() << endl;
        cout << "-------------------------------" << endl;
    }

    try {
        Rcmatrix C1(3, 2);
        Rcmatrix C2(2, 3);
        cin >> C1;
        cin >> C2;
        cout << "---------" << endl;
        cout << C1;
        cout << "---------" << endl;
        cout << C2;
        cout << "---------" << endl;
        Rcmatrix C3 = C1 * C2;
        cout << C3;
        cout << "-------------------------------" << endl;
    }
    catch (exception& e) {
        cout << "-------------------------------" << endl;
        cout << e.what() << endl;
        cout << "-------------------------------" << endl;
    }

    try {
        Rcmatrix C1(2, 2);
        Rcmatrix C2(2, 2);
        cin >> C1;
        cin >> C2;
        cout << "---------" << endl;
        cout << C1;
        cout << "---------" << endl;
        cout << C2;
        cout << "---------" << endl;
        Rcmatrix C3 = C1 - C2;
        cout << C3;
        cout << "-------------------------------" << endl;
    }
    catch (exception& e) {
        cout << "-------------------------------" << endl;
        cout << e.what() << endl;
        cout << "-------------------------------" << endl;
    }

    try {
        Rcmatrix C1(2, 2);
        Rcmatrix C2(2, 2);
        cin >> C1;
        cin >> C2;
        cout << "---------" << endl;
        cout << C1;
        cout << "---------" << endl;
        cout << C2;
        cout << "---------" << endl;
        Rcmatrix C3 = C1 + C2;
        cout << C3;
        cout << "-------------------------------" << endl;
    }
    catch (exception& e) {
        cout << "-------------------------------" << endl;
        cout << e.what() << endl;
        cout << "-------------------------------" << endl;
    }
}