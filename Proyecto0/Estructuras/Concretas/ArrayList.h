#pragma once

#define LIST_DEFAULT_MAX 10

#include <stdexcept>
#include <iostream>
#include <type_traits>
#include "../Abstractas/List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
protected:
	E* elements;
	int max;
	int size;
	int pos;
	bool isOwner;

private:
	void expand()
	{
		max = max*2;
		E* newElements = new E[max];
		
		for (int i = 0; i <= size; i++)
			newElements[i] = elements[i];

		delete[] elements;
		elements = newElements;
	}
	
public:
	ArrayList(int max = LIST_DEFAULT_MAX, bool isOwner = false) {
		if (max < 1)
			throw runtime_error("Invalid max size.");
		elements = new E[max];
		this->max = max;
		size = 0;
		pos = 0;
		this->isOwner = isOwner;
	}
	~ArrayList() {
		if (isOwner && std::is_pointer<E>::value){
			for (int i = 0; i < size; i++) {
				delete elements[i];
			}
		}
		
		delete[] elements;
	}
	void insert(E element) {
		if (size == max)
			expand();
			//throw runtime_error("List is full.");
		for (int i = size; i > pos; i--)
			elements[i] = elements[i - 1];
		elements[pos] = element;
		size++;
	}
	void append(E element) {
		if (size == max)
			expand();
			//throw runtime_error("List is full.");
		elements[size] = element;
		size++;
	}
	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");
		E result = elements[pos];
		for (int i = pos + 1; i < size; i++)
			elements[i - 1] = elements[i];
		size--;
		return result;
	}
	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");
		return elements[pos];
	}
	void clear() {
		size = pos = 0;
	}
	void goToStart() {
		pos = 0;
	}
	void goToEnd() {
		pos = size;
	}
	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds.");
		this->pos = pos;
	}
	void next() {
		if (pos < size)
			pos++;
	}
	void previous() {
		if (pos > 0)
			pos--;
	}
	bool atStart() {
		return pos == 0;
	}
	bool atEnd() {
		return pos == size;
	}
	int getPos() {
		return pos;
	}
	int getSize() {
		return size;
	}
	void print() {
		cout << "[ ";
		for (int i = 0; i < size; i++) {
			if (i == pos)
				cout << "*";
			if (std::is_pointer<E>::value)
			{
				cout << *elements[i] << " ";	
			}else
			{
				cout << elements[i] << " ";
			}
			
		}
		if (pos == size)
			cout << "*";
		cout << "]" << endl;
	}
	int indexOf(E element, int start)
	{
		if (start < 0) throw runtime_error("invalid starting index");
		for (int i = start; i<=size; i++)
		{
			if (elements[i] == element) return i;
		}
		return -1;
	}
	bool contains(E element)
	{
		return indexOf(element, 0) != - 1; 
	}
};

