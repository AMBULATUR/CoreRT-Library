// DLLUser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <conio.h>
#define symLoad GetProcAddress GetProcAddress
#define PathToDLL "D:\\NativeLibrary.dll"
int callSumFunc(int a, int b);

int main()
{
    HINSTANCE handle = LoadLibrary(PathToDLL);
 
    if (handle == NULL) {
        std::cout << "cannot locate the .dll file" << std::endl;
    }
    else {
        std::cout << "it has been called" << std::endl;
       
    }
 
    int result = callSumFunc(5, 4);
    std::cout << "Result " << result;
    _getch();
   
}
int callSumFunc(int firstInt, int secondInt)
{
    HINSTANCE handle = LoadLibrary(PathToDLL);
    typedef int (*myFunc)(int a, int b);
    myFunc MyImport = (myFunc)GetProcAddress(handle, "add");
    int result = MyImport(firstInt, secondInt);

    return result;
}



