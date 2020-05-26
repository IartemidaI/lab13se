#include <iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;
int main() {

	cout << "Vitaliy Bernyk ki-31" << endl;
	HANDLE hFile;
	TCHAR str1[25] = _T("d:\\demo_file.txt");
	PTCHAR TextString = str1;
	hFile = CreateFile(TextString, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		cerr << "Creating file failed." << endl << "The last error code: " << GetLastError() << endl;
		cout << "Press any key to finish.";
		return 0;
	}
	DWORD FSize = GetFileSize(TextString, NULL) / 2;
	LPDWORD dwFileSize = &FSize;
	for (int i = 0; i < 10; i++) {
		if (!WriteFile(hFile, &i, sizeof(i), dwFileSize, (LPOVERLAPPED)NULL)) {
			cerr << "Writing file failed." << endl << "The last error code: " << GetLastError() << endl;
			CloseHandle(hFile);
			cout << "Press any key to finish.";
			return 0;
		}
		if (i == 5) {
			if (!FlushFileBuffers(hFile)) {
				cerr << "Flush file buffers failed." << "The last error code: " << GetLastError() << endl;
				CloseHandle(hFile);
				cout << "Press any key to finish.";
				return 0;
			}
			cout << "a half of the file is written." << endl << "Press any key to continue." << endl;
			cin.get();
		}
	}
	CloseHandle(hFile);
	cout << "The file is created and written." << endl;
	return 0;
}
