/*
Result: App will crashes. fnc is a lambda that caputer "this" but it is called after the class is destroyed.
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Test {
    char * pointer;
public:
    Test(const char * text) { 
        pointer = new char[strlen(text) + 1];
        memcpy(pointer, text, strlen(text) + 1);
    }
    ~Test() { delete pointer; pointer = nullptr; }
    auto GetPrintLambda()
    {
        return [this]() { std::cout << this->pointer << std::endl; }; //err
    }
};

void LambdaTest_002()
{
    Test *t = new Test("some text");
    auto fnc = t->GetPrintLambda();
    delete t;
    fnc();/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/   
}
