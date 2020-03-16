/*
Result: App will crashes. fnc is a lambda that caputer "this". When called fnc will destroy Test::pointer data member, resulting in a crash when the actual destructor is called.
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Test {
    const char *pointer;
public:
    Test() {
        pointer = new char[10];
    }
    ~Test() { delete pointer; }
    auto GetCleanUpLambda()
    {
        return [this]() { delete this->pointer; };
    }
};

void LambdaTest_001()
{
    Test t;
    auto fnc = t.GetCleanUpLambda();
    fnc();
    /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/    
}
