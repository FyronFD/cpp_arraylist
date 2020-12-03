#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H

#include <iostream>
#include <exception>

template<typename T> class ArrayListIterator{
    private:
        T* ptr;

    public:
        explicit ArrayListIterator(T* ptr);
        ArrayListIterator<T>& operator++();//Prefix Inc
        ArrayListIterator<T> operator++(int);//Postfix Inc
        ArrayListIterator<T>& operator--();//Prefix Dec
        ArrayListIterator<T> operator--(int);//Postfix Dec
        ArrayListIterator<T> operator+(int i) const;//Add
        ArrayListIterator<T> operator-(int i) const;//Subtract
        int operator-(ArrayListIterator<T> RHS) const;//Difference of two Iterators
        T& operator*();//Dereference
        T& operator[](int i);//Returns element i elements forwards or backwards
        bool operator==(ArrayListIterator<T> RHS) const;//Equality
        bool operator!=(ArrayListIterator<T> RHS) const;//Not equal

};


template<typename T> class ArrayList {
    friend ArrayListIterator<T>;

    private:
        int size;
        T* arr;

    public:
        ArrayList();
        ArrayList(T* arr, int size);
        void placeBack(T element);
        void removeBack();
        T get(int index) const;//Accessor
        T& get(int index);//Mutator
        bool contains(T element) const;
        bool isEmpty() const;
        int indexOf(T element) const;
        void clear();
        void trim(int newSize);
        int getSize() const;
        T* toArray() const;
        void insertAt(int i, T element);
        void removeAt(int i);
        void replace(T value, ArrayListIterator<T> start, ArrayListIterator<T> end);
        T operator[](int i) const;//Accessor
        T& operator[](int i);//Mutator
        ArrayListIterator<T> begin();
        ArrayListIterator<T> end();

        ~ArrayList();//Destructor
        ArrayList(const ArrayList<T>& RHS);//Copy Constructor
        ArrayList(ArrayList<T>&& move) noexcept;//Move Constructor
        ArrayList<T>& operator=(const ArrayList<T>& RHS);//Copy Assignment
        ArrayList<T>& operator=(ArrayList<T>&& move) noexcept;//Move Assignment
};

/*
 *
 * ArrayListIterator
 */

template<typename T>
ArrayListIterator<T>::ArrayListIterator(T *ptr) {
    this->ptr = ptr;
}

template<typename T>
ArrayListIterator<T>& ArrayListIterator<T>::operator++() {
    ++ptr;
    return *this;
}

template<typename T>
ArrayListIterator<T> ArrayListIterator<T>::operator++(int) {
    ArrayListIterator<T> copy(ptr);
    ++ptr;
    return copy;
}

template<typename T>
ArrayListIterator<T>& ArrayListIterator<T>::operator--() {
    ++ptr;
    return *this;
}

template<typename T>
ArrayListIterator<T> ArrayListIterator<T>::operator--(int) {
    ArrayListIterator<T> copy(ptr);
    --ptr;
    return copy;
}

template<typename T>
ArrayListIterator<T> ArrayListIterator<T>::operator+(int i) const {
    return ArrayListIterator<T>(ptr + i);
}

template<typename T>
ArrayListIterator<T> ArrayListIterator<T>::operator-(int i) const {
    return ArrayListIterator<T>(ptr - i);
}

template<typename T>
int ArrayListIterator<T>::operator-(ArrayListIterator<T> RHS) const {
    return ptr - RHS.ptr;
}

template<typename T>
T &ArrayListIterator<T>::operator*() {
    return *ptr;
}

template<typename T>
T &ArrayListIterator<T>::operator[](int i) {
    return ptr[i];
}

template<typename T>
bool ArrayListIterator<T>::operator==(ArrayListIterator<T> RHS) const {
    return ptr == RHS.ptr;
}

template<typename T>
bool ArrayListIterator<T>::operator!=(ArrayListIterator<T> RHS) const {
    return ptr != RHS.ptr;
}

/*
 *
 * ArrayList
 */

template<typename T>
ArrayList<T>::ArrayList(){
    arr = new T[0]();
    size = 0;
}

template<typename T>
ArrayList<T>::ArrayList(T *oldArr, int size) {
    this->size = size;
    this->arr = new T[size]();
    for (int i = 0; i < size; i++) {
        this->arr[i] = oldArr[i];
    }
}

template<typename T>
void ArrayList<T>::placeBack(T element) {
    T* newArr = new T[size + 1]();
    for(int i = 0; i < size; i++){
        newArr[i] = arr[i];
    }
    newArr[size] = element;

    delete []arr;
    arr = newArr;
    size++;
}

template<typename T>
void ArrayList<T>::removeBack() {
    T* newArr = new T[size - 1]();
    for (int i = 0; i < size - 1; i++){
        newArr[i] = arr[i];
    }

    delete []arr;
    arr = newArr;
    size--;
}

template<typename T>
T ArrayList<T>::get(int index) const{
    if (index < size && index >= 0){
        return arr[index];
    }
    throw new std::exception("Bad Index");
}

template<typename T>
T& ArrayList<T>::get(int index) {
    if (index < size && index >= 0){
        return arr[index];
    }
    throw new std::exception("Bad Index");
}

template<typename T>
bool ArrayList<T>::contains(T element) const{
    for (int i = 0; i < size; i++){
        if (element == arr[i]){
            return true;
        }
    }
    return false;
}

template<typename T>
bool ArrayList<T>::isEmpty() const{
    return size == 0;
}

template<typename T>
int ArrayList<T>::indexOf(T element) const{
    for (int i = 0; i < size; i++) {
        if (element == arr[i]){
            return i;
        }
    }
    return -1;
}

template<typename T>
void ArrayList<T>::clear() {
    delete [] arr;
    arr = new T[0];
    size = 0;
}

template<typename T>
void ArrayList<T>::trim(int newSize) {
    T* newArr = new T[newSize]();
    for (int i = 0; i < newSize; i++){
        newArr[i] = arr[i];
    }

    delete []arr;
    arr = newArr;
    size = newSize;
}

template<typename T>
int ArrayList<T>::getSize() const{
    return size;
}

template<typename T>
T* ArrayList<T>::toArray() const{
    return arr;
}

template<typename T>
void ArrayList<T>::insertAt(int i, T element) {
    T* newArr = new T[size + 1]();
    for (int n = 0; n < i; n++){
        newArr[n] = arr[n];
    }
    newArr[i] = element;
    for (int n = i + 1; n <= size; n++) {
        newArr[n] = arr[n - 1];
    }

    delete []arr;
    arr = newArr;
    size++;
}

template<typename T>
void ArrayList<T>::removeAt(int i) {
    T* newArr = new T[size - 1]();
    for (int n = 0; n < i; n++){
        newArr[n] = arr[n];
    }
    for (int n = i; n < size; n++) {
        newArr[n] = arr[n + 1];
    }

    delete []arr;
    arr = newArr;
    size--;
}

template<typename T>
void ArrayList<T>::replace(T value, ArrayListIterator<T> start, ArrayListIterator<T> end) {
    for (auto it = start; it != end; ++it) {
        *it = value;
    }
}

template<typename T>
T ArrayList<T>::operator[](int i) const{
    return arr[i];
}

template<typename T>
T& ArrayList<T>::operator[](int i) {
    return arr[i];
}

template<typename T>
ArrayListIterator<T> ArrayList<T>::begin() {
    return ArrayListIterator<T>(arr);
}

template<typename T>
ArrayListIterator<T> ArrayList<T>::end() {
    return ArrayListIterator<T>(&arr[size]);
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete []arr;
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& RHS) {
    size = RHS.size;
    arr = new T[size]();
    for (int i = 0; i < size; i++){
        arr[i] = RHS.arr[i];
    }
}

template<typename T>
ArrayList<T>::ArrayList(ArrayList<T> &&move) noexcept{
    std::cout << "c";
    size = move.size;
    arr = move.arr;
    move.arr = nullptr;
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& RHS){
    this->size = RHS.size;

    delete []arr;
    arr = new T[size];
    for (int i = 0; i < size; i++){
        arr[i] = RHS[i];
    }

    return *this;
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList<T> &&move) noexcept{
    std::cout << "d";
    delete []arr;
    size = move.size;
    arr = move.arr;
    move.arr = nullptr;
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, ArrayList<T>& arrayList){
    for(int i = 0; i < arrayList.getSize(); i++){
        out << arrayList[i] << " ";
    }
    return out;
}

#endif