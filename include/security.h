#pragma once
#include <string>

extern bool g_admin;

bool cmd_confirm();
bool IsAdmin();
void InitSecurity();
bool IsAllowed(std::string choice);
