#include <iostream>
using namespace std;

class stdInfo {
public:
    string name;
    string SRCODE;
    string TIME[3];
    string SUBJ[3];
    stdInfo* next;

    stdInfo() : next(nullptr) {}
};

class stdManager {
private:
    stdInfo* head;
    stdInfo* tail;
    int numStudents = 0;

public:
    stdManager() : head(nullptr), tail(nullptr) {}

    void displayDetails() {
        // Display the students
        string SC;
        int temp = 0;
        cout << "\nEnter the SRCODE to display the details: ";
        cin.ignore();
        getline(cin, SC);
        stdInfo* curr = head;
        while (curr != nullptr) {
            if (SC == curr->SRCODE) {
                cout << "Name: " << curr->name << endl;
                for (int j = 0; j < 3; j++) {
                    cout << "Subject Name: " << curr->SUBJ[j] << endl;
                    cout << "Time: " << curr->TIME[j] << endl;
                }
                temp = 1;
                break;
            }
            curr = curr->next;
        }
        if (temp == 0) {
            cout << "\nThe Student identified by the given ID does not exist." << endl;
        }
    }

    bool isDupeSC(const string& SRCODE) {
        stdInfo* curr = head;
        while (curr != nullptr) {
            if (SRCODE == curr->SRCODE) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void addStdInfo() {
        char choice = 'y';
        do {
            stdInfo* newStudent = new stdInfo;
            cout << "Enter Name of student No. " << numStudents + 1 << ": ";
            cin.ignore();
            getline(cin, newStudent->name);

            bool duplicateSRCODE = false;
            do {
                cout << "Enter SR-CODE: ";
                cin >> newStudent->SRCODE;
                duplicateSRCODE = isDupeSC(newStudent->SRCODE);
                if (duplicateSRCODE) {
                    cout << "Duplicate SRCODE. Please enter a different SRCODE." << endl;
                }
            } while (duplicateSRCODE);

            for (int j = 0; j < 3; j++) {
                cout << "Enter Subject No. " << j + 1 << ": ";
                cin >> newStudent->SUBJ[j];
                cout << "Enter Time: ";
                cin >> newStudent->TIME[j];
            }

            if (head == nullptr) {
                head = newStudent;
                tail = newStudent;
            } else {
                tail->next = newStudent;
                tail = newStudent;
            }
            numStudents++;
            cout << "Do you want to add another student? (y/n): ";
            cin >> choice;

            while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
                cout << "Invalid choice. Please enter 'y' or 'n': ";
                cin >> choice;
            }
        } while (choice == 'y' || choice == 'Y');
    }

    void mainMenu() {
        int ch;
        bool continueMenu = true;
        while (continueMenu) {
            cout << "\t========== STUDENT ID DETAILS ==========\n";
            cout << "\t[ 1 ] Add Student Information\n";
            cout << "\t[ 2 ] Get Student Information\n";
            cout << "\t[ 3 ] Exit the Program\n";
            cout << "\tChoice: ";
            cin >> ch;

            switch (ch) {
                case 1:
                    addStdInfo();
                    break;
                case 2:
                    displayDetails();
                    break;
                case 3:
                    cout << "Exiting Program.";
                    continueMenu = false;
                    break;
                default:
                    cout << "Invalid input. Please try again.";
                    break;
            }
        }
    }
};

int main() {
    stdManager stdM;
    stdM.mainMenu();
    return 0;
}
