#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

class MemoryHacks
{
public:
	MemoryHacks();
	int getGold();
private:
	DWORD pid;
	HANDLE pHandle;
	HWND hwnd;
};

