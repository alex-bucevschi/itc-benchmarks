/*
Result: App will crashes with Division By 0 error. Post-fix operator has one parameter that is always 0 - thus deviding Integer::value with 0 will produce an error. From cplusplus "The int parameter is a dummy parameter used to differentiate between prefix and postfix versions of the operators. When the user-defined postfix operator is called, the value passed in that parameter is always zero, although it may be changed by calling the operator using function call notation"
Params: /permissive- /GS- /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTCu /arch:IA32 /Gd /Oy- /MDd /FC /Fa"Debug\" /nologo /Fo"Debug\" /Fp"Debug\TestCpp.pch" /diagnostics:classic
cl.exe: 19.16.27030.1
*/
#include "HeaderFile.hpp"

class Integer
{
    int value;
public:
    Integer(int val) : value(val) {}
    bool operator++ (int val) { return value / val; }
};
Integer n1(20);
void OperatorsTest_0012()
{
    n1++;/*Tool should detect this line as error*/ /*ERROR: Division by 0*/
}