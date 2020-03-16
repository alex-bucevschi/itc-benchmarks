/*
Result: Compiles , prints 123 and 50. Date.y is a reference to a temporar object on a stack
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Date
{
public:
    const int & y;
    int x;
    Date() : x(123), y(x) {} /*Tool should not detect this line as error*/ /*NO ERROR: reference to a temporar object on a stack*/
    void Test() {
        int a[1000];
        for (int tr = 0; tr < 1000; tr++)
            a[tr] = 50;
    }
};
void ConstructorTest_005();
{
    Date d;
    std::cout << d.y << std::endl;
    d.Test();
    std::cout << d.y << std::endl;
}

