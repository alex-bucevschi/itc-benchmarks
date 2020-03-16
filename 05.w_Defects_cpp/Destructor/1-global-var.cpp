/*
Result: App will NOT crashes. As the Test variable is global, Test::pointer is already set to nullptr thus calling the delete pointer will not fail
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
Test t;
void DestructorTest_0013()
{
}
