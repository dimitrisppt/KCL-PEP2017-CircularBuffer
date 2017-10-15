#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H


#include "vector.h"
#include <iostream>

using std::cout;
using pep::vector;


/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {

	private:
		int front = 0;
		bool isFull = false;
		int sizeOfBuffer;
		vector<char> buffer;
		int rear = 0;
		char tempChar = ' ';

	public:

		CircularBuffer(const int sizeOfBufferIn)
			: sizeOfBuffer(sizeOfBufferIn) {

			buffer.reserve(sizeOfBuffer);
		}

		int getSize() {
			return sizeOfBuffer;
		}

		int count() {
			return front;
		}

		bool full() {
			return isFull;
		}

		void add(char newChar) {

			buffer[count()-1] = newChar;
			if (front < getSize()) {
				front++;
			} else {
				front = 0;
			}
		}

		char remove() {
			cout << rear <<"\n";
			tempChar =  buffer[rear];
			buffer[count()] = ' ';
			front--;
			if (rear < getSize()-1) {
				rear++;
			} else {
				rear = 0;
			}
			return tempChar;

		}

};


// don't write any code below this line

#endif
