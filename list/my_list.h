#ifndef LIST_H
#define LIST_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
class _list_iterator
{
    Node <T> *current;
public:
    _list_iterator(Node<T>* node) : current(node) {};     //

    T & operator * () {
        return current->data;
    }

    _list_iterator & operator ++ () {
        current = current->next;
        return *this;
    }

    _list_iterator & operator -- () {
        current = current->prev;
        return *this;
    }

    bool operator !=(const _list_iterator & other) const {
        return current != other.current;
    }

    bool operator == (const _list_iterator & other) const {
        return current == other.current;
    }
};


template <typename T>
class list
{
    Node <T> * head;
    Node <T> * tail;

    int _size;
public:

    list();     //
    ~list();    // make sure that every node is deleted

    _list_iterator<T> begin() {
        return  _list_iterator<T> (head);
    }

    _list_iterator<T> end() {
        return  _list_iterator<T> (tail->next);
    }

    void push_back(const T& data);// push node at the end
    void push_front(const T& data); // push node to the front
    void insert(int position, T data); //

    void pop_back(); // delete last node
    void pop_front();// delete first node
    void pop_element(int position); // delete node at the given position
    void erase(); // delete every element in the list

    int get_size(); // return size of the list
    T& get_element(int position); // return node at the given position
    T& first();
    T& last();

};


template<typename T>
list<T>::list() : head(nullptr), tail(nullptr), _size(0) {}

template<typename T>
list<T>::~list()
{
    while (head != nullptr) {
        pop_front();
    }
}


template<typename T>
void list<T>::push_back(const T& data)
{
    Node<T>* next = new Node <T>(data);

    // if the list was not created create the first Node
    if (head == nullptr) {
        head = tail = next;
    }
    else {
        tail->next = next;
        next->prev = tail;
        tail = next;
    }
    _size++;
}


template<typename T>
void list<T>::push_front(const T& data)
{
    Node <T>* next = new Node <T>(data);

    // if the list was not created create the first Node
    if (head == nullptr) {
        head = tail = next;
    }
    else {
        head->prev = next;
        next->next = head;
        head = next;
    }
    _size++;
}


template<typename T>
void list<T>::insert(int position, T data)
{
    // check if the position is not at the beginning or at the end of the list
    if (position <= 0) {
        push_front(data);
        return;
    }
    else if (position >= _size-1) {
        push_back(data);
        return;
    }

    Node <T>* newNode = new Node <T>(data);
    Node <T>* temp = head;

    for (int i=0; i < position; i++) {
        temp = temp->next;
    }

    //insert the Node
    newNode->prev = temp;
    newNode->next = temp->next;

    temp->next = newNode;
    temp->next->prev = newNode;

    _size++;
}

template<typename T>
void list<T>::pop_back()
{
    if (head == nullptr) {
        return;
    }
    Node <T>* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    _size--;
}


template<typename T>
void list<T>::pop_front()
{
    if (head == nullptr) {
        return;
    }
    Node <T>* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    _size--;
}

template<typename T>
void list<T>::pop_element(int position)
{
    if (head == nullptr || position < 0 || position > _size-1 ) {
        throw 1111;
        return;
    }
    // check if the position is not at the beginning or at the end of the list
    if (position == 0) {
        pop_front();
        return;
    }
    else if (position == _size-1) {
        pop_back();
        return;
    }

    Node <T>* temp = head;

    for (int i=0; i < position; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    _size--;
}

template<typename T>
void list<T>::erase()
{
    while (head != nullptr) {
        pop_front();
    }

    _size = 0;
}



//
// template<typename T>
// T& list<T>::first()
// {
//     Node <T>* temp = head;
//     // if the list was not created create the first Node
//     if (temp == nullptr) {
//         return nullptr;
//     }
//
//     return temp;
// }


template<typename T>
T& list<T>::get_element(int position)
{
    // check if the position is not at the beginning or at the end of the list
    if (position < 0 || position >= _size) {
        // push_back(data);
        throw 11111;
    }

    Node <T>* temp = head;

    for (int i=0; i < position; i++) {
        temp = temp->next;
    }

    return temp->data;
}


template<typename T>
int list<T>::get_size()
{
    return _size;
}


#endif // LIST_H
