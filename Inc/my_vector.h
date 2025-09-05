#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class _vector_iterator
{
    T *current;
public:
    // _vector_iterator(arr) : current(node) {};     //

    // T & operator * () {}
    //
    // _vector_iterator & operator ++ () {return *this;}
    //
    // _vector_iterator & operator -- () {return *this;}
    //
    // bool operator !=(const _vector_iterator & other) const {
    //     // return current != other.current;
    // }
    //
    // bool operator == (const _vector_iterator & other) const {
    //     // return current == other.current;
    // }
};


template <typename T>
class vector
{
    T* arr;

    int _size;
    int _capacity;

    void _reserve () {
        int tempCapacity;
        if (_size == _capacity) {
            if (_capacity == 0) {
                tempCapacity = 1;
            } else {
                tempCapacity = 2*_capacity;
            }

            T* temp = new T [tempCapacity];
            for (int i=0; i<_size; ++i) {
                temp[i] = arr[i];
            }
            delete [] arr;
            arr = temp;
            _capacity = tempCapacity;
        }
    }

public:

    vector();     //
    ~vector();    // make sure that every node is deleted

    // _vector_iterator<T> begin() {}
    // _vector_iterator<T> end() {}

    void push_back(const T& data);// push node at the end
    void push_front(const T& data); // push node to the front
    void insert(int position, T& data); //

    void pop_back(); // delete last node
    void pop_front();// delete first node
    void pop_element(int position); // delete node at the given position
    // void erase(_vector_iterator<T> iter1,  _vector_iterator<T> iter2 = nullptr); //
    void clean();

    T& first();
    T& last();
    T& get_element(int position); // return data from the given position

    // resize
    // reserve

    int get_size(); // return the size of the array
    int get_capacity(); // return the capacity of the array
};

template <typename T>
vector<T>::vector() : arr(nullptr), _size(0), _capacity(0)
{}

template <typename T>
vector<T>::~vector()
{
    clean();
}


template <typename T>
void vector<T>::push_back(const T& data)
{
    _reserve();
    arr[_size] = data;
    _size++;
}

template <typename T>
void vector<T>::push_front(const T& data)
{
    _reserve();

    for (int i=_size; i>0; --i) {
        arr[i] = arr[i-1];
    }
    arr[0] = data;

    _size++;
}

template <typename T>
void vector<T>::insert(int position, T& data)
{
    if (position == 0) {
        push_front();
        return;
    }
    if (position == _size) {
        push_back();
        return;
    }
    if (position > _size || position < 0) {
        throw std::out_of_range("Out of range");
    }


    _reserve();

    for (int i=_size; i>position; --i) {
        arr[i] = arr[i-1];
    }
    arr[position] = data;

    _size++;
}

template <typename T>
void vector<T>::clean() {
    delete [] arr;
    arr = nullptr;
    _capacity = 0;
    _size = 0;
}

#endif // VECTOR_H
