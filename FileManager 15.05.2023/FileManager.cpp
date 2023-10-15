#include "FileManager.h"
#include <direct.h>

/*
    Добавить путь
    изменить путь
    сохранить путь
    првоерка тек. директории
    и тд
*/

/*
    1. Исправить запись в лог, при рег. или автор.
    2. Сделать шифрование паролей (Большие буквы и цифры)

    Создать как коммандая строка?

    crdr - create dir
    rndr - rename dir
    ltdr - list dr
    szdr - size dir

    crf - create file
    rnf - rename file
    szf - size file

    cin >> command >> from >> where;
*/

FileManager::FileManager() { command = from = where = nullptr; }

FileManager::FileManager(Users* u) {
    
    users = u;
}

void FileManager::CommandDefinition(string commandUser, string fromUser, string whereUser) {
    if (users->GetAccess()) {
        cout << "\t\t-----------------------" << endl;
        cout << "\t\t/*В доступе отказано!*/" << endl;
        cout << "\t\t-----------------------" << endl;
        return;
    }

    if (commandUser == "crdr") {
        int lenghtFrom = (fromUser.length()) + 1;

        from = new char[lenghtFrom];
        strcpy_s(from, lenghtFrom, fromUser.c_str());
        from[lenghtFrom] = '\0';

        CreateAFolder();
    }
    else if (commandUser == "rndr") {
        int lenghtFrom = (fromUser.length()) + 1;
        int lenghtWhere = (whereUser.length()) + 1;

        from = new char[lenghtFrom];
        strcpy_s(from, lenghtFrom, fromUser.c_str());
        from[lenghtFrom] = '\0';

        where = new char[lenghtWhere];
        strcpy_s(where, lenghtWhere, whereUser.c_str());
        where[lenghtWhere] = '\0';

        RenameFolder();
    }
}

void FileManager::ShowDiskContents() const {
    /*
    char cwd[256];
    if (_getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Текущая директория: %s\n", cwd);
    }
    else {
        perror("Ошибка при получении текущей директории");
    }
    */

    system("dir");
}

void FileManager::CreateAFolder() {
    if (_mkdir(from) == 0)
        cout << "Директория создана!" << endl;
    else
        cout << "Ошибка создания директории!" << endl;

    /*
    string folder;
    cout << "> ";
    cin >> folder;

    int lenght = (folder.length()) + 1;
    char* nameFolder = new char[lenght];
    strcpy_s(nameFolder, lenght, folder.c_str());
    nameFolder[lenght] = '\0';

    if(_mkdir(nameFolder) == 0)
        cout << "Директория создана!" << endl;
    else
        cout << "Ошибка создания директории!" << endl;
    */
}

void FileManager::CreateFile() {
}

void FileManager::RenameFolder() {
    if (rename(from, where) == 0)
        cout << "Директория переименована!" << endl;
    else
        cout << "Ошибка переименования директории!" << endl;

    /*
    string folder = "D:/ШАГ/2 курс/ООП/FileManager 15.05.2023/FileManager 15.05.2023/";
    string folderTemp;
    cout << "Введите папку которую хотите перименовать: ";
    cin >> folderTemp;

    folder += folderTemp;

    int lenght = (folder.length()) + 1;
    char* oldFolder = new char[lenght];
    strcpy_s(oldFolder, lenght, folder.c_str());

    cout << "Введите новое название: ";
    cin >> folderTemp;

    int l = (folderTemp.length()) + 1;
    char* newFolder = new char[l];
    strcpy_s(newFolder, l, folderTemp.c_str());

    if (rename(oldFolder, newFolder) == 0)
        cout << "Директория переименована!" << endl;
    else
        cout << "Ошибка переименования директории!" << endl;
    */
    // int rename(const char* old_filename, const char* new_filename);
}

void FileManager::RenameFile() {
}

void FileManager::CopyFolder() {
}

void FileManager::CopyFile() {
}

void FileManager::CalculateSizeFolder() {
}

void FileManager::CalculateSizeFile() {
}

void FileManager::SearchByMask() {
}
