/*
Result: App should crashes. fnc capture "t" as a value (as not copy-ctor is provided, the Test::pointer is copied as it is in the lamba class).  As a result, when fnc destructor is called, the copy of "t" is also deleted, thus the pointe "test::pointer" will be invalid when the destructor of t is called.
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
    void Show() const { printf("%s\n", pointer); }
};

void LambdaTest_004()
{
    Test t("some text");
    auto fnc = [=]() { t.Show(); };
    fnc();        
    /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/    
}