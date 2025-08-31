#include <iostream>

#include "list/my_list.h"

using namespace std;

struct STROOKT {
    int liczba1;
    char znak;
    // string napis;
};

int main() {
    list<STROOKT> my_list;

    STROOKT strookt;

    strookt.liczba1 = 1;
    strookt.znak = 'A';
    // strookt.napis = "Pierwszy wezel";
    my_list.push_back(strookt);

    strookt.liczba1 = 2;
    strookt.znak = 'B';
    // strookt.napis = "Drugi wezel";
    my_list.push_back(strookt);

    strookt.liczba1 = 3;
    strookt.znak = 'C';
    // strookt.napis = "Drugi wezel";
    my_list.push_back(strookt);

    strookt.liczba1 = 10;
    strookt.znak = 'Z';
    // strookt.napis = "Drugi wezel";
    my_list.push_front(strookt);

    strookt.liczba1 = 20;
    strookt.znak = 'Q';
    // strookt.napis = "Drugi wezel";
    my_list.insert(55 , strookt);

    // my_list.pop_back();
    // my_list.pop_front();
    // my_list.pop_element(2);
    // my_list.erase();


    cout<<my_list.get_size()<<endl;

    for (STROOKT value : my_list) {
        cout<<value.liczba1 << '\t' << value.znak << endl;
    }


    // cout<<my_list.first().znak<<endl;
    // cout<<my_list.last().znak<<endl;



    return 0;
}
