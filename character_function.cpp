// Mary Brown
// CIS1202
// 01/08/2025

#include <iostream>
#include <stdexcept>
using namespace std;

// Exception: invalid input character
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character: must be a letter.";
    }
};

// Exception: result character is outside valid range
class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Resulting character is out of range.";
    }
};

// Function that offsets a character with range validation
char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }

    char result = start + offset;

    // Check case range consistency
    if (islower(start) && !islower(result)) {
        throw invalidRangeException();
    }
    if (isupper(start) && !isupper(result)) {
        throw invalidRangeException();
    }

    return result;
}

int main() {
    char inputChar;
    int offset;

    cout << "Enter a single letter (A-Z or a-z): ";
    cin >> inputChar;

    cout << "Enter an offset value (positive or negative integer): ";
    cin >> offset;

    try {
        char result = character(inputChar, offset);
        cout << "Resulting character: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
