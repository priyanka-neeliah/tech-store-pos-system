#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int main() {
    // Our tech products collection
    string products[] = {
        "Wireless Mouse",
        "Bluetooth Speaker",
        "USB Flash Drive",
        "Gaming Keyboard",
        "Noise-Cancelling Headphones",
        "Smartwatch",
        "External Hard Drive",
        "Portable Charger"
    };

    double prices[] = { 150.00, 250.00, 100.00, 500.00, 750.00, 1200.00, 1000.00, 300.00 };
    const int NUM_PRODUCTS = 8;
    const int MAX_ITEMS = 10;

    // Getting to know you
    string firstName, lastName;

    cout << "👋 Welcome to Tech Haven!" << endl;
    cout << "Let's get you set up for shopping..." << endl << endl;

    cout << "What's your first name? ";
    cin >> firstName;
    cout << "And your last name? ";
    cin >> lastName;

    cout << endl << "Nice to meet you, " << firstName << "! ";
    cout << "Here's what we have in store today:" << endl << endl;

    // Showing off our products
    cout << "🛍️  OUR PRODUCT CATALOGUE" << endl;
    cout << "─────────────────────────" << endl;
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        cout << "[" << i + 1 << "] " << left << setw(35) << products[i]
            << "R" << fixed << setprecision(2) << prices[i] << endl;
    }

    // Let's figure out how many items you want
    int numItems;
    cout << endl << "So " << firstName << ", how many different items would you like to get? ";
    cout << "(you can choose up to " << MAX_ITEMS << "): ";

    while (!(cin >> numItems) || numItems < 1 || numItems > MAX_ITEMS) {
        cout << "Hmm, that doesn't seem right. Please choose between 1 and " << MAX_ITEMS << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Great! Let me help you pick " << numItems;
    if (numItems == 1) {
        cout << " item." << endl;
    }
    else {
        cout << " items." << endl;
    }

    // Arrays to remember your choices
    int itemNumbers[MAX_ITEMS];
    int quantities[MAX_ITEMS];

    // Helping you choose each item
    for (int i = 0; i < numItems; i++) {
        int itemNumber, quantity;

        cout << endl << "--- Item #" << (i + 1) << " ---" << endl;

        // Which product caught your eye?
        cout << "Which product would you like? (enter 1-" << NUM_PRODUCTS << "): ";
        while (!(cin >> itemNumber) || itemNumber < 1 || itemNumber > NUM_PRODUCTS) {
            cout << "Oops! Please choose a number between 1 and " << NUM_PRODUCTS << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // How many would you like?
        cout << "How many " << products[itemNumber - 1] << "s would you like? ";
        while (!(cin >> quantity) || quantity < 1) {
            cout << "Let's try that again - please enter a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        itemNumbers[i] = itemNumber;
        quantities[i] = quantity;

        cout << "✓ Added " << quantity << " " << products[itemNumber - 1];
        if (quantity > 1) cout << "s";
        cout << " to your cart!" << endl;
    }

    // Let's total everything up
    double subtotal = 0.0;

    cout << endl << "📋 CALCULATING YOUR ORDER..." << endl;
    cout << "─────────────────────────" << endl;
    cout << "Order for: " << firstName << " " << lastName << endl << endl;

    cout << "Your items:" << endl;
    for (int i = 0; i < numItems; i++) {
        int itemIndex = itemNumbers[i] - 1;
        double itemTotal = prices[itemIndex] * quantities[i];
        subtotal += itemTotal;

        cout << "  • " << quantities[i] << " x " << left << setw(35) << products[itemIndex]
            << "R" << fixed << setprecision(2) << itemTotal << endl;
    }

    // Checking if you get a special discount!
    double discount = 0.0;
    string discountMessage = "";

    if (subtotal > 2000.00) {
        discount = subtotal * 0.15;
        discountMessage = "🎉 You qualified for our 15% discount!";
    }
    else {
        discountMessage = "💡 Spend over R2000 to get 15% off your next order!";
    }

    double finalTotal = subtotal - discount;

    // Showing you the final breakdown
    cout << endl << "💰 ORDER SUMMARY" << endl;
    cout << "─────────────────────────" << endl;
    cout << "Subtotal:       R" << setw(8) << fixed << setprecision(2) << subtotal << endl;

    if (discount > 0) {
        cout << "Discount:      -R" << setw(8) << discount << endl;
    }

    cout << "Total:           R" << setw(8) << finalTotal << endl;

    cout << endl << discountMessage << endl;

    // Friendly goodbye
    cout << endl << "✨ Thank you for shopping with us, " << firstName << "!" << endl;
    cout << "Your tech gear will be ready shortly. Have a great day! 🌟" << endl;

    return 0;
}