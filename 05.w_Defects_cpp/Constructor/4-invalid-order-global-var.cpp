/*
Result: Compiles , however as "t" is global, la values for t.y, t.x and t.z are not undefined 
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Test
{
    int x, y, z;
public:
    Test(int value) : x(value), y(x*z), z(value+2) { } /*Tool should detect this line as error*/ /*ERROR: invalid order*/
};
Test t(5);
void ConstructorTest_0041() 
{    
}
