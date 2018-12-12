#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string file_name = "text.txt";
    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "ERROR!!! Can't open file: " << file_name << ".\n";
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        string sentence = "";
        for (size_t i = 0; i < line.length(); i++) {
            sentence += line[i];
            if (line[i] == '.' || line[i] == '!' || line[i] == '?') {
                if (sentence.substr(0, 2) == " -")
                    cout << sentence << endl;
                sentence = "";
            }
        }
    }

    fin.close();
    return 0;
}