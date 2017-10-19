#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H


#include "vector.h"
#include <iostream>
#include <cmath>

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
		int sizeOfBuffer = 0;
		vector<char> buffer;
		int rear = 0;
		char tempChar;
		vector<char> tempVect;

	public:

		CircularBuffer(int sizeOfBufferIn)
			: sizeOfBuffer(sizeOfBufferIn) {

			buffer.reserve(sizeOfBuffer);
		}

		int getSize() {
			return sizeOfBuffer;
		}

		int getRear() {
			return rear;
		}

		int getFront() {
			return front;
		}

		int count() {
			return abs(getRear()-getFront());
		}

		bool full() {
			return isFull;
		}

		void add(char newChar) {

			if (!(sizeOfBuffer == count())) {

				buffer[getRear()] = newChar;
					if (getRear() < getSize()-1) {
						rear++;
					} else {
						rear = 0;
					}

			} else {
				isFull = true;
			}

		}

		char remove() {

				tempChar = buffer[getFront()];
				buffer[getFront()] = tempChar;
				front = (front+1)%getSize();
				return tempChar;


		}


		// don't write any code below this line

};



#endif
