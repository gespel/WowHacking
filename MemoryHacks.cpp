#include "MemoryHacks.h"

MemoryHacks::MemoryHacks() {
    hwnd = FindWindowA(0, ("World of Warcraft"));
    GetWindowThreadProcessId(hwnd, &pid);
    pHandle = OpenProcess(PROCESS_VM_READ, FALSE, pid);    
}

int MemoryHacks::getGold() {
    int gold;
    ReadProcessMemory(pHandle, (LPVOID)(0x1F22BDA4D18), &gold, sizeof(gold), 0);
    return gold;
}