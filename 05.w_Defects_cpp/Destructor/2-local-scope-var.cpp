/*
Result: App will crashes. Test::pointer is deleted twice (first time manually, second time by a destructor)
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Test
{
public:
    char * pointer;
    Test() { pointer = new char[10]; }
    ~Test() { delete pointer; }
};
void DestructorTest_0021()
{    
    for (int tr = 0; tr < 100000; tr++)
    {
        if (tr > 5000)
        {
            Test *t = new Test();
            delete t->pointer;
            delete t;
        }
    }
    /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}
