#define UNICODE
#ifdef UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
int main() 
{
	HANDLE hFile;
	TCHAR fName[11] = { _T("MyFile.txt") };
	PTCHAR FileName = fName;
	TCHAR str[17] = { _T("Vitaliy Bernyk: ") };
	PTCHAR TextString = str;
	DWORD iWrite, StringLength = lstrlen(TextString);
	_tprintf(_T("There are %ld symbols in text string '%s' \n"), StringLength, TextString);
	hFile = CreateFile(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | 0, NULL);
	iWrite = StringLength;
#ifdef UNICODE
	iWrite = 2 * StringLength;
#endif
	WriteFile(hFile, TextString, iWrite, &iWrite, NULL);
	printf("%d bytes are written to file\n", iWrite);
	CloseHandle(hFile);
	system("pause");
	return 0;
}
