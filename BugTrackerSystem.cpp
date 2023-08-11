#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bug {
public:
    int id;
    string title;
    string description;
    string status;
    string severity;
    string assignedUser;

    Bug(int id, const string& title, const string& description,
        const string& status, const string& severity, const string& assignedUser)
        : id(id), title(title), description(description), status(status), severity(severity), assignedUser(assignedUser) {}
};

class BugTracker {
private:
    vector<Bug> bugs;
    int lastBugId;

public:
    BugTracker() : lastBugId(0) {}

    void addBug(const string& title, const string& description,
                const string& status, const string& severity, const string& assignedUser) {
        Bug newBug(++lastBugId, title, description, status, severity, assignedUser);
        bugs.push_back(newBug);
    }

    void displayAllBugs() {
        cout << "Bug List:" << endl;
        for (const auto& bug : bugs) {
            cout << "ID: " << bug.id << endl;
            cout << "Title: " << bug.title << endl;
            cout << "Description: " << bug.description << endl;
            cout << "Status: " << bug.status << endl;
            cout << "Severity: " << bug.severity << endl;
            cout << "Assigned User: " << bug.assignedUser << endl;
            cout << "-------------------------------------" << endl;
        }
    }
};

int main() {
    BugTracker bugTracker;

    bugTracker.addBug("Crash on startup", "The application crashes when launched.", "Open", "High", "John");
    bugTracker.addBug("UI glitch", "The button color is incorrect.", "Open", "Low", "Alice");

    int option;
    do {
        cout << "Bug Tracking System" << endl;
        cout << "1. Add Bug" << endl;
        cout << "2. View All Bugs" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1: {
            string title, description, status, severity, assignedUser;
            cout << "Enter Bug Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Bug Description: ";
            getline(cin, description);
            cout << "Enter Status: ";
            getline(cin, status);
            cout << "Enter Severity: ";
            getline(cin, severity);
            cout << "Enter Assigned User: ";
            getline(cin, assignedUser);
            bugTracker.addBug(title, description, status, severity, assignedUser);
            cout << "Bug added successfully!" << endl;
            break;
        }

        case 2:
            bugTracker.displayAllBugs();
            break;

        case 0:
            cout << "Exiting Bug Tracking System." << endl;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
