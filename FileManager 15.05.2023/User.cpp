#include "User.h"

User::User() {
	id++;
}

User::User(LogUs* ls, string fn, string ln, string lg, string ps, bool fe, bool a) :
	Users(ls, fn, ln, lg, ps, fe, a) {
}

void User::Input() {
	// ���� ��� �����������

	string tempLog;
	string tempPass;

	int userChoice;

	do {
		cout << "���� - 1. ����������� - 2\n> ";
		cin >> userChoice;

		if (userChoice == 2 && logUs->GetCheckingId(id)) {
			cout << "�� ��������� ������������������ ��� ������������������ ��������!" << endl << endl;
		}
	} while (userChoice == 2 && logUs->GetCheckingId(id));
	

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


		// �������� �� ����� ������
		firstName = logUs->GetFirstName(tempLog, tempPass);
		lastName = logUs->GetLastName(tempLog, tempPass);
		login = logUs->GetLogin(tempLog, tempPass);
		password = logUs->GetPassword(tempLog, tempPass);

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

		logUs->InputLogUsRegistration(id, firstName, lastName, login, password, firstEntry, access);
	}
}

void User::Print() const {
	cout << "���: " << firstName << endl;
	cout << "�������: " << lastName << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
}


string User::GetFirstName() const { return firstName; }
string User::GetLastName() const { return lastName; }
string User::GetLogin() const { return login; }
string User::GetPassword() const { return password; }

int User::GetId() const { return id; }

bool User::GetFirstEntry() const { return firstEntry; }
bool User::GetAccess() const { return access; }


void User::SetFirstName(string fn) { firstName = fn; }
void User::SetLastName(string ln) { lastName = ln; }
void User::SetLogin(string lg) { login = lg; }
void User::SetPassword(string ps) {
	logUs->Encryption(ps);
	password = ps;
}

void User::SetFirstEntry(bool fe) { firstEntry = fe; }
void User::SetAccess(bool a) { access = a; }