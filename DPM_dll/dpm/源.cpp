#include <iostream>  
#include<Windows.h>  
using namespace std;

//������dll�ļ��Ĵ��·��  
const char* DllName = "FastDPM-2014-May.dll";
//��ȡdll���  
HMODULE dllCreat = LoadLibraryA(DllName);
//��������  
typedef int(*DPMDLL)(string, string, string);

//��ȡ������ַ  
DPMDLL DpmDll = DPMDLL(GetProcAddress(dllCreat, "DpmDll"));

int main()
{
	cout << "--" << endl;
	DpmDll("img","model_inriaperson.txt", "result");
	system("pause");
	return 0;
}