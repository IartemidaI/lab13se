#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	HANDLE hFile;
	long n;
	long p;
	DWORD dwBytesRead;
	int m;
	cout<< "Vitaliy Bernyk: " << endl;
	hFile = CreateFile(
		"C:\\demo_file.txt", GENERIC_READ || GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		cerr<< " create file failed" << endl<< " the last error code : " << GetLastError()<< endl;
		cout<< " press any key to finish";
		cin.get();
		return 0;
	}
	cout<< " input a number from 0 to 9:";
	cin>> n;
	if (!SetFilePointer(hFile, n * sizeof(int), &p, FILE_BEGIN)) 
	{
		cerr<< " Set file pointer failed." << endl<< " the last error code : " << GetLastError()<< endl;
		CloseHandle(hFile);
		cout<< " press any key to finish";
		cin.get();
	}
	cout<< " File pointer : " << p << endl;
	if (!ReadFile(hFile, &m, sizeof(m), &dwBytesRead,
		(LPOVERLAPPED)NULL)) {
		cerr<< " Read fale failed." << endl<< " the last error code : " << GetLastError()<< endl;
		CloseHandle(hFile);
		cout<< " press any key to finish";
		cin.get();
		return 0;
	}
	cout<< " The read number : " << m<< endl;
	CloseHandle(hFile);
	system("pause");
	return 0;
}
