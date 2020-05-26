#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
	if (!DeleteFile("C: Wdemo_file.dat"))
	{
		cerr<<"Delete file failed. "<<endl
			<<"The last error code: "<< GetLastError() <<endl;
		cout <<"Press any key to finish. ";
		cin.get();
		return 0;
	}
	cout <<"The file is deleted. "<<endl;
	return 0;
}
