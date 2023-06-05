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
	bool operator<(const Student& ob) const;

	bool is_Excellent() const;
	bool is_Doubler() const;

	std::string get_name() const;
	std::string get_surname() const;
	std::string get_patronymic() const;
	size_t get_id() const;
	std::vector<Discipline> get_disciplines() const; 

	void set_name(const std::string& name);
	void set_surname(const std::string& surname);
	void set_patronymic(const std::string& patronymic);
	void set_id(const size_t id);
	void set_discipline(const std::vector<Discipline>& disciplines);

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

struct StudentHasher {
	size_t operator()(const Student& s) const {
		return std::hash<std::string>()(s.get_name()) ^ std::hash<int>()(s.get_id());
	}
};

#endif // STUDENT_H
