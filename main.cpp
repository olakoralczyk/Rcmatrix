#include <iostream>
#include "Rcmatrix.h"

using namespace std;

int main() {
    try {
        Rcmatrix C1("mat4.txt");
        Rcmatrix C2("mat4.txt");
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
        Rcmatrix C1("mat4.txt");
        Rcmatrix C2("mat4.txt");
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
        Rcmatrix C1("mat4.txt");
        Rcmatrix C2("mat4.txt");
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
        Rcmatrix C1("mat.txt");
        Rcmatrix C2("mat3.txt");
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