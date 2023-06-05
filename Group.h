
#include "Student.h"
#include <unordered_set>
#include <iostream>

class Group {
public:
	Group();
	Group(const std::string& group_name);

	void add_student(const Student& ob);
	/*void remove_student(const std::string& name);*/

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
