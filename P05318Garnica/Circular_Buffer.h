// Circular_Buffer.h -- starter code
/*  REQUIREMENTS NOTES:

	Functions that need to be written have a comment above the function or constructor

	Do not add any additional instance variables

	You may include the implementation/definition of functions in this header file
		-- no need to create a separate .cpp file

*/

#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	//COMPLETE CONSTRUCTOR BELOW
	CircularBuffer() { 
		_head = 0;
		_size = 0;
		_tail = 0;
		_current = 0;
		_capacity = cap;
	};

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN

	//T& head() {} ignore these two
	//T& tail() {};
	T const& head() const {
		if (_size > 0) {
			return c[_head];
		}
	}
	T const& tail() const { 
		if (_size > 0) {
			return c[_tail];
		}
	}

	//COMPLETE THE push_back function -- circular buffer will overwrite
	//		oldest data if buffer is full.  This function must update
	//		appropriate instance variables
	void push_back(T val) noexcept {
		if (_size == _capacity) { //checks to see if full
			_head = (_head + 1) % _capacity; //if yes then updates head when new item is added
		}
		if (_size == 0) {
			_tail = 0;
		}
		else {
			_tail = (_tail + 1) % _capacity; //same as head it is able to loop around 
		}
		c[_current] = val;
		_current = (_tail + 1) % _capacity;

		if (_size != _capacity) {
			_size = _size + 1;
		}

	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}
		_size = _size - 1;
		_head = (_head + 1) % _capacity;

		// COMPLETE THE REMAINDER OF THIS FUNCTION
	}

	// COMPLETE THE FUNCTIONS BELOW
	int size() const noexcept { 
		return _size;
	}

	int capacity() noexcept {
		return _capacity;
	}

	bool empty() const noexcept { 
		if (_size <= 0) {
			return true;
		}
		else {
			return false;
		}
	} //returns true if buffer is empty

	bool full() const noexcept { 
		if (_size == _capacity) {
			return true;
		}
		else {
			return false;
		}
	}  //returns true if buffer is full

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {
		os << "Buffer Info: head: " << buf._head << ", tail: " << buf._tail << ", current: " << buf._current << ", capacity: " << buf.capacity() << ", size: " << buf.size() << endl;
		os << " Container: "; 
		for (int i = 0; i < buf.capacity(); i++) {
			os << buf.c[i] << " ";
		}
		return os;
	}

private:
	Container c; // will be std::array<T, cap>
	int _head; //oldest item in buffer
	int _tail; //newest item in buffer
	int _size; //# of elem in buffer
	int _current; //next write position in buffer
	int _capacity;
};
#endif


