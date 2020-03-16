/*
Result: App will crashes. When first destructor is called, Singleton::instance::pointer is delete, thus when the second one is call the delete from the destructor will fail.
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

void DestructorTest_007()
{
    for (int tr = 0; tr < 10; tr++)
    {
        Singleton inst = *Singleton::CreateInstance();/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
        //err la tr = 1
    }
}
