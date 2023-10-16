#pragma once
#include <iostream>

#include "Users.h"
#include "Log.h"

using namespace std;

class FileManager {
	Log* log;
	Users* users;

	char* command;
	char* from;
	char* where;
public:
	FileManager();
	FileManager(Users*);
	~FileManager();

	void InputCommand();
	void CommandDefinition(string, string, string);

	void ShowDiskContents() const; // Показать содержимое диска
	void CreateAFolder() const; // Создать папку
	void CreateFile() const; // Создать файл
	void RenameFolder() const; // Переименовать папку
	void RenameFile(); // Переименовать файл
	void CopyFolder(); // Копировать папку
	void CopyFile(); //  Копировать файл
	void CalculateSizeFolder(); // Размер папки
	void CalculateSizeFile(); // Размер файла
	void SearchByMask(); // Поиск по маске
};