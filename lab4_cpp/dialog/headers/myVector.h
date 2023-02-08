#ifndef DIALOG_VECTOR_H
#define DIALOG_VECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class myVector {
private:
    T *data;
    size_t Size;
    size_t Capacity;

public:
    myVector();

    explicit myVector(size_t size);

    myVector(const myVector &other);
    myVector(myVector &&other);
    void operator=(const myVector &other);
    void operator=(myVector &&other);

    ~myVector();

    T &operator[](size_t index);

    T *begin();
    T *end();
    const T *begin() const;
    const T *end() const;

    size_t size();
    size_t capacity();

    void push_front(const T &value);
    void push_back(const T &value);
};

template <typename T>
myVector<T>::myVector(): Size(0), Capacity(0), data(nullptr) {}

template<typename T>
myVector<T>::myVector(size_t size): data(new T[size]), Size(size), Capacity(size) {}

template<typename T>
myVector<T>::myVector(const myVector &other):
    data(new T[other.Capacity]), Size(other.Size), Capacity(other.Capacity) {
    copy(other.begin(), other.end(), begin());
}

template<typename T>
myVector<T>::myVector(myVector &&other):
        data(other.data), Size(other.Size), Capacity(other.Capacity) {
    other.data = nullptr;
    other.Size = 0;
    other.Capacity = 0;
}

template<typename T>
void myVector<T>::operator=(const myVector &other) {
    delete[] data;
    data = new T[other.Capacity];
    Size = other.Size;
    Capacity = other.Capacity;
    copy(other.begin(), other.end(), begin());
}

template<typename T>
void myVector<T>::operator=(myVector &&other) {
    delete[] data;
    data = other.data;
    Size = other.Size;
    Capacity = other.Capacity;

    other.data = nullptr;
    other.Size = 0;
    other.Capacity = 0;
}

template<typename T>
myVector<T>::~myVector() {
    delete[] data;
}

template<typename T>
T &myVector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
T *myVector<T>::begin() {
    return data;
}

template<typename T>
const T *myVector<T>::begin() const {
    return data;
}

template<typename T>
T *myVector<T>::end() {
    return data + Size;
}

template<typename T>
const T *myVector<T>::end() const {
    return data + Size;
}

template<typename T>
size_t myVector<T>::size() {
    return Size;
}

template<typename T>
size_t myVector<T>::capacity() {
    return Capacity;
}

template<typename T>
void myVector<T>::push_front(const T &value) {
    if (Size >= Capacity) {
        auto new_cap = Capacity == 0 ? 1 : 2 * Capacity;
        auto new_data = new T[new_cap];

        copy(begin(), end(), new_data + 1);
        delete[] data;

        data = new_data;
        Capacity = new_cap;
    }
    data[0] = value;
    Size++;
}

template<typename T>
void myVector<T>::push_back(const T &value) {
    if (Size >= Capacity) {
        auto new_cap = Capacity == 0 ? 1 : 2 * Capacity;
        auto new_data = new T[new_cap];

        copy(begin(), end(), new_data);
        delete[] data;

        data = new_data;
        Capacity = new_cap;
    }
    data[Size++] = value;
}

#endif