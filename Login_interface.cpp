#include <iostream>
#include <string>
#include <map>

using namespace std;

// Structure to hold user information
struct User {
    string name;
    string phoneNumber;
    string email;
    string password;
};

// Map to store user information
map<string, User> users;

// Function to add a new user
void signUp() {
    string username;
    cout << "Enter a username: ";
    cin >> username;

    if (users.find(username)!= users.end()) {
        cout << "Username already exists." << endl;
        return;
    }

    User newUser;
    cout << "Enter name: ";
    cin.ignore(); // To ignore the newline character from the previous input
    getline(cin, newUser.name);
    cout << "Enter phone number: ";
    getline(cin, newUser.phoneNumber);
    cout << "Enter email: ";
    getline(cin, newUser.email);
    cout << "Enter password: ";
    getline(cin, newUser.password);

    users[username] = newUser;
    cout << "User registered successfully." << endl;
}

// Function to check user credentials
bool login(string username, string password) {
    if (users.find(username) == users.end()) {
        cout << "Invalid username or password." << endl;
        return false;
    }

    User user = users[username];
    if (user.password!= password) {
        cout << "Invalid username or password." << endl;
        return false;
    }

    cout << "Login successful." << endl;
    return true;
}

int main() {
    int choice;
    string username, password;

    while (true) {
        cout << "\n1. Sign Up\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (login(username, password)) {
                    break;
                }
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

