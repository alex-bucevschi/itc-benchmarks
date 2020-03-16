/*
Result: App will crash. The new operator allocates memory outside the global_mem variable (tr is from 0 to 20000). As a result a memory access violation will be produced.
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
        void * result = &global_mem[current_offset];/*Tool should detect this line as error*/ /*ERROR: memory access violation*/ 
        current_offset++;
        return result;
    }
    int GetX() { return x; }
};
void AllocatorTest_004()
{
    for (int tr = 0; tr < 20000; tr++)
    {
        Test * t = new Test(tr);
        std::cout << t->GetX() << " ";
    }
}
