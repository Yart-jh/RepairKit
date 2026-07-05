#include "log.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

std::time_t g_currentTime;

void Create_Logfile() {

if (!fs::exists("repairtool_log.txt")) {
fs::path filepath("repairtool_log.txt");
std::ofstream file(filepath, std::ios::app);
std::cout << "repairtool_log.txt created succesfully!" << std::endl;
}

}

std::ofstream OpenLogfile() {

fs::path filepath("repairtool_log.txt");
std::ofstream file(filepath, std::ios::app);

return file;
}

void GetTime() {

auto now = std::chrono::system_clock::now();
g_currentTime = std::chrono::system_clock::to_time_t(now);

}

fs::path sysinfo_getpath() {

fs::path filepath("RK_sysinfo_log.txt");


return filepath;
}