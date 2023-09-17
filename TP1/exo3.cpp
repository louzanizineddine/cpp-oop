#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string sentence, token;

    cout << "Type a sentence: " << endl;
    getline(cin, sentence);

    cout << "sentence == " << sentence << endl;

    istringstream iss(sentence);

    while (getline(iss, token, ' ')) {
        cout << token << endl;
    }

    return 0;
}