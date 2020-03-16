/*
Result: Compiles but can crash. Since "y" is a reference to "x", and a copy constructor is missing, the following statement "Date d2 = *d;" will make d2.y a reference to d.x. As a result, when d is deleted and d2 calls SetX method, d2.y refers to an invalid memory
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Date
{
    int & y;
    int x;
public:
    Date(): x(0),y(x) { }
    void SetX(int value) { y = value; }
};
void ConstructorTest_006()
{
    Date *d = new Date();
    d->SetX(100);
    Date d2 = *d;
    delete d;
    d2.SetX(100);/*Tool should detect this line as error*/ /*ERROR: missing copy constructor*/
}

