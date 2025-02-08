#pragma once
#include <windows.h> 
#include <iostream>
#include <sstream>

class Utils
{
public:
	static std::string currentDateTime();
	static void log(std::string msg);
};

