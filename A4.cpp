#include <iostream>
using namespace std;

int main() {
    int data[7], hamming[11];
    int p1, p2, p4;

    cout << "Enter 7-bit data:\n";
    for (int i = 0; i < 7; i++)
        cin >> data[i];

    // Place data bits (skip parity positions 1,2,4)
    hamming[2] = data[0];
    hamming[4] = data[1];
    hamming[5] = data[2];
    hamming[6] = data[3];
    hamming[8] = data[4];
    hamming[9] = data[5];
    hamming[10] = data[6];

    // Calculate parity bits (even parity)
    p1 = hamming[2] ^ hamming[4] ^ hamming[6] ^ hamming[8] ^ hamming[10];
    p2 = hamming[2] ^ hamming[5] ^ hamming[6] ^ hamming[9] ^ hamming[10];
    p4 = hamming[4] ^ hamming[5] ^ hamming[6];

    hamming[1] = p1;
    hamming[3] = p2;
    hamming[7] = p4;

    cout << "\nHamming Code:\n";
    for (int i = 1; i <= 10; i++)
        cout << hamming[i] << " ";

    // Introduce error
    cout << "\n\nEnter position to introduce error (1-10): ";
    int errorPos;
    cin >> errorPos;
    hamming[errorPos] ^= 1;

    // Error detection
    int c1, c2, c4;
    c1 = hamming[1] ^ hamming[2] ^ hamming[4] ^ hamming[6] ^ hamming[8] ^ hamming[10];
    c2 = hamming[3] ^ hamming[2] ^ hamming[5] ^ hamming[6] ^ hamming[9] ^ hamming[10];
    c4 = hamming[7] ^ hamming[4] ^ hamming[5] ^ hamming[6];

    int errorPosition = c4 * 4 + c2 * 2 + c1;

    if (errorPosition == 0) {
        cout << "\nNo error detected.";
    } else {
        cout << "\nError detected at position: " << errorPosition;
        hamming[errorPosition] ^= 1;
        cout << "\nCorrected Hamming Code:\n";
        for (int i = 1; i <= 10; i++)
            cout << hamming[i] << " ";
    }

    return 0;
}