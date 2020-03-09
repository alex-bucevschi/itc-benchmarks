/*result: App will NOT crash. Both "t1" and "t2" are allocated into the same memory due to the overwrite of the new operator
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include <iostream>

int global_mem;

class Test
{
    int value;
public:
    void* operator new(size_t size) { return &global_mem; }
};
int test_001()
{
    Test * t1 = new Test();
    delete t1;
    Test * t2 = new Test();/*Tool should not detect this line as error*/ /*NO ERROR: Improper new handling*/

    return 0;
}
