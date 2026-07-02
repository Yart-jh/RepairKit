#pragma once
#include <filesystem>
#include <fstream>
#include <chrono>
#include <iomanip>

namespace fs = std::filesystem;
extern std::time_t g_currentTime;

void Create_Logfile();
std::ofstream OpenLogfile();
void GetTime();