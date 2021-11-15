#include <iostream>
using namespace std;
#define MAX 1000
#include <string>


// Menu function
void showMenu() {
	cout << "////////////////////////////////////////////////////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// Please Select an Instruction.          //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 1. Add a contact.                      //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 2. Show the contacts.                  //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 3. Delete a contact.                   //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 4. Find a contact.                     //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 5. Edit a contact's information.       //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 6. Show the instruction.               //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 7. Clear the contact list.             //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////// 0. Exit the contact management system. //////" << endl;
	cout << "//////                                        //////" << endl;
	cout << "////////////////////////////////////////////////////" << endl;
}

// Struct of a person;
struct Person {
	string name;

	int gender;

	int age;

	string phone;

};

// Struct of the contact list;
struct ContactList {

	struct Person information[MAX];

	int contactListSize;

};

// Add a contact;
void addPerson(struct ContactList * abs) {
	if (abs->contactListSize == MAX) {
		cout << "The maximum capacity of the contact list is exceeded." << endl;
		return;
	}
	else {
		// name
		string nameEntered;
		cout << "Please enter the name of the contact: " << endl;
		cin >> nameEntered;
		abs->information[abs->contactListSize].name = nameEntered;
		cout << "                                      " << endl;

		//gender
		int genderEntered;
		cout << "Please enter the gender of the contact: " << endl;
		cout << "1 --- Male." << endl;
		cout << "2 --- Female." << endl;
		while (true) {
			cin >> genderEntered;
			if (genderEntered == 1 || genderEntered == 2) {
				abs->information[abs->contactListSize].gender = genderEntered;
				break;
			}
			cout << "Invalid number entered. Please try again." << endl;
		}
		cout << "                                        " << endl;

		// age
		int ageEntered;
		cout << "Please enter the age of the contact: " << endl;
		cin >> ageEntered;
		abs->information[abs->contactListSize].age = ageEntered;
		cout << "                                     " << endl;


		// phone number
		string phoneEntered;
		cout << "Please enter the phone number of the contact: " << endl;
		cin >> phoneEntered;
		abs->information[abs->contactListSize].phone = phoneEntered;
		cout << "                                              " << endl;

		// Update the size of the contact list;
		abs->contactListSize++;
		cout << "You have successfully added a contact." << endl;
		cout << "                                      " << endl;
		system("pause");
		system("cls");
	}
}

// Show contacts;
void showPerson(struct ContactList * abs) {
	// Check if the contact list is empty, if so, prompt that it's an empty contact list;
	if (abs->contactListSize == 0) {
		cout << "It's an empty contact list." << endl;
		cout << "                           " << endl;
	}
	// If it's not an empty contact list, show the information of the contacts;
	else {
		for (int i = 0; i < abs->contactListSize; i++) {
			cout << "Name: " << abs->information[i].name << "\t";
			cout << "Gender: " << (abs->information[i].gender == 1 ? "Male" : "Female") << "\t";
			cout << "Age: " << abs->information[i].age << "\t";
			cout << "Phone: " << abs->information[i].phone << endl;
			cout << "                                    " << endl;
		}
	}
	system("pause");
	system("cls");
}

// Check if the entered contact exists;
int existence(struct ContactList * abs, string nameIn) {
	for (int i = 0; i < abs->contactListSize; i++) {
		// The contact's name is found, return the found index; 
		if (abs->information[i].name == nameIn) {
			return i;
		}
	}
	// If not found, return -1;
	return -1;
}

// Delete a contact;
void deletePerson(struct ContactList * abs) {
	cout << "Please enter the name of the contact that you want to delete: " << endl;
	string nameDelete;
	cin >> nameDelete;

	int result = existence(abs, nameDelete);
	// If result != -1, name is found; 
	if (result != -1) {
		nameDelete = abs->information[result].name;
		// Overlap the index i by i + 1;
		for (int i = result; i < abs->contactListSize; i++) {
			abs->information[i] = abs->information[i + 1];
		}
		abs->contactListSize--;
		cout << "                                " << endl;
		cout << "You have successfully deleted \"" << nameDelete << "\" in your contact list. " << endl;
	}
	// If result == -1, name is not found; 
	else {
		cout << "                                      " << endl;
		cout << "No such person is found in the system." << endl;
	}
	cout << "                                          " << endl;


	system("pause");
	system("cls");
}

// Find a contact;
void findPerson(struct ContactList * abs) {
	cout << "Please enter the name of the contact that you want to find: " << endl;
	string nameFind;
	cin >> nameFind;
	

	int result = existence(abs, nameFind);
	// If result != -1, name is found;
	if (result != -1) {
		cout << "                                       " << endl;
		cout << "Name: " << abs->information[result].name << "\t";
		cout << "Gender: " << (abs->information[result].gender == 1 ? "Male" : "Female") << "\t";
		cout << "Age: " << abs->information[result].age << "\t";
		cout << "Phone: " << abs->information[result].phone << endl;
	}
	// If result == -1, name is not found;
	else {
		cout << "                                      " << endl;
		cout << "No such person is found in the system." << endl;
	}
	cout << "                                          " << endl;


	system("pause");
	system("cls");
}

// Edit a contact's information
void editPerson(struct ContactList * abs) {
	cout << "Please enter the name of the contact that you want to edit his/her information: " << endl;
	string nameEdit;
	cin >> nameEdit;

	int result = existence(abs, nameEdit);
	// If the result != -1, name is found;
	if (result != -1) {
		// edit name
		string nameAfter;
		cout << "           " << endl;
		cout << "Edit name: " << endl;
		cin >> nameAfter;
		abs->information[result].name = nameAfter;
		cout << "           " << endl;

		// edit gender
		int genderAfter;
		cout << "Edit gender: " << endl;
		cout << "1 --- Male." << endl;
		cout << "2 --- Female." << endl;
		while (true) {
			cin >> genderAfter;
			if (genderAfter == 1 || genderAfter == 2) {
				abs->information[result].gender = genderAfter;
				break;
			}
			cout << "Invalid number entered. Please try again." << endl;
		}
		cout << "                                             " << endl;
		
		// edit age
		int ageAfter;
		cout << "Edit age: " << endl;
		cin >> ageAfter;
		abs->information[result].age = ageAfter;
		cout << "                     " << endl;

		// edit phone
		string phoneAfter;
		cout << "Edit phone: " << endl;
		cin >> phoneAfter;
		abs->information[result].phone = phoneAfter;
		cout << "                         " << endl;

		cout << "You have successfully eddited the contact's information. " << endl;
	}
	// If the result == -1, name is not found;
	else {
		cout << "                                      " << endl;
		cout << "No such person is found in the system." << endl;
	}
	cout << "                                          " << endl;

	system("pause");
	system("cls");
}

// Show the instruction
void showInstruction() {
	cout << "Please follow the instructions. " << endl;
	cout << "Note: please avoid adding those people with the same name, and please do not enter an non-integer type input," << endl;
	cout << "in order to prevent the program to crash. " << endl;
	cout << "                                " << endl;


	cout << "****** How to add? " << endl;
	cout << "1. Please enter the name in the form of \"First Name - Last Name\". " << endl;
	cout << "2. Please enter the gender in the form of 1 or 2, which indicates male or female, in ordered." << endl;
	cout << "3. Please enter the age in an integer number." << endl;
	cout << "4. Please enter the phone number consecutively, without any space." << endl;
	cout << "                                                                  " << endl;

	cout << "****** How to show the contact list? " << endl;
	cout << "Please enter number 2. " << endl;
	cout << "                                     " << endl;

	cout << "****** How to delete a contact?" << endl;
	cout << "Please enter the contact's name that you want to delete." << endl;
	cout << "                               " << endl;

	cout << "****** How to find a contact? " << endl;
	cout << "Please enter the contact's name that you want to find. " << endl;
	cout << "                              " << endl;

	cout << "****** How to edit a contact's information? " << endl;
	cout << "1. Please enter the name of the contact that you want to edit his/her information. " << endl;
	cout << "2. Please re-enter everything in the format mentioned in \"How to add?\" section." << endl;
	cout << "                                            " << endl;

	cout << "****** How to exit? " << endl;
	cout << "Please enter number 0." << endl;
	cout << "Note: after this executiom, all of the data you've stored will be lost." << endl;
	cout << "                    " << endl;

	cout << "****** How to clear all of the contacts? " << endl;
	cout << "Please enter number 7. " << endl;
	cout << "                                         " << endl;

	cout << "    " << endl;
	system("pause");
	system("cls");
}

// Clear the contact list;
void clearContactList(struct ContactList * abs) {
	abs->contactListSize = 0;
	cout << "The contact list is cleared." << endl;
	cout << "                            " << endl;

	system("pause");
	system("cls");
}



int main() {

	struct ContactList abs;	
	abs.contactListSize = 0;


	int select;

	while (true) {
		// Call menu function;
		showMenu();
		cout << "                               " << endl;
		cout << "Please enter a number (0 - 7): " << endl;
		cin >> select;
		cout << "                               " << endl;

		switch (select) {

		case 1:
			addPerson(&abs);
			break;

		case 2:
			showPerson(&abs);
			break;

		case 3:
			deletePerson(&abs);
			break;

		case 4:
			findPerson(&abs);
			break;

		case 5:
			editPerson(&abs);
			break;

		case 6:
			showInstruction();
			break;

		case 7:
			clearContactList(&abs);
			break;

		case 0:
			cout << "We're looking forward to your coming back." << endl;
			cout << "                                          " << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "Invalid instruction, please try again." << endl;
			cout << "                                      " << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
