#include <iostream>

#include "Inc/my_list.h"

using namespace std;

struct STROOKT {
    int number;
    char character;
    // string napis;
};

int main() {
    list<STROOKT> my_list1;

    STROOKT strookt1;

    for (int i=0; i<10; i++) {
        strookt1.number = i;
        strookt1.character = 'A' + i;
        my_list1.push_back(strookt1);
    }

    my_list1.pop_back();
    my_list1.pop_front();
    my_list1.pop_element(2);

    cout<<"first list size: " << my_list1.get_size()<<endl;

    cout<<"list 1: " <<endl;
    for (STROOKT value : my_list1) {
        cout<<value.number << '\t' << value.character << endl;
    }
    cout<<endl<<endl;

    STROOKT strookt2;
    strookt2.number = 99;
    strookt2.character = 'Z';

    list<STROOKT> my_list2 = {
        strookt1, strookt2
    };

    cout<<"list 2: "<<endl;
    for (STROOKT value : my_list2) {
        cout<<value.number << '\t' << value.character << endl;
    }
    cout<<endl<<endl;

    my_list1 = my_list2;
    cout<<"list 1 "<<endl;
    for (STROOKT value : my_list1) {
        cout<<value.number << '\t' << value.character << endl;
    }
    cout<<endl<<endl;

    my_list2.erase();
    auto iter = my_list2.begin();
    if(iter == nullptr) {
        cout<<"List 2 is empty"<<endl<<endl;
    }

    cout<<my_list1.first().character<<endl;
    cout<<my_list1.last().number<<endl;

    return 0;
}
