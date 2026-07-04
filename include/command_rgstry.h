#pragma once
#include <string>
#include <functional>
#include <map>

struct Command {

std::string name;
std::string cmdID;
bool requiresAdmin;
std::function<void()> execute;
};

extern std::map<int, Command> commandRegistry;
