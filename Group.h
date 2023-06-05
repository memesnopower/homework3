#ifndef GROUP_H
#define GROUP_H

#include <unordered_set>
#include <algorithm>
#include <iostream>
#include "Student.h"

class Group {
public:
	Group();
	Group(const std::string& group_name);

	void add_student(Student &ob);
	
	friend std::istream& operator>>(std::istream& is, Group& ob);
	friend std::ostream& operator<<(std::ostream& os, const Group& ob);

private:
	std::string group_name;
	std::unordered_set<Student, StudentHasher> students;
};

#endif // GROUP_H

