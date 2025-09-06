#include <iostream>

#include "Inc/my_vector.h"

using namespace std;

struct STROOKT {
    int number;
    char character;
    // string napis;
};

int main() {
    my_vector<int> wektor;

    for (int i=0; i<10; ++i) {
        wektor.push_back(i);
        cout<<wektor.get_size()<<' '<<wektor.get_capacity()<<'\n';
    }
    cout<<endl;

    for (int i=0; i<wektor.get_size(); ++i) {
        cout<<wektor[i]<<' ';
    }
    cout<<endl<<endl;

    for (int i=0; i<10; ++i) {
        wektor.push_front(i);
        cout<<wektor.get_size()<<' '<<wektor.get_capacity()<<'\n';
    }
    cout<<endl;

    wektor.insert(10, 999);

    cout<<wektor.get_size()<<' '<<wektor.get_capacity()<<'\n';
    wektor.pop_back();
    wektor.pop_front();
    cout<<wektor.get_size()<<' '<<wektor.get_capacity()<<'\n';
    cout<<endl<<endl;

    for (int i=0; i<wektor.get_size(); ++i) {
        cout<<wektor[i]<<' ';
    }
    cout<<endl<<endl;

    my_vector<int> wektor2 = {1,2,3,4,5};
    for (int data : wektor2) {
        cout<<data<<' ';
    }
    cout<<endl<<endl;

    wektor.clean();

    return 0;
}
