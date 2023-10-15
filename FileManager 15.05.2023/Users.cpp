#include "Users.h"

Users::Users() {
	cout << "C" << endl;

	firstName = "";
	lastName = "";
	login = "";
	password = "";
	firstEntry = true;
	access = false;
	logUs->CreateLogUs();
}

void Users::Input() {
	// Вход или регистрация

	string tempLog;
	string tempPass;

	int userChoice;

	cout << "Вход - 1. Регистрация - 2\n> ";
	cin >> userChoice;

	if (userChoice == 1) {
		cout << "/* ВХОД */" << endl << endl;

		do {
			do {
				cout << "Введите логин: ";
				cin >> tempLog;

				if (!logUs->SearchLogin(tempLog)) {
					cout << "Такого логина нет!\nНапишите: reg - для регистрации" << endl << endl;
				}
			} while (!logUs->SearchLogin(tempLog));

			cout << "Введите пароль: ";
			cin >> tempPass;
			logUs->Encryption(tempPass);

			if (!logUs->Authorization(tempLog, tempPass))
				cout << "Введён неверный логин или пароль!" << endl << endl;
		} while (!logUs->Authorization(tempLog, tempPass));

		firstEntry = true;
		access = true;

		logUs->InputLogUsAuthorization(firstName, lastName, login, firstEntry, access);
		cout << endl;

		cout << "/* ДОБРО ПОЖАЛОВАТЬ */" << endl << endl;		
	}
	else if (userChoice == 2) {
		cout << "/* РЕГИСТРАЦИЯ */" << endl << endl;
		cout << "Введите имя: ";
		cin >> firstName;

		cout << "Введите фамилию: ";
		cin >> lastName;

		do {
			cout << "Создайте логин: ";
			cin >> login;
			if (logUs->SearchLogin(login))
				cout << "Такой логин есть! Придумайте другой" << endl << endl;
		} while (logUs->SearchLogin(login));

		cout << "Создайте пароль: ";
		cin >> password;
		logUs->Encryption(password);

		access = true;
		firstEntry = false;

		id++;

		logUs->InputLogUsRegistration(id, firstName, lastName, login, password, firstEntry, access);
	}
}

void Users::Print() const {
	cout << "Имя: " << firstName << endl;
	cout << "Фамилия: " << lastName << endl;
	cout << "Логин: " << login << endl;
	cout << "Пароль: " << password << endl;
}


string Users::GetFirstName() const { return firstName; }
string Users::GetLastName() const { return lastName; }
string Users::GetLogin() const { return login; }
string Users::GetPassword() const { return password; }

bool Users::GetFirstEntry() const { return firstEntry; }
bool Users::GetAccess() const { return access; }


void Users::SetFirstName(string fn) { firstName = fn; }
void Users::SetLastName(string ln) { lastName = ln; }
void Users::SetLogin(string lg) { login = lg; }
void Users::SetPassword(string ps) {
	logUs->Encryption(ps);
	password = ps;
}

void Users::SetFirstEntry(bool fe) { firstEntry = fe; }
void Users::SetAccess(bool a) { access = a; }