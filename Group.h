#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include <unordered_set>
#include "Exceptions.h"
#include <iostream>

class Group {
public:
	Group();
	Group(const std::string& group_name);

	void add_student(const Student& ob);
	void remove_student(const size_t id);
	void search_name(const std::string& name) const;
	void search_surname(const std::string& surname) const;
	void search_patronymic(const std::string& patronymic) const;

	double getAverageMark() const;
	double getAverageMarkBySubject(const std::string& subject) const;

	void printExcellent() const;
	void printDoubler() const;

	friend std::ostream& operator<<(std::ostream& os, const Group& group);
	friend std::istream& operator>>(std::istream& is, Group& group);

private:
	std::string group_name;
	std::unordered_set<Student, Hasher> students;
};


#endif // GROUP_H
