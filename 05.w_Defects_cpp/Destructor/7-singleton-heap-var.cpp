/*
Result: App will crashes. First delete for inst1 will delete the singleton. Then the second delete will fail as the pointer Singleton::instance is invalid
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Singleton
{
    char * pointer;
    Singleton() { pointer = new char[10]; }
    static Singleton * instance;
public:    
    ~Singleton() { delete pointer; }
    static Singleton*  CreateInstance()
    {
        if (instance == nullptr)
            instance = new Singleton();
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;

void DestructorTest_0073()
{
    Singleton * inst1 = Singleton::CreateInstance();
    Singleton * inst2 = Singleton::CreateInstance();
    delete inst1;
    delete inst2;/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}
