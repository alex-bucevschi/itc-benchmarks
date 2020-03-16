/*
Result: App will crashes with Division By 0 error. memcpy instruction will overwrite vfptr making the A* to be an actual B*
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class A
{
protected:
    int x;  
public:
    A(int value): x(value) { }
    virtual int GetX() { return x; }
};
class B : public A
{
public:
    B(int value): A(value) { }
    virtual int GetX() { return 0; }
};
void VirtualTest_001()
{
    A * a = new A(10);
    B * b = new B(10);
    A * c = new A(10);
    memcpy(c, b, sizeof(A));
    int res = a->GetX() / c->GetX(); /*Tool should detect this line as error*/ /*ERROR: Division by 0*/
    return 0;
}