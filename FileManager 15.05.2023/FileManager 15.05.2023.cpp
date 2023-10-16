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
    lsdr - list dr
    szdr - size dir

    crf - create file
    rnf - rename file
    szf - size file

    cin >> command >> from >> where;

    login - уникальный, можно не писать ФИО

    Добавить директорию по умолчанию?
*/

int main() {
    setlocale(0, "");
    system("chcp 1251");
    SetConsoleCP(1251);

    Users* user = new User;
    // user->Input();

    FileManager test(user);
    test.InputCommand();

    return 0;
}