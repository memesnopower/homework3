#include "Group.h"
#include "Student.h"

Group::Group() = default;

Group::Group(const std::string& group_name) {
	this->group_name = group_name;
}

void Group::add_student(const Student& ob) {
	this->students.insert(ob);
}

void Group::remove_student(const size_t id) {

	bool flag = false;
	for (const auto& pos : students) {
		if (pos.get_id() == id) {
			students.erase(pos);
			bool flag = true;
		}
	}

	if (!flag) {
		throw StudentNotFoundException();
	}
}

void Group::search_name(const std::string& name) const {
	bool flag = false;
	for (const auto& pos : students) {
		if (pos.get_name() == name) {
			std::cout << "Student found!" << std::endl;
			std::cout << pos << std::endl;
			flag = true;
		}
	}

	if (!flag) {
		throw StudentNotFoundException();
	}
}

void Group::search_surname(const std::string& surname) const {
	bool flag = false;
	for (const auto& pos : students) {
		if (pos.get_surname() == surname) {
			std::cout << "Student found!" << std::endl;
			std::cout << pos << std::endl;
			flag = true;
		}
	}

	if (!flag) {
		throw StudentNotFoundException();
	}
}

void Group::search_patronymic(const std::string& patronymic) const {
	bool flag = false;
	for (const auto& pos : students) {
		if (pos.get_patronymic() == patronymic) {
			std::cout << "Student found!" << std::endl;
			std::cout << pos << std::endl;
			flag = true;
		}
	}

	if (!flag) {
		throw StudentNotFoundException();
	}
}

double Group::getAverageMark() const {

	if (students.size() == 0) {
		throw ZeroDimensionalityException();
	}

	double total = 0;
	for (const auto& pos : students) {
		total += pos.get_average();
	}

	return total / students.size();
}

double Group::getAverageMarkBySubject(const std::string& subject) const {

	if (students.size() == 0) {
		throw ZeroDimensionalityException();
	}

	double total = 0;

	for (const auto& pos : students) {
		const auto& grades = pos.get_marks();
		auto it = grades.find(subject);
		if (it != grades.end()) {
			total += it->second;
		}
	}

	return total / students.size();
}

void Group::printExcellent() const {
	std::cout << "List of Excellent students" << std::endl;
	for (const auto& pos : students) {
		if (pos.isExcellent() == true) {
			std::cout << pos << std::endl;
		}
		else {
			std::cout << "Empty :(" << std::endl;
		}
	}
}

void Group::printDoubler() const {
	std::cout << "List of Doubler students" << std::endl;
	for (const auto& pos : students) {
		if (pos.isDoubler() == true) {
			std::cout << pos << std::endl;
		}
		else {
			std::cout << "Empty :)" << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
	os << group.group_name << std::endl;

	for (const auto& pos : group.students) {
		os << pos << std::endl;
	}

	return os;
}

std::istream& operator>>(std::istream& is, Group& group) {
	is >> group.group_name;
	size_t n = 0;
	is >> n;
	for (size_t i = 0; i < n; ++i) {
		Student temp;

		is >> temp;
	}

	return is;
}
