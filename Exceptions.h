#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class StudentNotFoundException : public std::exception {
public:
	StudentNotFoundException() = default;

	void what() {
		std::cout << "Student not found in the group" << std::endl;
	}
};

class ZeroDimensionalityException : public std::exception {
public:
	ZeroDimensionalityException() = default;
	
	void what() {
		std::cout << "The dimension of the array is zero" << std::endl;
	}
};

class InvalidGradeException : public std::exception {
public:
	InvalidGradeException() = default;

	void what() {
		std::cout << "The score can be from 2 to 5" << std::endl;
	}
};

#endif // EXCEPTIONS_H

