#include <iostream>
#include <string>
using namespace std;

// --- GLOBAL STORAGE ---
string titles[50] = {"The Hobbit", "1984", "fire and blood"};
string authors[50] = {"Tolkien", "Orwell", "George Martin"};
float prices[50] = {2000, 1500, 3000};
int stock[50] = {10, 5, 8};
string history[100];

int bookCount = 3;    
int historyCount = 0; 

// --- ADMIN MENU FUNCTION ---
// We move this ABOVE main so main can see it.
void adminMenu() {
    int choice = 0;
    while (choice != 10) {
        cout << "\n--- ADMIN PANEL ---\n";
        cout << "1. Add Book (Create)\n";
        cout << "2. View All Books (Read)\n";
        cout << "3. Update Price (Update)\n";
        cout << "4. Delete Book (Delete)\n";
        cout << "5. Sort by Price\n";
        cout << "6. Sort by Name\n";
        cout << "7. Search Book\n";
        cout << "8. Inventory Value\n";
        cout << "9. View History\n";
        cout << "10. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore(); // This clears the "Enter" key from the buffer
            cout << "Enter Title: ";
            getline(cin, titles[bookCount]); // Allows spaces in names
            cout << "Enter Author: ";
            getline(cin, authors[bookCount]);
            cout << "Enter Price: ";
            cin >> prices[bookCount];
            cout << "Enter Stock: ";
            cin >> stock[bookCount];
            
            bookCount++; 
            cout << "Book Added Successfully!\n";
        }
        else if (choice == 2) {
            cout << "\n--- CURRENT INVENTORY ---\n";
            for (int i = 0; i < bookCount; i++) {
                // We use i + 1 just for display so it doesn't show "Book 0"
                cout << i + 1 << ". " << titles[i] << " by " << authors[i] << " | Price: " << prices[i] << " | Stock: " << stock[i] << endl;
            }
        }
        else if (choice == 3) {
            int index;
            cout << "Enter the Book Number to update (1 to " << bookCount << "): ";
            cin >> index;
            index--; // Convert user's "1" to array's "0"

            if (index >= 0 && index < bookCount) {
                cout << "Updating: " << titles[index] << endl;
                cout << "Enter New Price: ";
                cin >> prices[index];
                cout << "Price Updated!\n";
            } else {
                cout << "Invalid Book Number!\n";
            }
        }
        else if (choice == 4) {
            int index;
            cout << "Enter the Book Number to delete: ";
            cin >> index;
            index--; 

            if (index >= 0 && index < bookCount) {
                // LOGIC: Shift everything to the left to fill the hole
                for (int i = index; i < bookCount - 1; i++) {
                    titles[i] = titles[i + 1];
                    authors[i] = authors[i + 1];
                    prices[i] = prices[i + 1];
                    stock[i] = stock[i + 1];
                }
                bookCount--; // Shrink the size of our active list
                cout << "Book Deleted successfully!\n";
            } else {
                cout << "Invalid Book Number!\n";
            }
        }
    }
}

    void customerMenu() {
    int choice = 0;
    while (choice != 10) {
        cout << "\n--- CUSTOMER PORTAL ---\n";
        cout << "1. View Catalog\n";
        cout << "2. Search for a Book\n";
        cout << "3. Buy a Book (Checkout)\n";
        cout << "4. View My Purchase History\n";
        cout << "10. Logout\n"; // i am typing opt 10 here instead of 5 to keep the key for exit same
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // Re-use your View logic
            for (int i = 0; i < bookCount; i++) {
                cout << i + 1 << ". " << titles[i] << " - $" << prices[i] << endl;
            }
        }
        else if (choice == 3) {
            int buyIndex;
            cout << "Enter Book Number to Buy: ";
            cin >> buyIndex;
            buyIndex--;

            if (buyIndex >= 0 && buyIndex < bookCount) {
                // Record to History
                string entry = "Purchased: " + titles[buyIndex];
                history[historyCount] = entry;
                historyCount++;
                cout << "Thank you for buying " << titles[buyIndex] << "!\n";
            }
        }
        else if (choice == 4) {
            cout << "\n--- YOUR HISTORY ---\n";
            for (int i = 0; i < historyCount; i++) {
                cout << history[i] << endl;
            }
        }
    }
}

// --- MAIN PROGRAM ---
int main() {
    int userType = 0;

    while (userType != 3) {
        cout << "\n=== BOOKSTORE MANAGEMENT SYSTEM ===\n";
        cout << "1. Admin Login\n";
        cout << "2. Customer Login\n";
        cout << "3. Exit\n";
        cout << "Choose User Type: ";
        cin >> userType;

        if (userType == 1) {
            adminMenu(); 
        } 
        else if (userType == 2) {
            customerMenu();
        }
    }

    cout << "Exiting... Goodbye";
    return 0;
}
