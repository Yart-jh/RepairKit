#pragma once
#include <string>
#include <functional>


struct Command {

std::string name;
bool requiresAdmin;
std::function<void()> execute;
};