#include "Group.h"
#include "Exceptions.h"

void showMenu() {
	std::cout << "=====MENU=====" << std::endl;
	std::cout << "1 - Add student" << std::endl;
	std::cout << "2 - Show list of students" << std::endl;
	std::cout << "3 - Remove student" << std::endl;
	std::cout << "4 - Search student" << std::endl;
	std::cout << "5 - View the GPA in all subjects for the whole group" << std::endl;
	std::cout << "6 - View the GPA in a particular subject for the whole group" << std::endl;
	std::cout << "7 - View the list of excellent students" << std::endl;
	std::cout << "8 - View the list of debtors" << std::endl;
	std::cout << "0 - Exit" << std::endl;
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
			std::cout << "Enter student id: ";
			std::cin >> id;
			try {
				group.remove_student(id);
			}
			catch (StudentNotFoundException& e) {
				e.what();
			}
			break;
		case 4:
			std::cout << "Choose which parameter to search for a student by -->" << std::endl;
			std::cout << "1 - name" << std::endl;
			std::cout << "2 - surname" << std::endl;
			std::cout << "3 - patronymic" << std::endl;

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
			}
			break;
		case 5:
			try {
				std::cout << group.getAverageMark();
			}
			catch (ZeroDimensionalityException& e) {
				e.what();
			}
			break;
		case 6:
			std::cout << "Enter subject: ";
			std::cin >> subject;
			try {
				std::cout << group.getAverageMarkBySubject(subject);
			}
			catch (ZeroDimensionalityException& e) {
				e.what();
			}
			break;
		case 7:
			group.printExcellent();
			break;
		case 8:
			group.printDoubler();
			break;
		}
	}
}
