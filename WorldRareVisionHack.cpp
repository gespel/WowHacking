#include "WorldRareVisionHack.h"

WorldRareVisionHack::WorldRareVisionHack() {
   
    std::ostringstream initString;
    initString << "Width: " << width << " Height: " << height;

    Utils::log(initString.str());
    
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 24;
    bmi.bmiHeader.biCompression = BI_RGB;

    
    SelectObject(hdcMem, hbmScreen);

    for (int x = 200; x < 400; x++) {
        for (int y = 200; y < 400; y++) {
            SetPixel(hdcScreen, x, y, RGB(255, 255, 255));
        }
    }
}

void WorldRareVisionHack::startHack() {
    while (1) {
        BitBlt(hdcMem, 0, 0, width, height, hdcScreen, 0, 0, SRCCOPY);

        GetDIBits(hdcMem, hbmScreen, 0, height, pPixels, &bmi, DIB_RGB_COLORS);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int index = (y * width + x) * 3;
                BYTE blue = pPixels[index];     // Blau
                BYTE green = pPixels[index + 1];  // Grün
                BYTE red = pPixels[index + 2];    // Rot

                if (checkIfInRange((int)red, (int)green, (int)blue, 119, 88, 130, 20)) {
                    //ostringstream s_t;

                    //s_t << "X: " << x << " Y: " << y;
                    SetPixel(hdcScreen, x, y + 120, RGB(255, 255, 255));
                    //log("Found \"aufgewuehlte Erde\" at " + s_t.str());
                }
            }
        }
    }


    DeleteObject(hbmScreen);
    DeleteDC(hdcMem);
    ReleaseDC(NULL, hdcScreen);
    delete[] pPixels;
}

bool WorldRareVisionHack::checkIfInRange(int r, int g, int b, int r_t, int g_t, int b_t, int range) {
    if (abs(r - r_t) <= range && abs(g - g_t) <= range && abs(b - b_t) <= range) {
        return true;
    }
    return false;
}