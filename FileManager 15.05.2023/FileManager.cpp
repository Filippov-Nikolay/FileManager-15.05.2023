#include "FileManager.h"

#include <direct.h>
#include <sstream>

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

    clfm - close file manager

    cin >> command >> from >> where;

    ПЕРЕСМОТРЕТЬ ЦИКЛ В LOGUS
*/

FileManager::FileManager() { command = from = where = nullptr; }

FileManager::FileManager(Users* u) { users = u; }

FileManager::~FileManager() {
    delete command;
    delete from;
    delete where;
}

void FileManager::InputCommand() {
    string userInput = "";
    string commandUser = "";
    string fromUser = "";
    string whereUser = "";

    do {
        cout << "> ";
        getline(std::cin, userInput);

        istringstream iss(userInput);
        iss >> commandUser >> fromUser >> whereUser;

        CommandDefinition(commandUser, fromUser, whereUser);
    } while (commandUser != "clfm");
    
    cout << "До свидания!" << endl;
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
        from[lenghtFrom - 1] = '\0';

        CreateAFolder();
    }
    else if (commandUser == "rndr") {
        int lenghtFrom = (fromUser.length()) + 1;
        int tempIndex = 0;
        int index = 0;

        string temp;

        from = new char[lenghtFrom];
        strcpy_s(from, lenghtFrom, fromUser.c_str());
        from[lenghtFrom - 1] = '\0';


        for (int i = 0; i < lenghtFrom; i++) {
            if (fromUser[i] == '/')
                tempIndex++; // 2
        }

        for (int i = 0, j = 0; i < lenghtFrom; i++) {
            if (fromUser[i] != '/')
                temp += fromUser[i];
            else {
                temp += fromUser[i];
                index++;
            }

            if (index == tempIndex)
                break;
        }

        whereUser = temp += whereUser;

        int lenghtWhere = (whereUser.length()) + 1;
        
        where = new char[lenghtWhere];
        strcpy_s(where, lenghtWhere, whereUser.c_str());
        where[lenghtWhere - 1] = '\0';
        
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
}

void FileManager::CreateFile() {
    ofstream out(from);

    if (out.is_open()) {
        out << where;

        out.close();
    }
    else
        cout << "Не удалось открыть файл!" << endl;
}

void FileManager::RenameFolder() {
    if (rename(from, where) == 0)
        cout << "Директория переименована!" << endl;
    else
        cout << "Ошибка переименования директории!" << endl;
}

void FileManager::RenameFile() {
}

void FileManager::CopyFolder() {
}

void FileManager::CopyFile() {
    ofstream out;
    out.open(from, ios::out | ios::trunc);

    ifstream in;
    in.open(where, ios::in);

    if (in) {
        do {
            char character;

            in.get(character);

            out.put(character);
        } while (in);
        
        out.close();
        in.close();
    } 
    else 
        cout << "Не удалось открыть файл!" << endl;
}

void FileManager::CalculateSizeFolder() {
    
}

void FileManager::CalculateSizeFile() {
    ifstream in(from, ios::binary | ios::in);

    if (in) {
        in.seekg(0, ios::end);

        cout << "Размер файла: " << in.tellg() / 1024 << " КБ" << endl;

        in.close();
    } 
    else
        cout << "Не удалось открыть файл!" << endl;
}

void FileManager::SearchByMask() {
}
