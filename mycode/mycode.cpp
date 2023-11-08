#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// Define a custom exception for invalid input parameters
class InvalidInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid input parameters";
    }
};

// Function to validate input parameters
bool checkValidParams(double n, double x) {
    return n > 4;
}

// Function to check if input values are valid (i.e., not characters or invalid doubles)
bool checkValidInput(double n, double x) {
    return !std::cin.fail() && std::cin.eof();
}

// Function to calculate the function value
double function(double n, double x) {
    if (!checkValidParams(n, x)) {
        throw InvalidInputException();
    }

    if (x <= 0) {
        double y = 1;
        for (int i = 1; i <= n; i++) {
            y *= (1.0 / x) - (1.0 / i);
        }
        return y;
    }
    else if (x > 0) {
        double sum = 0;
        double y = 0;
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                if ((x - i + x * j) == 0) {
                    continue;
                }
                else {
                    sum += 1.0 / (x - i + x * j);
                }
            }
            y += sum;
        }
        return y;
    }
}

void calculateAndPrintResults(double n, double x_min, double x_max, double step) {
    // Open the output file
    ofstream outputFile("results.txt");

    if (n > 4 && x_min < x_max && step > 0) {
        for (double x = x_min; x <= x_max; x += step) {
            double y = function(n, x);
            cout << "x = " << x << "\t y = " << y << endl;

            // Write results to the file
            outputFile << "x = " << x << "\t y = " << y << endl;
        }
        outputFile.close();
    }
    else {
        throw InvalidInputException();
    }
}

int main() {
    double x_max, n, x_min, step;

    try {
        // Read input parameters
        cout << "Enter x_min: ";
        cin >> x_min;
        cout << "Enter x_max: ";
        cin >> x_max;
        cout << "Enter step: ";
        cin >> step;
        cout << "Enter n: ";
        cin >> n;

        if (!checkValidInput(n, x_min)) {
            throw InvalidInputException();
        }

        calculateAndPrintResults(n, x_min, x_max, step);

        cout << "Results have been saved to 'results.txt'" << endl;
    }
    catch (const InvalidInputException& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}