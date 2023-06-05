#include "Student.h"

Student::Student() = default;

Student::Student(std::string name, std::string surname, std::string patronymic, size_t studentId) {
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->studentId = studentId;
}

void Student::add_discipline(Discipline ob) {
	disciplines.push_back(ob);
}

double Student::get_average_mark() const {
	double total = 0;
	for (const auto& pos : disciplines) {
		total += pos.mark;
	}

	return total / disciplines.size();
}

Student::~Student() = default;


std::string Student::get_name() const {
	return this->name;
}

std::string Student::get_surname() const {
	return this->surname;
}


std::string Student::get_patronymic() const {
	return this->patronymic;
}

size_t Student::get_id() const {
	return this->studentId;
}

std::vector<Discipline> Student::get_disciplines() const {
	return disciplines;
}

bool Student::operator==(const Student& s) const {
	return name == s.name && surname == s.surname && patronymic == s.patronymic && studentId == s.studentId;
}


std::istream& operator>>(std::istream& is, Student& ob) {
	std::getline(is, ob.name);
	std::getline(is, ob.surname);
	std::getline(is, ob.patronymic);
	is >> ob.studentId;

	// Добавить для оценок 

	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& ob) {
	os << "Name: " << ob.name << std::endl;
	os << "Surnamne: " << ob.surname << std::endl;
	os << "Patronymic: " << ob.patronymic << std::endl;
	os << "Student ID: " << ob.studentId << std::endl;

	// Доделать для оценок

	return os;
}
