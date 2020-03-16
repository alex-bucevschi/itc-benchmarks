/*
Result: App should crashes. "d" is an array but the delete[] operator is not used on it.
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

int global_id = 0;
class Date 
{
    int id;
public:
    Date() { global_id++; id = global_id; printf("ctor id:%d\n", id); }
    ~Date() { printf("dtor id:%d\n", id); }
};
void DestructorTest_008()
{ 
    Date *d = new Date[5];
    delete d;/*Tool should detect this line as error*/ /*ERROR:Improper delete() handling*/ 
    //err delete [d]
}