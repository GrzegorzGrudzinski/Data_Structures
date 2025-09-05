#include <iostream>

#include "Inc/my_vector.h"

using namespace std;

struct STROOKT {
    int number;
    char character;
    // string napis;
};

int main() {
    vector<int> wektor;

    for (int i=0; i<10; ++i) {
        wektor.push_back(i);
    }

    for (int i=0; i<10; ++i) {
        // cout<<wektor<<endl;
        wektor.push_front(i);
    }

    wektor.clean();

    return 0;
}
