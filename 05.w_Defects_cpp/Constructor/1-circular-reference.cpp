/*
Result: Compiles but produces a stack overflow from delegating constructors in a circular way
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Test
{
public:
    Test(int value): Test() { }
    Test(): Test(0) { }    
};
void ConstructorTest_001()
{    
    Test t;/*Tool should detect this line as error*/ /*ERROR: circular reference*/
}
