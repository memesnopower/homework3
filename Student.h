#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

struct Discipline {
	std::string subject;
	size_t mark;
};

class Student {
public:
	Student();
	Student(std::string name, std::string surname, std::string patronymic, size_t studentId);
	~Student();

	void add_discipline(Discipline ob);
	double get_average_mark() const;

	std::string get_name() const;
	std::string get_surname() const;
	std::string get_patronymic() const;
	size_t get_id() const;
	std::vector<Discipline> get_disciplines() const; 

	bool operator==(const Student& s) const;

	friend std::ostream& operator<<(std::ostream& os, const Student& ob);
	friend std::istream& operator>>(std::istream& is, Student& ob);
private:
	std::string name;
	std::string surname;
	std::string patronymic;
	size_t studentId = 0;
	std::vector<Discipline> disciplines;
};

#endif // STUDENT_H