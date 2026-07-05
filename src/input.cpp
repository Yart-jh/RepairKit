#include "input.h"
#include <iostream>
#include "commands.h"
#include "security.h"
#include "command_rgstry.h"
#include <map>
#include "display.h"
#include <string>

    extern std::map<int, Command> commandRegistry;

//Function that sets options to different positions on the command registry.
void Initcmds() {

    commandRegistry[1] = {"SFC Scan", "sfc", true, SFCScan};
    commandRegistry[2] = {"DISM Restore", "dism", true, DISMRestore};
    commandRegistry[3] = {"CHKDSK", "chkdsk", true, CHKDSK};
    commandRegistry[4] = {"Flush DNS", "flushdns", false, FlushDNS};
    commandRegistry[5] = {"Renew IP", "renewip", false, RenewIP};
    commandRegistry[6] = {"Reset Winsock", "resetwinsock", true, ResetWinsock};
    commandRegistry[7] = {"Reset Network Stack", "resetnetworkstack", true, ResetNetworkStack};
    commandRegistry[8] = {"Boot Repair", "bootrepair", true, BootRepair};
    commandRegistry[9] = {"Windows Report", "windowsreport", false, WindowsReport};
    commandRegistry[10] = {"Power & Thermal Check", "powerthermal_check", false, Powerthermal_check};

    commandRegistry[11] = {"Driver Health Status", "driver_status", false, Drive_HealthCheck};
    commandRegistry[12] = {"System Information", "sysinfo", false, SystemInfo};
    commandRegistry[13] = {"Event Viewer", "eventvwr", false, EventVWR};
    commandRegistry[14] = {"Driver Query", "driverquery", false, Driver_query};
    commandRegistry[15] = {"Reliability Monitor", "reliability_mon", false, Reliability_mon};
    commandRegistry[16] = {"Network Information", "networkinfo", false, Network_info};
    commandRegistry[17] = {"Ping Test", "pingtest", false, PingTest};
    commandRegistry[18] = {"CMD Window", "newcmd", false, New_CMD};
    commandRegistry[19] = {"Task Manager", "taskmngr", false, TaskMNGR};
    commandRegistry[20] = {"Device Manager", "devicemngr", false, DeviceMNGR};
    commandRegistry[21] = {"Device Manager Scan", "devicemanagerscan", false, DeviceManagerScan};
    commandRegistry[22] = {"Memory Diagnostic", "memdiag", true, Mem_Diagnostic};
    commandRegistry[23] = {"DXDIAG", "dxdiag", false, DXDIAG};


}


std::string UserInput() {

    std::string choice;
    
while (true) {

    std::cout << "Please select which option you would like to proceed with[Numbers only]" << std::endl;

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

void ExecuteChoice(std::string choice) {

    extern bool g_admin;

for (char& c : choice) {

    c = std::tolower(c);
}//End for.

if (choice == "exit") {

    std::cout << "exiting.." << std::endl;
    return;
}


if (choice == "info") {

HelpBanner();
return;
}

for (const auto& [cmdID, cmd] : commandRegistry) {

if (cmd.cmdID == choice) {

Command command = cmd;

cmd.execute();
return;
}
}
    std::cout << "<ERROR> Invalid Input" << std::endl;
    return;
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