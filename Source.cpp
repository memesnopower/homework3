#include "Group.h"
#include "Exceptions.h"
#include <thread>

std::mutex mute;

void showMenu() {
	std::cout << "=====MENU=====" << std::endl;
	std::cout << "1 - Add student" << std::endl;
	std::cout << "2 - Show list of students" << std::endl;
	std::cout << "3 - Remove student" << std::endl; // Фиксануть
	std::cout << "4 - Search student" << std::endl;
	std::cout << "5 - Edit student" << std::endl;
	std::cout << "6 - View the GPA in all subjects for the whole group" << std::endl;
	std::cout << "7 - View the GPA in a particular subject for the whole group" << std::endl;
	std::cout << "8 - View the list of excellent students" << std::endl;
	std::cout << "9 - View the list of debtors" << std::endl;
	std::cout << "10 - View the list of regular students" << std::endl;
	std::cout << "11 - Save to file" << std::endl;
	std::cout << "12 - Read from file" << std::endl;
	std::cout << "0 - Exit" << std::endl;
}

void removeStudent(Group& group, const size_t id) {
	mute.lock();
	try {
		group.remove_student(id);
	}
	catch (StudentNotFoundException& e) {
		e.what();
	}
	mute.unlock();
}

void writeInToFile(Group& group, const std::string& fileName) {
	mute.lock();
	std::fstream fout(fileName);
	fout << group;
	mute.unlock();
}

void readFromFile(Group& group, const std::string& fileName) {
	mute.lock();
	std::fstream fin(fileName);
	fin >> group;
	mute.unlock();
}




int main() {
	Group group("IU8-22");
	
	bool flag = false;
	Student temp;
	std::string subject, name, surname, patronymic;
	size_t id = 0;
	int choice1 = 0;
	while (!flag) {
		showMenu();
		int choice = 0;
		int choice2 = 0;
		std::cin >> choice;
		switch (choice) {
		case 0:
			flag = true;
			break;
		case 1:
			std::cin >> temp;
			group.add_student(temp);
			break;
		case 2:
			std::cout << group;
			break;
		case 3:
		{
			std::cout << "Enter student id: ";
			std::cin >> id;
			std::thread t(removeStudent, std::ref(group), std::ref(id));
			t.join();
			break;
		}
		case 4:
			std::cout << "Choose which parameter to search for a student by -->" << std::endl;
			std::cout << "1 - name" << std::endl;
			std::cout << "2 - surname" << std::endl;
			std::cout << "3 - patronymic" << std::endl;
			std::cout << "4 - id" << std::endl;

			std::cin >> choice1;

			switch (choice1) {
			case 1:
				std::cout << "Enter student name: ";
				std::cin >> name;
				try {
					group.search_name(name);
				}
				catch (StudentNotFoundException& e) {
					e.what();
				}
				break;
			case 2:
				std::cout << "Enter student surname: ";
				std::cin >> surname;
				try {
					group.search_surname(surname);
				}
				catch (StudentNotFoundException& e) {
					e.what();
				}
				break;
			case 3:
				std::cout << "Enter student patronymic: ";
				std::cin >> patronymic;
				try {
					group.search_patronymic(patronymic);
				}
				catch (StudentNotFoundException& e) {
					e.what();
				}
				break;
			case 4:
				std::cout << "Enter student id: ";
				std::cin >> id;
				try {
					group.search_id(id);
				}
				catch (StudentNotFoundException& e) {
					e.what();
				}
				break;
			}
			break;
		case 5:
			std::cout << "Select what you want to edit -->" << std::endl;
			std::cout << "1 - Student name" << std::endl;
			std::cout << "2 - Student surname" << std::endl;
			std::cout << "3 - Student patronymic" << std::endl;
			std::cin >> choice2;
			switch (choice2) {
			case 1:
				std::cout << "Enter student id: " << std::endl;
				std::cin >> id;
				std::cout << "Enter new student name: " << std::endl;
				std::cin >> name;
				group.edit_student_name(id, name);
				break;
			case 2:
				std::cout << "Enter student id: " << std::endl;
				std::cin >> id;
				std::cout << "Enter new student surname: " << std::endl;
				std::cin >> surname;
				group.edit_student_surname(id, surname);
				break;
			case 3:
				std::cout << "Enter student id: " << std::endl;
				std::cin >> id;
				std::cout << "Enter new student patronymic: " << std::endl;
				std::cin >> patronymic;
				group.edit_student_patronymic(id, patronymic);
				break;
			}
			break;
		case 6:
			try {
				std::cout << group.getAverageMark();
			}
			catch (ZeroDimensionalityException& e) {
				e.what();
			}
			break;
		case 7:
			std::cout << "Enter subject: ";
			std::cin >> subject;
			try {
				std::cout << group.getAverageMarkBySubject(subject);
			}
			catch (ZeroDimensionalityException& e) {
				e.what();
			}
			break;
		case 8:
			group.printExcellent();
			break;
		case 9:
			group.printDoubler();
			break;
		case 10:
			group.printSimple();
			break;
		case 11:
		{
			std::string fileName;
			std::cout << "Please enter file name: ";
			std::cin >> fileName;
			std::thread t(writeInToFile, std::ref(group), std::ref(fileName));
			t.join();
			break;
		}
		case 12:
		{
			std::string fileName;
			std::cout << "Please enter file name: ";
			std::cin >> fileName;
			std::thread t(readFromFile, std::ref(group), std::ref(fileName));
			t.join();
			break;
		}
		}
	}
}
