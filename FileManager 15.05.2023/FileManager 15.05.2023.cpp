#include <iostream>
#include <Windows.h>

#include "User.h"

#include "LogUs.h"

using namespace std;

/*
    1. Исправить запись в лог, при рег. или автор.
    2. Сделать шифрование паролей
*/

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    
    
    Users* user = new User;
    user->Input();


    return 0;
}
