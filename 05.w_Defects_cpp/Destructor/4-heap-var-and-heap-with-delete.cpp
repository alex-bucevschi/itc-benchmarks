/*
Result: App will crashes. Test::pointer is multiple time. Since there is no copy-ctor, when the "Test t2=t" is run, the pointer is copied as it is, resulting in its destructio when the scope of t2 ends. Since this is done for "tr=0", "tr=2", "tr=4", ... , when "tr=2" and a new "t2" is created, the pointer is already invalid from the previous execution, resulting in a crash when the destructor is called.
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
void DestructorTest_0042()
{
    Test * t = new Test();
    for (int tr = 0; tr < 100; tr++)
    {
        if (tr % 2 == 0)
        {
            Test t2 = *t;
        }
    }
    delete t; /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}
