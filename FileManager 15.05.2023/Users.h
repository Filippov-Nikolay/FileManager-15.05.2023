#pragma once
#include <iostream>
#include "LogUs.h"

using namespace std;

class Users {
protected:
	LogUs* logUs;
	string firstName; // Имя
	string lastName; // Фамилия
	string login; // Логин
	string password; // Пароль

	bool firstEntry; // Первый вход
	bool access; // Доступ
public:
	void Input();
	void Print() const;


	// Аксессоры
	// Геттеры
	string GetFirstName() const;
	string GetLastName() const;
	string GetLogin() const;
	string GetPassword() const;
	
	bool GetFirstEntry() const;
	bool GetAccess() const;
};