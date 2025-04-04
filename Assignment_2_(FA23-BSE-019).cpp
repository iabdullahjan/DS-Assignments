#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int emergencyLevel; 
    static int count;
    int id;

    Patient(string n, int e) {
        name = n;
        emergencyLevel = e;
        id = ++count; 
    }

    bool operator>(const Patient& p) const {
        return emergencyLevel > p.emergencyLevel;
    }
};

int Patient::count = 0; 
void showMenu() {
    cout << "\nHospital Patient Priority Queue System\n";
    cout << "1. Add Patient\n";
    cout << "2. Treat Next Patient\n";
    cout << "3. Show Treatment Order\n";
    cout << "4. Show Disease Priority List\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void showDiseaseMenu() {
    cout << "\nDisease Priority List:\n";
    cout << "1. Heart Attack (Priority: 1)\n";
    cout << "2. Stroke (Priority: 1)\n";
    cout << "3. Severe Burn (Priority: 2)\n";
    cout << "4. Broken Leg (Priority: 2)\n";
    cout << "5. Fractured Arm (Priority: 2)\n";
    cout << "6. Fever (Priority: 3)\n";
    cout << "7. Food Poisoning (Priority: 3)\n";
    cout << "8. Migraine (Priority: 3)\n";
    cout << "9. Mild Cold (Priority: 4)\n";
    cout << "10. Small Cut (Priority: 4)\n";
}

int main() {
    priority_queue<Patient, vector<Patient>, greater<Patient>> pq; 
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); 
        
        if (choice == 1) {
            string name;
            int emergency;
            cout << "Enter patient's name: ";
            getline(cin, name);
            showDiseaseMenu();
            cout << "Enter emergency level (1-4 based on above list): ";
            cin >> emergency;
            pq.push(Patient(name, emergency));
            cout << "Patient added successfully!\n";
        } 
        else if (choice == 2) {
            if (!pq.empty()) {
                Patient next = pq.top();
                pq.pop();
                cout << "Treating Patient: " << next.name << " (Emergency Level: " << next.emergencyLevel << ")\n";
            } else {
                cout << "No patients in queue!\n";
            }
        } 
        else if (choice == 3) {
            if (pq.empty()) {
                cout << "No patients in queue!\n";
            } else {
                priority_queue<Patient, vector<Patient>, greater<Patient>> temp = pq; 
                cout << "Current Treatment Order:\n";
                while (!temp.empty()) {
                    Patient p = temp.top();
                    cout << "- " << p.name << " (Emergency Level: " << p.emergencyLevel << ")\n";
                    temp.pop();
                }
            }
        }
        else if (choice == 4) {
            showDiseaseMenu();
        }
        else if (choice == 5) {
            cout << "Exiting system.\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
