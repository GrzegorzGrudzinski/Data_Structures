#ifndef LIST_H
#define LIST_H

//TODO add / repair copying constructor

#include <initializer_list>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
class _my_list_iterator
{
    Node <T> *current;
public:
    _my_list_iterator(Node<T>* node) : current(node) {};     //

    T & operator * () {
        return current->data;
    }

    _my_list_iterator & operator ++ () {
        current = current->next;
        return *this;
    }

    _my_list_iterator & operator -- () {
        current = current->prev;
        return *this;
    }

    bool operator !=(const _my_list_iterator & other) const {
        return current != other.current;
    }

    bool operator == (const _my_list_iterator & other) const {
        return current == other.current;
    }
};


template <typename T>
class my_list
{
    Node <T> * head;
    Node <T> * tail;

    int _size;
public:

    my_list();     //
    my_list(std::initializer_list<T>);
    my_list(const my_list& other);
    ~my_list();    // make sure that every node is deleted

    _my_list_iterator<T> begin() {
        return  _my_list_iterator<T> (head);
    }

    _my_list_iterator<T> end() {
        return  _my_list_iterator<T> (tail->next);
    }

    _my_list_iterator<T> begin() const{
        return  _my_list_iterator<T> (head);
    }

    _my_list_iterator<T> end() const{
        return  _my_list_iterator<T> (tail->next);
    }

    my_list<T>& operator = (const my_list<T>& other );

    void push_back(const T& data);// push node to the end
    void push_front(const T& data); // push node to the front
    void insert(int position,const T& data); //

    void pop_back(); // delete last node
    void pop_front();// delete first node
    void pop_element(int position); // delete node at the given position
    void erase(); // delete every element in the my_list

    int get_size() const; // return size of the my_list
    T& get_element(int position); // return node at the given position
    T& first();
    T& last();
};


template<typename T>
my_list<T>::my_list() : head(nullptr), tail(nullptr), _size(0)
{}

template<typename T>
my_list<T>::my_list(std::initializer_list<T> init) : head(nullptr), tail(nullptr), _size(0)
{
    for (const T& data : init) {
        push_back(data);
    }
}

template<typename T>
my_list<T>::my_list(const my_list& other)
{
    for (const T& data : other) {
        push_back(data);
    }
}


template<typename T>
my_list<T>::~my_list()
{
    while (head != nullptr) {
        pop_front();
    }
}

template<typename T>
my_list<T>& my_list<T>::operator=(const my_list<T>& other)
{
    if (&other != this) {
        erase();
        for (const T& data : other) {
            push_back(data);
        }
    }
    return *this;
}

template<typename T>
void my_list<T>::push_back(const T& data)
{
    Node<T>* next = new Node <T>(data);

    // if the my_list was not created create the first Node
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
void my_list<T>::push_front(const T& data)
{
    Node <T>* next = new Node <T>(data);

    // if the my_list was not created create the first Node
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
void my_list<T>::insert(int position,const T& data)
{
    // check if the position is not at the beginning or at the end of the my_list
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
void my_list<T>::pop_back()
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
void my_list<T>::pop_front()
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
void my_list<T>::pop_element(int position)
{
    if (head == nullptr || position < 0 || position > _size-1 ) {
        throw std::out_of_range("Out of range");
        return;
    }
    // check if the position is not at the beginning or at the end of the my_list
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
void my_list<T>::erase()
{
    while (head != nullptr) {
        pop_front();
    }

    _size = 0;
}

template<typename T>
T& my_list<T>::first()
{
    if (head != nullptr) {
        return head->data;
    }
    throw std::out_of_range("Out of range");
}

template<typename T>
T& my_list<T>::last()
{
    if (tail != nullptr) {
        return tail->data;
    }
    throw std::out_of_range("Out of range");
}

template<typename T>
T& my_list<T>::get_element(int position)
{
    // check if the position is not at the beginning or at the end of the my_list
    if (position < 0 || position >= _size) {
        // push_back(data);
        throw std::out_of_range("Out of range");
    }

    Node <T>* temp = head;

    for (int i=0; i < position; i++) {
        temp = temp->next;
    }

    return temp->data;
}


template<typename T>
int my_list<T>::get_size() const
{
    return _size;
}


#endif // LIST_H
