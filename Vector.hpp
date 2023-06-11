#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
	T* data;
	size_t _size = 0;
	size_t _capacity = 0;

	void resize();
	void copyFrom(const Vector<T>&);
	void moveFrom(Vector<T>&&);
	void free();
public:
	Vector();
	Vector(const Vector<T>&);
	Vector(Vector<T>&&) noexcept;
	Vector<T>& operator=(const Vector<T>&);
	Vector<T>& operator=(Vector<T>&&) noexcept;
	~Vector();
	size_t size() const;
	size_t capacity() const;
	bool isEmpty() const;
	void push_back(const T&);
	void push_back(T&&);
	void insert(const T&, size_t);
	void insert(T&&, size_t);
	const T& at(const size_t) const;
	T& at(const size_t);
	T& operator[](const size_t);
	const T& operator[](const size_t) const;
	void pop_back();
	void clear();
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	void erase(size_t);
}; 

template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other) {
	_capacity = other._capacity;
	_size = other._size;
	data = new T[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		data[i] = other.data[i];
	}
}
template <typename T>
void Vector<T>::moveFrom(Vector<T>&& other) {
	_capacity = other._capacity;
	_size = other._size;
	data = other.data;
	other.data = nullptr;
	other._size = 0;
	other._capacity = 0;
}
template <typename T>
void Vector<T>::free() {
	delete[] data;
	data = nullptr;
	_size = 0;
	_capacity = 0;
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copyFrom(other);
}
template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept {
	moveFrom(std::move(other));
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
template <typename T>
Vector<T>::~Vector() {
	free();
}
template <typename T>
Vector<T>::Vector() {
	_capacity = 8;
	data = new T[_capacity];
}
template <typename T>
void Vector<T>::resize() {
	_capacity *= 2;
	T* newData = new T[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		newData[i] = data[i]; // ?? newData[i] = std::move(data[i]);
	}
	delete[] data;
	data = newData;
}
template<typename T>
void Vector<T>::push_back(const T& object) {
	if (_size == _capacity) {
		resize();
	}
	data[_size++] = object;
}
template<typename T>
void Vector<T>::push_back(T&& object) {
	if (_size == _capacity) {
		resize();
	}
	data[_size++] = std::move(object);
}
template <typename T>
void Vector<T>::insert(const T& obj, size_t index) {
	if (index > _size) {
		throw std::invalid_argument("Index out of range");
	}
	if (_size == _capacity) {
		resize();
	}
	for (size_t i = _size; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = obj;
	_size++;
}
template <typename T>
void Vector<T>::insert(T&& obj, size_t index) {
	if (index > _size) {
		throw std::invalid_argument("Index out of range");
	}
	if (_size == _capacity) {
		resize();
	}
	for (size_t i = _size; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = std::move(obj);
	_size++;
}

template <typename T>
const T& Vector<T>::at(const size_t index) const {
	if (index >= _size) {
		throw std::invalid_argument("Index out of range");
	}
	return data[index];
}
template <typename T>
T& Vector<T>::at(const size_t index) {
	if (index >= _size) {
		throw std::invalid_argument("Index out of range");
	}
	return data[index];
}
template <typename T>
T& Vector<T>::operator[](const size_t index) {
	return at(index);
}
template <typename T>
const T& Vector<T>::operator[](const size_t index) const {
	return at(index);
}
template <typename T>
void Vector<T>::pop_back() {
	if (isEmpty()) {
		throw ("Vector is empty");
	}
	_size--;
}
template <typename T>
bool Vector<T>::isEmpty() const {
	return (_size == 0);
}
template <typename T>
size_t Vector<T>::size() const {
	return _size;
}
template <typename T>
size_t Vector<T>::capacity() const {
	return _capacity;
}
template <typename T>
void Vector<T>::clear() {
	free();
	_capacity = 8;
	data = new T[_capacity];
}
template <typename T>
T& Vector<T>::front() {
	if (isEmpty()) {
		throw ("Vector is empty");
	}
	return data[0];
}
template <typename T>
const T& Vector<T>::front() const {
	if (isEmpty()) {
		throw ("Vector is empty");
	}
	return data[0];
}
template <typename T>
T& Vector<T>::back() {
	if (isEmpty()) {
		throw ("Vector is empty");
	}
	return data[_size - 1];
}
template <typename T>
const T& Vector<T>::back() const {
	if (isEmpty()) {
		throw ("Vector is empty");
	}
	return data[_size - 1];
}
template <typename T>
void Vector<T>::erase(size_t index) {
	if (index >= _size) {
		throw std::invalid_argument("Index out of range");
	}
	for (size_t i = index; i < _size - 1; i++)
	{
		data[i] = data[i + 1]; // data[i] = std::move(data[i + 1]);
	}
	_size--;
}
