#include <iostream> 
#include <fstream>

using namespace std;

int main() {
    // Open the binary file (use Mac file path structure)
    ifstream f("/Users/cee/coding/practice /cpp/integer.bin", ios::binary);

    if (!f.is_open()) {
        cout << "Can not open file:" << endl;
        return 1;
    }

    int x;
    while (f.read(reinterpret_cast<char *>(&x), sizeof(int))) {
        cout << x << "\t";
    }

    cout << endl; // Flush line output
    f.close();
    
    return 0;
}