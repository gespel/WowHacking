#pragma once
#include <windows.h> 
#include <iostream>
#include <sstream>
#include "Utils.h"

class WorldRareVisionHack
{
public:
	WorldRareVisionHack();
	void startHack();
	
private:
	bool checkIfInRange(int r, int g, int b, int r_t, int g_t, int b_t, int range);

	HDC hdcScreen = GetDC(NULL);
	HDC hdcMem = CreateCompatibleDC(hdcScreen);

	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	BITMAPINFO bmi = { 0 };
	BYTE* pPixels = new BYTE[width * height * 3];
	
	HBITMAP hbmScreen = CreateCompatibleBitmap(hdcScreen, width, height);
};

