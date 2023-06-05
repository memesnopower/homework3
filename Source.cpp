#include "Group.h"

void showMenu() {
	std::cout << "=====MENU=====" << std::endl;
	std::cout << "1 - Add student" << std::endl;
	std::cout << "2 - Show list of students" << std::endl;
	std::cout << "3 - Remove student" << std::endl;
	std::cout << "4 - View the GPA in all subjects for the whole group" << std::endl;
	std::cout << "5 - View the GPA in a particular subject for the whole group" << std::endl;
	std::cout << "6 - View the list of excellent students" << std::endl;
	std::cout << "7 - View the list of debtors" << std::endl;
	std::cout << "0 - Exit" << std::endl;
}

int main() {
	Group group("IU8-22");
	
	bool flag = false;
	Student temp;
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
			/*std::cout << "Enter student name: ";
			std::string name;
			std::cin >> name;
			group.remove_student(name);
			break;*/
		case 6:
			group.printExcellent();
			break;
		case 7:
			group.printDoubler();
			break;
		}

		
	}
}
