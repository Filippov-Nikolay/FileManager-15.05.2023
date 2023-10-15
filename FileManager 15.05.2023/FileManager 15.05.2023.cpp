#include <iostream>
#include <Windows.h>

#include "User.h"
#include "FileManager.h"

using namespace std;

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

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    
    string command;
    string from;
    string where;

    cout << "> ";
    cin >> command >> from >> where;

    cout << command << " " << from << " " << where << endl;

    
    Users* user = new User;
    // user->Input();

    FileManager test(user);
    test.CommandDefinition(command, from, where);

    /*
    test.ShowDiskContents();
    test.CreateAFolder();
    test.RenameFolder();
    */

    return 0;
}
