// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function declarations
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b, bool& error);
int calculateModulus(int a, int b, bool& error);
double power(double base, double exp);

// Menu display
void showMenu() {
    cout << "=================================" << endl;
    cout << "        SIMPLE CALCULATOR        " << endl;
    cout << "=================================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

// 1. Addition
double add(double a, double b) {
    return a + b;
}

// 2. Subtraction
double subtract(double a, double b) {
    return a - b;
}

// 3. Multiplication
double multiply(double a, double b) {
    return a * b;
}

// 4. Division with zero check
double divide(double a, double b, bool& error) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        error = true;
        return 0.0;
    }
    error = false;
    return a / b;
}

// 5. Modulus with zero check
int calculateModulus(int a, int b, bool& error) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
        error = true;
        return 0;
    }
    error = false;
    return a % b;
}

// 6. Exponentiation using pow() from <cmath>
double power(double base, double exp) {
    return pow(base, exp);
}

int main() {
    int choice = 0;

    while (choice != 7) {
        showMenu();
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please select a valid option (1-7)." << endl << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice! Please select a valid option (1-7)." << endl << endl;
            continue;
        }

        // Handle operations
        if (choice == 5) { // Modulus requires integer inputs
            int num1, num2;
            cout << "Enter first number: ";
            while (!(cin >> num1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid integer. Enter first number: ";
            }

            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid integer. Enter second number: ";
            }

            bool error = false;
            int result = calculateModulus(num1, num2, error);
            if (!error) {
                cout << "Result: " << num1 << " % " << num2 << " = " << result << endl;
            }
        } else { // Standard arithmetic / float operations
            double num1, num2;
            cout << "Enter first number: ";
            while (!(cin >> num1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number. Enter first number: ";
            }

            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number. Enter second number: ";
            }

            bool error = false;
            double result = 0.0;

            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case 2:
                    result = subtract(num1, num2);
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case 3:
                    result = multiply(num1, num2);
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case 4:
                    result = divide(num1, num2, error);
                    if (!error) {
                        cout << fixed << setprecision(2);
                        cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                    }
                    break;
                case 6:
                    result = power(num1, num2);
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
                    break;
            }
        }

        cout << endl;
    }

    return 0;
}