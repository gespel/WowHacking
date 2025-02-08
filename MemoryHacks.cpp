#include "MemoryHacks.h"

MemoryHacks::MemoryHacks() {
    int cHealth;
    HWND hWnd = FindWindowA(0, ("World of Warcraft"));

    GetWindowThreadProcessId(hWnd, &pid);
    pHandle = OpenProcess(PROCESS_VM_READ, FALSE, pid);

    while (true)
    {
        ReadProcessMemory(pHandle, (LPVOID)(0x1F22BDA4D18), &cHealth, sizeof(cHealth), 0);
        std::cout << cHealth << std::endl;
        Sleep(200);
    }
        
    
}