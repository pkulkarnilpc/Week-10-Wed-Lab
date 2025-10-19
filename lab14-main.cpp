#include "HashTableOpen.hpp"
#include <string>

int main() {
    // variables
    HashTableOpen<string, string> dict;
    string userWord, s;
    int userChoice = 0;
    bool flag = false;

    // add data to the dictionary
    dict.insert("banana", "a fruit that many like, or a phone");
    dict.insert("cactus", "a pointy plant");
    dict.insert("dog", "a domesticated fluff ball");
    dict.insert("graph", "an awesome data structure!");
    dict.insert("haskell", "fantastic programming language, go learn it");
    dict.insert("igloo", "a cool house");
    dict.insert("phoenix", "a bird on fire");
    dict.insert("quack", "said Mr. Duck");

    // display menu
    cout << "Welcome to my open hash table dictionary program!\n";
    cout << "Here are your options:\n";
    cout << "\t1. Find\n";
    cout << "\t2. Insert\n";
    cout << "\t3. Remove\n";
    cout << "\t4. Size\n";
    cout << "\t5. Clear\n";
    cout << "\t6. Quit\n";

    // loop until the user quits
    do {
        cout << "Enter your option: ";
        cin  >> userChoice;

        switch (userChoice) {
            // find
            case 1:
                try {
                    cout << "Enter a key to search my dictionary: ";
                    cin.ignore();
                    getline(cin, userWord);
                    s = dict.find(userWord);
                    cout << s << endl;
                }
                catch (string& e) {
                    cout << e << endl;
                }
                break;

            // insert
            case 2:
                cout << "Enter the key of the new record: ";
                cin.ignore();
                getline(cin, userWord);
                cout << "Enter the value of the new record: ";
                getline(cin, s);
                dict.insert(userWord, s);
                break;

            // remove
            case 3:
                try {
                    cout << "Enter the key of the record to be "
                         << "removed from my dictionary: ";
                    cin.ignore();
                    getline(cin, userWord);
                    dict.remove(userWord);
                }
                catch (string& e) {
                    cout << e << endl;
                }
                break;

            // size
            case 4:
                cout << "Dictionary size is " << dict.size() << endl;
                break;

            // clear
            case 5:
                cout << "Clearing out my dictionary . . . ";
                dict.clear();
                cout << "cleared!\n";
                break;

            // quit
            case 6:
                flag = true;
                break;
        }
    } while (!flag);

    // terminate
    return 0;
}
