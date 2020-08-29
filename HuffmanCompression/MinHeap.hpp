#pragma once
#include "Vector.hpp"

//Create a leaf node for each unique character and build a min heap of all leaf nodes  
//The value of frequency field is used to compare two nodes in min heap.
//Initially, the least frequent character is at root)


template <typename Type>
class MinHeap {

private:

	Vector<Type> container;

	void heapDown(const int &index);
	void heapUp(const int &index);
	void heapify(); 

	void swap(Type &lhs, Type &rhs);

public:
	MinHeap() {};
	MinHeap(const Type *arr, const std::size_t &size);
	MinHeap(const Vector<Type> &src);

	//Modifiers
	Type top() const;
	void pop();
	void push(const Type &element);

	std::size_t size() const;

	bool compare(Type *lhs, Type *rhs);
};


template<typename Type>
inline bool MinHeap<Type>::compare(Type  *lhs, Type  *rhs)
{
	return *lhs > *rhs;
}


template<typename Type>
inline void MinHeap<Type>::heapDown(const int & index)
{
	std::size_t size = this->container.size();
	std::size_t leftChildIndex = 2 * index + 1;
	std::size_t rightChildIndex = 2 * index + 2;

	if (leftChildIndex >= size)//when the element on that index is a leaf
	{
		return;
	}
	int minIndex = index;

	if (compare((Type *)this->container[minIndex],(Type*) this->container[leftChildIndex])) {
		minIndex = leftChildIndex;
	}

	if ((rightChildIndex < size) && this->compare((Type*)this->container[minIndex], (Type*)this->container[rightChildIndex])) {
		minIndex = rightChildIndex;
	}

	if (minIndex != index) {
		this->swap(this->container[minIndex], this->container[index]);

		this->heapDown(minIndex);
	}
}

	template<typename Type>
	inline void MinHeap<Type>::heapUp(const int & index)
	{
		if (index == 0)//this is top so no need for change, base for recursion
		{
			return;
		}

		std::size_t parentIndex = (index - 1) / 2;

		if (this->compare((Type*)this->container[parentIndex], (Type*)this->container[index])) {
			this->swap(this->container[parentIndex], this->container[index]);

			this->heapUp(parentIndex);
		}
		
}

template<typename Type>
inline void MinHeap<Type>::heapify()
{
	for (int i = this->container.size() - 1; i >= 0; --i) {
		this->heapDown;
	}
}

template<typename Type>
inline void MinHeap<Type>::swap(Type & lhs, Type & rhs)
{
	Type temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template<typename Type>
inline MinHeap<Type>::MinHeap(const Type * arr, const std::size_t & size)
{
	for (std::size_t i = 0; i < size; ++i) {
		this->container[i] = arr[i];
	}
	this->heapify();
}

template<typename Type>
inline MinHeap<Type>::MinHeap(const Vector<Type>& src) : container(src)
{
	this->heapify();
}

template<typename Type>
inline Type MinHeap<Type>::top() const
{
	if (this->container.empty()) {
		throw "HeapIsEmtyException";
	}

	return this->container[0];
}

template<typename Type>
inline void MinHeap<Type>::pop()
{
	if (this->container.empty()) {
		throw "HeapIsEmptyException";
	}

	this->container[0] = this->container[this->container.size() - 1];

	this->container.pop_back();

	this->heapDown(0);
}

template<typename Type>
inline void MinHeap<Type>::push(const Type & element)
{
	std::size_t size = this->container.size();

	this->container.push_back(element);

	this->heapUp(size);
}

template<typename Type>
inline std::size_t MinHeap<Type>::size() const
{
	return this->container.size();
}

	