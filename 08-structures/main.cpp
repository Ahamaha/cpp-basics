#include <iostream>
#include <string>

using namespace std;

struct Note {
    string name;
    string phone_number;
    int birthday[3];
};

void InputNotes(Note *notes, const int kNumNotes);
void SortNotes(Note *notes, const int kNumNotes);
void PrintNotes(Note *notes, const int kNumNotes);
void FindMember(Note *notes, string telephone, const int kNumNotes);

int main() {
    const int kNumNotes = 8;
    Note notes[kNumNotes];

    InputNotes(notes, kNumNotes);

    SortNotes(notes, kNumNotes);
    PrintNotes(notes, kNumNotes);

    while (true) {
        string telephone;
        cout << "\nEnter Phone Number (or 'exit' to close the program): ";
        getline(cin, telephone);

        if (telephone == "exit")
            break;
        else
            FindMember(notes, telephone, kNumNotes);
    }

    return 0;
}

void InputNotes(Note *notes, const int kNumNotes) {
    for (int i = 0; i < kNumNotes; i++) {
        cout << "Enter " << i + 1 << " member Full Name: ";
        getline(cin, notes[i].name);
        cout << "Enter " << i + 1 << " member Phone Number: ";
        getline(cin, notes[i].phone_number);
        cout << "Enter " << i + 1 << " member Birth Day (**): ";
        cin >> notes[i].birthday[0];
        cout << "Enter " << i + 1 << " member Birth Month (**): ";
        cin >> notes[i].birthday[1];
        cout << "Enter " << i + 1 << " member Birth Year (****): ";
        cin >> notes[i].birthday[2];
        cin.ignore();
        cout << endl;
    }
}

void SwapByBirthday(Note &notes_j, Note &notes_j1, int k) {
    // k = 0 — day
    // k = 1 — month
    // k = 2 — year
    if (notes_j.birthday[k] > notes_j1.birthday[k])
        swap(notes_j, notes_j1);
    else if (notes_j.birthday[k] == notes_j1.birthday[k] && k != 0)
        SwapByBirthday(notes_j, notes_j1, k - 1);
}

void SortNotes(Note *notes, const int kNumNotes) {
    for (int i = 0; i < kNumNotes - 1; i++)
        for (int j = 0; j < kNumNotes - i - 1; j++)
            SwapByBirthday(notes[j], notes[j + 1], 2);
}

void PrintNotes(Note *notes, const int kNumNotes) {
    for (int i = 0; i < kNumNotes; i++) {
        cout << "Note #" << i + 1;
        cout << "\nName: " << notes[i].name;
        cout << "\nPhone number: " << notes[i].phone_number;
        cout << "\nBirthday: ";
        cout << notes[i].birthday[0] << ".";
        cout << notes[i].birthday[1] << ".";
        cout << notes[i].birthday[2];
        cout << endl << endl;
    }
}

void FindMember(Note *notes, string telephone, const int kNumNotes) {
    for (int i = 0; i < kNumNotes; i++) {
        if (notes[i].phone_number == telephone) {
            cout << "\nMember information:\n";
            cout << "\nName: " << notes[i].name;
            cout << "\nPhone number: " << notes[i].phone_number;
            cout << "\nBirthday: ";
            cout << notes[i].birthday[0] << ".";
            cout << notes[i].birthday[1] << ".";
            cout << notes[i].birthday[2];
            cout << endl;
            break;
        }

        if (i == kNumNotes - 1)
            cout << "\nPhone Number not found...\n";
    }
}