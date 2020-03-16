/*
Result: App crashes. When the destructor is called, Test::pointer is invalid (not set)
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic 
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Test
{
    char * pointer;
public:
    Test() { }
    ~Test() { delete pointer; }
};
void DestructorTest_001()
{
    Test t;
    /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}
