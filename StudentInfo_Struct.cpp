#include <iostream>
using namespace std;

struct student {
    string name;
    string SRCODE;
    string SUBJ[3];
    string TIME[3];
};
void mainMenu(student* students, int& numStudents);
void displayDetails(student* students, int numStudents) {
    // Display the students
    string SC;
    int temp = 0;
    cout << "\nEnter the SRCODE to display the details: ";
    cin.ignore();
    getline(cin, SC);
    for (int i = 0; i < numStudents; i++) {
        if (SC == students[i].SRCODE) {
            cout << "Name: " << students[i].name << endl;
            for (int j = 0; j < 3; j++) {
                cout << "Subject Name: " << students[i].SUBJ[j] << endl;
                cout << "Time: " << students[i].TIME[j] << endl;
            }
            temp = 1;
            break;
        }
    }
    if (temp == 0) {
        cout << "\nThe Student identified by the given ID does not exist." << endl;
    }
}

bool isDupeSC(student* students, int numStudents, const string& SRCODE) {
    for (int i = 0; i < numStudents; i++) {
        if (SRCODE == students[i].SRCODE) {
            return true;
        }
    }
    return false;
}

bool addStdInfo(student* students, int& numStudents) {
    char choice = 'y';
    do {
        cout << "Enter Name of student No. " << numStudents + 1 << ": ";
        cin.ignore();
        getline(cin, students[numStudents].name);
        
        bool duplicateSRCODE = false;
        do {
            cout << "Enter SR-CODE: ";
            cin >> students[numStudents].SRCODE;
            duplicateSRCODE = isDupeSC(students, numStudents, students[numStudents].SRCODE);
            if (duplicateSRCODE) {
                cout << "Duplicate SRCODE. Please enter a different SRCODE." << endl;
            }
        } while (duplicateSRCODE);

        for (int j = 0; j < 3; j++) {
            cout << "Enter Subject No. " << j + 1 << ": ";
            cin >> students[numStudents].SUBJ[j];
            cout << "Enter Time: ";
            cin >> students[numStudents].TIME[j];
        }
        numStudents++;
        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;

        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid choice. Please enter 'y' or 'n': ";
            cin >> choice;
        }
    } while (choice == 'y' || choice == 'Y');
    return (choice == 'y' || choice == 'Y');
}


void mainMenu(student* students, int& numStudents) {
    int ch;
    bool continueMenu = true;
    while(continueMenu){
        cout << "\t========== STUDENT ID DETAILS ==========\n";
        cout << "\t[ 1 ] Add Student Information\n";
        cout << "\t[ 2 ] Get Student Information\n";
        cout << "\t[ 3 ] Exit the Program\n";
        cout << "\tChoice: ";
        cin >> ch;
        

        switch (ch) {
        case 1:
            addStdInfo(students, numStudents);
            break;
        case 2:
            displayDetails(students, numStudents);
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
    delete[] students;
}

int main() {
    int numStudents = 0;
    student* students = new student[100];
    mainMenu(students, numStudents);
    delete[] students;
    return 0;
}
