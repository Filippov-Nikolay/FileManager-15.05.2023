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
	// ���� ��� �����������

	string tempLog;
	string tempPass;

	int userChoice;

	cout << "���� - 1. ����������� - 2\n> ";
	cin >> userChoice;

	if (userChoice == 1) {
		cout << "/* ���� */" << endl << endl;

		do {
			do {
				cout << "������� �����: ";
				cin >> tempLog;

				if (!logUs->SearchLogin(tempLog)) {
					cout << "������ ������ ���!\n��������: reg - ��� �����������" << endl << endl;
				}
			} while (!logUs->SearchLogin(tempLog));

			cout << "������� ������: ";
			cin >> tempPass;
			logUs->Encryption(tempPass);

			if (!logUs->Authorization(tempLog, tempPass))
				cout << "����� �������� ����� ��� ������!" << endl << endl;
		} while (!logUs->Authorization(tempLog, tempPass));

		firstEntry = true;
		access = true;

		logUs->InputLogUsAuthorization(firstName, lastName, login, firstEntry, access);
		cout << endl;

		cout << "/* ����� ���������� */" << endl << endl;		
	}
	else if (userChoice == 2) {
		cout << "/* ����������� */" << endl << endl;
		cout << "������� ���: ";
		cin >> firstName;

		cout << "������� �������: ";
		cin >> lastName;

		do {
			cout << "�������� �����: ";
			cin >> login;
			if (logUs->SearchLogin(login))
				cout << "����� ����� ����! ���������� ������" << endl << endl;
		} while (logUs->SearchLogin(login));

		cout << "�������� ������: ";
		cin >> password;
		logUs->Encryption(password);

		access = true;
		firstEntry = false;

		id++;

		logUs->InputLogUsRegistration(id, firstName, lastName, login, password, firstEntry, access);
	}
}

void Users::Print() const {
	cout << "���: " << firstName << endl;
	cout << "�������: " << lastName << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
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