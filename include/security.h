#pragma once

extern bool g_admin;

bool cmd_confirm();
bool IsAdmin();
void InitSecurity();
bool IsAllowed(int choice);
