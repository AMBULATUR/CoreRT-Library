#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>

#define PathToDLL "D:\\NativeLibrary.dll"
int callSumFunc(int a, int b);

int main()
{
    HINSTANCE handle = LoadLibrary(PathToDLL);

    if (handle == NULL) {
        printf("DLL Not Found || Check Character Set == MultiByte || Check x64 Native Tools");
    }
    else {
        printf("Success Load\n");
    }
    int res = callSumFunc(1, 5);
    printf("Result = %d",res);

    

    getch();

}

int callSumFunc(int firstInt, int secondInt)
{
    HINSTANCE handle = LoadLibrary(PathToDLL);
    typedef int (*myFunc)(int a, int b);
    myFunc MyImport = (myFunc)GetProcAddress(handle, "add");
    int result = MyImport(firstInt, secondInt);

    return result;
}
