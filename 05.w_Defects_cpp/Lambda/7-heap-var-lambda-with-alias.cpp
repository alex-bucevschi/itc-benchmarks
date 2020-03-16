/*
Result: App should crashes. fnc capture "t" as a value (as not copy-ctor is provided, the Test::pointer is copied as it is in the lamba class).  When calling the fnc() another lambda is created that copies the "t" pointer and destroys it if the value passed as a parameter is multiple of 7. When the loop is called, the delete is called twice (once for 7 and once for 14). The second one will crash the app.
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"


class Test {
    char * pointer;
public:
    Test(const char * text) { 
        pointer = new char[strlen(text) + 1];
        memcpy(pointer, text, strlen(text) + 1);
    }
    ~Test() { delete pointer; }
};

void LambdaTest_0071()
{
    Test *t = new Test("some text");
    auto fnc = [=]() mutable { return [a = t](int x) mutable { if (x % 7 == 0) delete a; }; };
    for (int tr = 1; tr < 16; tr++)
    {
        fnc()(tr);/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/    
    }
}