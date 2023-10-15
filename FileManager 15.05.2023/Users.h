#pragma once
#include <iostream>
#include "LogUs.h"

using namespace std;

class Users {
protected:
	LogUs* logUs; // Лог
	string firstName; // Имя
	string lastName; // Фамилия
	string login; // Логин
	string password; // Пароль

	bool firstEntry = true; // Первый вход
	bool access; // Доступ

	unsigned int id;
public:
	Users();

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


	// Сеттеры
	void SetFirstName(string);
	void SetLastName(string);
	void SetLogin(string);
	void SetPassword(string);

	void SetFirstEntry(bool);
	void SetAccess(bool);
};