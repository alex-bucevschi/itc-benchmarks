/*
Result: App will NOT crash. The new operator returns the same offset multiple times !!!
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

int global_mem[100];
int current_offset = 0;

class Test
{
    int x;
public:
    Test(int value): x(value) { }
    void* operator new(size_t size) {  
        void * result = &global_mem[current_offset];
        current_offset = (current_offset + 1) % 100;
        return result;
    }
    int GetX() { return x; }
};
void AllocatorTest_005()
{
    for (int tr = 0; tr < 20000; tr++)
    {
        Test * t = new Test(tr); /*Tool should detect this line as error*/ /*ERROR: Improper new() handling*/
        std::cout << t->GetX() << " ";
    }
}
