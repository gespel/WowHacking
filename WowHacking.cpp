// WowHacking.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <windows.h> 
#include <iostream>
#include <sstream>

using namespace std;

const std::string currentDateTime() {
    std::string out = "";
    stringstream ss;
    SYSTEMTIME st, lt;

    GetSystemTime(&st);
    ss << st.wHour << ":" << st.wMinute << ":" << st.wSecond << ":" << st.wMilliseconds;

    ss >> out;
    
    return out;
}

void log(std::string msg) {
    std::cout << "[STENS_WOWHACK_LOG][" << currentDateTime() << "] Message: " << msg << std::endl;
}

bool checkIfInRange(int r, int g, int b, int r_t, int g_t, int b_t, int range) {
    if (abs(r - r_t) <= range && abs(g - g_t) <= range && abs(b - b_t) <= range) {
        return true;
    }
    return false;
}

int main()
{
    HDC hdcScreen = GetDC(NULL);  // Bildschirm-DC holen

    // Bildschirmgröße ermitteln
    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    ostringstream initString;
    initString << "Width: " << width << " Height: " << height;

    log(initString.str());
   
    // Bitmap-Informationen vorbereiten
    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;  // Negative Höhe für "top-down"-Reihenfolge
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 24;  // 24 Bit (RGB ohne Alpha)
    bmi.bmiHeader.biCompression = BI_RGB;

    // Speicher für die Pixel-Daten allokieren
    BYTE* pPixels = new BYTE[width * height * 3];

    // DC für Bitmap erstellen
    HDC hdcMem = CreateCompatibleDC(hdcScreen);
    HBITMAP hbmScreen = CreateCompatibleBitmap(hdcScreen, width, height);
    SelectObject(hdcMem, hbmScreen);

    for (int x = 200; x < 400; x++) {
        for (int y = 200; y < 400; y++) {
            SetPixel(hdcScreen, x, y, RGB(255, 255, 255));
        }
    }

    while (1) {
        
        // Bildschirminhalt in die Bitmap kopieren
        BitBlt(hdcMem, 0, 0, width, height, hdcScreen, 0, 0, SRCCOPY);

        // Pixelwerte auslesen
        GetDIBits(hdcMem, hbmScreen, 0, height, pPixels, &bmi, DIB_RGB_COLORS);

        // Pixel-Daten auswerten
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int index = (y * width + x) * 3;
                BYTE blue = pPixels[index];     // Blau
                BYTE green = pPixels[index + 1];  // Grün
                BYTE red = pPixels[index + 2];    // Rot

                //std::cout << "(" << (int)red << "," << (int)green << "," << (int)blue << ")\n";
                if (checkIfInRange((int)red, (int)green, (int)blue, 119, 88, 130, 20)) {
                    //ostringstream s_t;

                    //s_t << "X: " << x << " Y: " << y;
                    SetPixel(hdcScreen, x, y+120, RGB(255, 255, 255));
                    //log("Found \"aufgewuehlte Erde\" at " + s_t.str());
                }
            }
        }
        //std::cout << "Frame rendered!" << std::endl;
    }
    

    // Ressourcen freigeben
    DeleteObject(hbmScreen);
    DeleteDC(hdcMem);
    ReleaseDC(NULL, hdcScreen);
    delete[] pPixels;

    return 0;
}
