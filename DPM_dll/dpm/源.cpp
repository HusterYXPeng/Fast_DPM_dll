#include <iostream>  
#include<Windows.h>  
using namespace std;

//所调用dll文件的存放路径  
const char* DllName = "FastDPM-2014-May.dll";
//获取dll句柄  
HMODULE dllCreat = LoadLibraryA(DllName);
//类型声明  
typedef int(*DPMDLL)(string, string, string);

//获取函数地址  
DPMDLL DpmDll = DPMDLL(GetProcAddress(dllCreat, "DpmDll"));

int main()
{
	cout << "--" << endl;
	DpmDll("img","model_inriaperson.txt", "result");
	system("pause");
	return 0;
}