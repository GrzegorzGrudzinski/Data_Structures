#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <stdexcept>

template <typename T>
class _vector_iterator
{
    T* array;

public:
    _vector_iterator(T* arr) : array(arr) {};     //

    T & operator * () {
        return *array;
    }

    _vector_iterator & operator++() {
        ++array;
        return *this;
    }

    _vector_iterator & operator--() {
        --array;
        return *this;
    }

    bool operator!=(const _vector_iterator<T>& otherArray) const {
        return array != otherArray.array;
    }

    bool operator==(const _vector_iterator<T>& otherArray) const {
        return array == otherArray.array;
    }

};


template <typename T>
class vector
{
    T* arr;

    int _size;
    int _capacity;

    void _reserve ();
public:
    vector();     //
    vector(std::initializer_list<T> init);
    ~vector();    // make sure that every node is deleted

    T& operator[](int index);

    _vector_iterator<T> begin() {
        return _vector_iterator<T> (arr);
    }
    _vector_iterator<T> end() {
        return _vector_iterator<T> ((arr+_size));
    }

    void push_back(const T& data);// push data at the end
    void push_front(const T& data); // push data to the front
    void insert(int position, const T& data); // insert data after the given position

    // void erase(_vector_iterator<T> iter1,  _vector_iterator<T> iter2 = nullptr); //
    void clean();

    void pop_back(); // delete last node
    void pop_front();// delete first node
    void pop_element(int position); // delete node at the given position
    // resize
    // reserve

    int get_size() const; // return the size of the array
    int get_capacity() const; // return the capacity of the array
};

/************************************
 *
 ************************************/

template <typename T>
void vector<T>::_reserve()
{
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


template <typename T>
vector<T>::vector() : arr(nullptr), _size(0), _capacity(0)
{}

template<typename T>
vector<T>::vector(std::initializer_list<T> init) : arr(nullptr), _size(0), _capacity(0)
{
    for (const T& data : init) {
        push_back(data);
    }
}


template <typename T>
vector<T>::~vector()
{
    clean();
}


template <typename T>
T& vector<T>::operator[] (int index)
{
    if (index < _size && index >= 0) {
        return arr[index];
    }
    throw std::out_of_range("Out of range");
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
void vector<T>::insert(int position,const T& data)
{
    if (position == 0) {
        push_front(data);
        return;
    }
    if (position == _size) {
        push_back(data);
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
void vector<T>::pop_back() {
    _size--;
}

template <typename T>
void vector<T>::pop_front() {
    for (int i=0; i<_size-1; ++i) {
        arr[i] = arr[i+1];
    }

    _size--;
}


template <typename T>
void vector<T>::clean() {
    delete [] arr;
    arr = nullptr;
    _capacity = 0;
    _size = 0;
}

template <typename T>
int vector<T>::get_size() const {
    return _size;
}

template <typename T>
int vector<T>::get_capacity() const {
    return _capacity;
}


#endif // VECTOR_H
