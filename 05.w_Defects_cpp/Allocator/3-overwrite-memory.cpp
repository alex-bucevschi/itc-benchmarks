/*
Result: App will NOT crash. The new operator does not allocate the memory in the right order (instead of summing up 4 bytes (int) it just adds 3 bytes). As a result, every new allocation will overwrite the previous one.
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

unsigned char global_mem[sizeof(int)*100];
int current_offset = 0;

class Test
{
    int x;
public:
    Test(int value): x(value) { }
    void* operator new(size_t size) {  
        void * result = &global_mem[current_offset];
        current_offset += sizeof(Test) - 1;
        return result;
    }
    int GetX() { return x; }
};

void AllocatorTest_003()
{
    Test * t1 = new Test(123456789);
    Test * t2 = new Test(987654321);/*Tool should detect this line as error*/ /*ERROR: invalid order memory allocation*/
    std::cout << t1->GetX() << " " << t2->GetX() << std::endl;
}
