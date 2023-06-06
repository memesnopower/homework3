#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include <unordered_set>
#include "Exceptions.h"
#include <memory>
#include <mutex>
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
	void search_id(const size_t id) const;


	void edit_student_name(const size_t id, const std::string& name);
	void edit_student_surname(const size_t id, const std::string& surname);
	void edit_student_patronymic(const size_t id, const std::string& patronymic);
	
	double getAverageMark() const;
	double getAverageMarkBySubject(const std::string& subject) const;

	void printExcellent() const;
	void printDoubler() const;
	void printSimple() const;

	friend std::ostream& operator<<(std::ostream& os, const Group& group);
	friend std::istream& operator>>(std::istream& is, Group& group);

private:
	std::string group_name;
	std::unordered_set<Student, Hasher> students;
};

#endif // GROUP_H
