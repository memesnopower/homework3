#include "Group.h"

Group::Group() = default;

Group::Group(const std::string& group_name) {
	this->group_name = group_name;
}

void Group::add_student(Student& ob) {
	students.insert(ob);
}

std::istream& operator>>(std::istream& is, Group& ob) {
	std::getline(is, ob.group_name);
	is.ignore();

	for (size_t i = 0; i < 2; ++i) {
		Student temp;
		is >> temp;
		ob.students.insert(temp);
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Group& ob) {
	os << "Group name: " << ob.group_name << std::endl;

	for (const auto& pos : ob.students) {
		os << pos << std::endl;
	}

	return os;
}
