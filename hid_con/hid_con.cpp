// hid_con.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hid.h"
#include <iostream>
using namespace std;

char buffer_out[64];
char haselko[18];
int _tmain(int argc, _TCHAR* argv[])
{
	for (int i=0;i<18;i++) {
		buffer_out[i]=0;	
	}
	buffer_out[1]=1;// pomaranczowa dioda
	//buffer_out[1]=2;// zielona dioda
	//buffer_out[1]=4;// czerwona dioda
	//buffer_out[1]=8;// niebieska dioda
	printf("Aby zagrac melodyjke podaj haslo\n");
	scanf("%s", haselko);
	printf("Wysy³amy: %s", haselko);
	FindTheHID();
	WriteOutputReport(haselko);
	WriteOutputReport(buffer_out);

	return 0;
}

