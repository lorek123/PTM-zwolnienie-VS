// hid_con.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hid.h"
#include <iostream>
using namespace std;

char buffer_out[64];
char buffer_in[64];

int _tmain(int argc, _TCHAR* argv[])
{
	for (int i=0;i<64;i++) {
		buffer_out[i]=0;	
		buffer_in[i]=0;
	}
	buffer_out[1]=1;// pomaranczowa dioda
	//buffer_out[1]=2;// zielona dioda
	//buffer_out[1]=4;// czerwona dioda
	//buffer_out[1]=8;// niebieska dioda

	FindTheHID();
	WriteOutputReport(buffer_out);
	while (1){
		ReadInputReport(buffer_in);
		DisplayInputReport(buffer_in);
		Sleep(1);
	}
	system("pause");

	return 0;
}

