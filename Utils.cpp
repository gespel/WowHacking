#include "Utils.h"


std::string Utils::currentDateTime() {
    std::string out = "";
    std::stringstream ss;
    SYSTEMTIME st, lt;

    GetSystemTime(&st);
    ss << st.wHour << ":" << st.wMinute << ":" << st.wSecond << ":" << st.wMilliseconds;

    ss >> out;

    return out;
}

void Utils::log(std::string msg) {
    std::cout << "[STENS_WOWHACK_LOG][" << currentDateTime() << "][INFO] " << msg << std::endl;
}