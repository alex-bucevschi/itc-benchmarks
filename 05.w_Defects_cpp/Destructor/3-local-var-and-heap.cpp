/*
Result: App will crashes. Test::pointer is deleted twice. Since there is no copy-ctor, when the "Test t2=t" is run, the pointer is copied as it is, resulting in its destriction when the scope of t2 ends. At the end of the execution, when "t" destructor is called, "t.pointer" is invalid.
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
void DestructorTest_003()
{
    Test t;
    for (int tr = 0; tr < 100; tr++)
    {
        if (tr == 50)
        {
            Test t2 = t;
        }
    }
    /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
    //err destructor t
}
