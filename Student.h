#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Exceptions.h"
#include <map>

class Student {
public:
	Student();
	Student(const std::string& name, const std::string& surname, const std::string& patronymic, const size_t id);


	bool operator==(const Student& ob) const;
	const std::string& get_name() const;
	const std::string& get_surname() const;
	const std::string& get_patronymic() const;
	const size_t get_id() const;
	void add_mark(const std::string& subject, size_t mark);
	const std::map<std::string, size_t>& get_marks() const;

	double get_average() const;

	bool isExcellent() const;
	bool isDoubler() const;

	friend std::ostream& operator<<(std::ostream& os, const Student& student);
	friend std::istream& operator>>(std::istream& is, Student& student);

private:
	std::string name;
	std::string surname;
	std::string patronymic;
	size_t id = 0;
	std::map<std::string, size_t> marks;
};


struct Hasher {

	std::hash<std::string> strHash;
	std::hash<size_t> stHash;

	size_t operator() (const Student& ob) const {
		const size_t coef = 5171;

		return (pow(coef, 3) * strHash(ob.get_name()) + pow(coef, 2) * strHash(ob.get_surname()) + coef * strHash(ob.get_patronymic()) + stHash(ob.get_id()));
	}
};


#endif // STUDENT_H
