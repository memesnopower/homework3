#include "Student.h"

Student::Student() = default;

Student::Student(const std::string& name, const std::string& surname, const std::string& patronymic, const size_t id) {
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->id = id;
}

const std::string& Student::get_name() const {
	return this->name;
}

const std::string& Student::get_surname() const {
	return this->surname;
}

const std::string& Student::get_patronymic() const {
	return this->patronymic;
}

const size_t Student::get_id() const {
	return this->id;
}


void Student::set_name(const std::string& name) {
	this->name = name;
}

void Student::set_surname(const std::string& surname) {
	this->surname = surname;
}

void Student::set_patronymic(const std::string& patronymic) {
	this->patronymic = patronymic;
}

void Student::set_marks(const std::map<std::string, size_t>& marks) {
	this->marks = marks;
}



void Student::add_mark(const std::string& subject, size_t mark) {
	if (mark < 2 || mark > 5) {
		throw InvalidGradeException();
	}
	marks[subject] = mark;
}

const std::map<std::string, size_t>& Student::get_marks() const {
	return this->marks;
}


double Student::get_average() const {

	size_t total = 0;
	for (const auto& mark : marks) {
		total += mark.second;
	}
	
	return static_cast<double>(total) / marks.size();
}

bool Student::operator==(const Student& ob) const {
	return name == ob.name && surname == ob.surname && patronymic == ob.patronymic && id == ob.id;
}

bool Student::isExcellent() const {
	if (get_average() == 5) {
		return true;
	}
	return false;
}

bool Student::isDoubler() const {
	for (const auto& pos : marks) {
		if (pos.second == 2) {
			return true;
			break;
		}
		return false;
	}
}

bool Student::isSimple() const {
	if (get_average() > 3 && get_average() < 5) {
		return true;
	}
	return false;
}



std::ostream& operator<<(std::ostream& os, const Student& student) {
	os << student.name << std::endl;
	os << student.surname << std::endl;
	os << student.patronymic << std::endl;
	os << student.id << std::endl;

	for (const auto& mark : student.marks) {
		os << mark.first << " " << mark.second << std::endl;
	}

	os << "Average: " << std::endl;
	os << student.get_average() << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
	is >> student.name;
	is >> student.surname;
	is >> student.patronymic;
	is >> student.id;
	size_t n = 0;
	is >> n;
	for (size_t i = 0; i < n; ++i) {
		std::string subject;
		size_t mark;
		is >> subject >> mark;
		try {
			student.add_mark(subject, mark);
		}
		catch (InvalidGradeException& e) {
			e.what();
		}
	}

	return is;
}
