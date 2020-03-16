/*
Result: App will crash. Division by 0. Both "t1" and "t2" are allocated into the same memory due to the overwrite of the new operator. This means tha t1->value and t2->value will alway be equal.
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

int global_mem;

class Test
{
public:
    int value;
    void* operator new(size_t size) { return &global_mem; }
};
void AllocatorTest_002()
{
    Test * t1 = new Test();
    Test * t2 = new Test();
    t2->value = 10;
    t1->value = 20;
    std::cout << 100 / (t1->value - t2->value) << std::endl;/*Tool should detect this line as error*/ /*ERROR: Division by 0*/
}
