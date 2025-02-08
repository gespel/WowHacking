#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

class MemoryHacks
{
public:
	MemoryHacks();
private:
	DWORD pid;
	HANDLE pHandle;
};

