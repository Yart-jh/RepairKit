#include "input.h"
#include <iostream>
#include "commands.h"
#include "security.h"
#include "command_rgstry.h"
#include <map>
#include "display.h"
#include <string>

std::string UserInput() {

    std::string choice;
    
while (true) {

    std::cout << "Please input which option you would like to proceed with" << std::endl;

std::cin >> choice;


bool valid = IsAllowed(choice);

if (valid) {
    return choice;
}
else {

continue;
}

continue;
}
}

std::string ExecuteChoice(std::string& choice) {

    extern bool g_admin;

for (char& c : choice) {

    c = std::tolower(c);
}//End for.

if (choice == "exit") {

    std::cout << "exiting.." << std::endl;
    return "";
}


if (choice == "info") {

if (g_admin) HelpBanner();
else HelpBanner_noadmin();

return "";
}

for (const auto& [cmdID, cmd] : commandRegistry) {

if (cmd.cmdID == choice) {

Command command = cmd;

cmd.execute();
return choice;
}
}
    std::cout << "<ERROR> Invalid Input" << std::endl;
    return "";
}

int PingTst_n() {

    int pingcount;
    
    std::cout << "How many pings would you like performed? (1-100)" << std::endl;

while (true) {

if (!(std::cin >> pingcount)) {

std::cout << "<ERROR> Invalid input." << std::endl;
std::cin.clear();
std::cin.ignore(1000, '\n');
continue;

}

if (pingcount < 1 || pingcount > 100) {

std::cout << "<ERROR> Ping count must be 1-100." << std::endl;
std::cin.clear();
std::cin.ignore(1000, '\n');
continue;

}

std::cout << "The program will ping " << pingcount << " times." << std::endl;
break;

}

return pingcount;
}

std::string PingTst_target() {

std::string pingTarget;

while (true) {
std::cout << "Would you like to ping a domain or an IP?" << std::endl;

std::cin >> pingTarget;

if (pingTarget == "domain" ) {
std::cout << "The program will ping google.com." << std::endl;
pingTarget = "google.com";
break;
}
else if (pingTarget == "ip") {
std::cout << "The program will ping the IP 8.8.8.8." << std::endl;
pingTarget = "8.8.8.8";
break;
}
else {

std::cout << "<ERROR> Invalid Input. Enter domain or ip as an input." << std::endl;
continue;

}
}

return pingTarget;
}

bool sysinfo_export() {

std::string choice;

while (true) {

    std::cout << "Would you like to export systeminfo to a .txt file?[y/n]" << std::endl;

    std::cin >> choice;

if (choice.length() > 1) {
    std::cout << "<ERROR> Invalid input. Only y/n is accepted." << std::endl;
    continue;
}

if (choice == "y" || choice == "Y") {

std::cout << "Systeminfo will be exported to a .txt file." << std::endl;
return true;

}
else if (choice == "n" || choice == "N") {

std::cout << "Systeminfo will not be exported." << std::endl;
return false;

}
else {

std::cout << "<ERROR> Invalid input. Only y/n is accepted." << std::endl;
continue;

}
}


}

