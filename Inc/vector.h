#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class _array_iterator
{
    T *current;
public:
    // _array_iterator(arr) : current(node) {};     //

    T & operator * () {
        return current->data;
    }

    _array_iterator & operator ++ () {
        current = current->next;
        return *this;
    }

    _array_iterator & operator -- () {
        current = current->prev;
        return *this;
    }

    bool operator !=(const _array_iterator & other) const {
        return current != other.current;
    }

    bool operator == (const _array_iterator & other) const {
        return current == other.current;
    }
};


template <typename T>
class array
{
    T* arr;

    int _size;
    // int _capacity;

    T* resize () {

    }
public:

    array();     //
    ~array();    // make sure that every node is deleted

    _array_iterator<T> begin() {
        return  _array_iterator<T> ();
    }

    _array_iterator<T> end() {
        return  _array_iterator<T> ();
    }

    void push_back(const T& data);// push node at the end
    void push_front(const T& data); // push node to the front
    void insert(int position, T& data); //

    void pop_back(); // delete last node
    void pop_front();// delete first node
    void pop_element(int position); // delete node at the given position
    void erase(_array_iterator<T> iter1,  _array_iterator<T> iter2 = nullptr); //

    T& first();
    T& last();
    T& get_element(int position); // return data from the given position

    // resize
    // reserve

    int get_size(); // return the size of the array
    int get_capacity(); // return the capacity of the array
};

template <typename T>
array<T>::array() : arr(nullptr), _size(0)
{}


#endif // LIST_H
