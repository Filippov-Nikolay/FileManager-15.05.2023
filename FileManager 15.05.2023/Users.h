#pragma once
#include <iostream>

using namespace std;

class Users {
protected:
	// LogUs* logus;
	string firstName; // ���
	string lastName; // �������
	string login; // �����
	string password; // ������

	bool firstEntry; // ������ ����
	bool access; // ������
public:
	void Input();
	void Print() const;


	// ���������
	// �������
	string GetFirstName() const;
	string GetLastName() const;
	string GetLogin() const;
	string GetPassword() const;
	
	bool GetFirstEntry() const;
	bool GetAccess() const;
};