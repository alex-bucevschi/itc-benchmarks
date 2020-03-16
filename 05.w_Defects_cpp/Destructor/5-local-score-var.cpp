/*
Result: App will crashes. CreateInstance return a reference to a local object (dangling reference). That local object is destroy when exit function CreateInstace resulting in copying an invalid pointer to object T
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Test
{
    char * pointer;
public:
    Test() { pointer = new char[10]; }
    ~Test() { delete pointer; }
};
Test & CreateInstance()
{
    Test tempObject;
    return tempObject;
}

void DestructorTest_0051()
{
    for (int tr = 0; tr < 100; tr++)
    {
        if (tr == 50)
        {
            Test t = CreateInstance();/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
        }
    }
}
