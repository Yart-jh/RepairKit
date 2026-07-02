#include "input.h"
#include <iostream>
#include "commands.h"
#include "security.h"
#include "command_rgstry.h"
#include <map>
#include "display.h"

    extern std::map<int, Command> commandRegistry;

//Function that sets options to different positions on the command registry.
void Initcmds() {

    commandRegistry[1] = {"SFC Scan", true, SFCScan};
    commandRegistry[2] = {"DISM Restore", true, DISMRestore};
    commandRegistry[3] = {"CHKDSK", true, CHKDSK};
    commandRegistry[4] = {"Flush DNS", false, FlushDNS};
    commandRegistry[5] = {"Renew IP", false, RenewIP};
    commandRegistry[6] = {"Reset Winsock", true, ResetWinsock};
    commandRegistry[7] = {"Reset Network Stack", true, ResetNetworkStack};
    commandRegistry[8] = {"Device Manager Scan", false, DeviceManagerScan};
    commandRegistry[9] = {"Memory Diagnostic", true, Mem_Diagnostic};
    commandRegistry[10] = {"DXDIAG", false, DXDIAG};
    commandRegistry[11] = {"Driver Health Status", false, Drive_HealthCheck};
    commandRegistry[12] = {"System Information", false, SystemInfo};
    commandRegistry[13] = {"Event Viewer", false, EventVWR};
    commandRegistry[14] = {"Driver Query", false, Driver_query};
    commandRegistry[15] = {"Reliability Monitor", false, Reliability_mon};
    commandRegistry[16] = {"Network Information", false, Network_info};
    commandRegistry[17] = {"Ping Test", false, PingTest};
    commandRegistry[18] = {"CMD Window", false, New_CMD};
    commandRegistry[19] = {"Task Manager", false, TaskMNGR};
    commandRegistry[20] = {"Device Manager", false, DeviceMNGR};
 
}

int UserInput() {

    int choice;
    
while (true) {

    std::cout << "Please select which option you would like to proceed with[Numbers only]" << std::endl;

if (!(std::cin >> choice)) {

    std::cout << "<ERROR> Invalid Input." << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    continue;
}


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

void ExecuteChoice(int choice) {

    extern bool g_admin;

if (choice == 0) {

    std::cout << "exiting.." << std::endl;
    return;
}
else if (choice == 69) {

HelpBanner();
return;
}


    auto it = commandRegistry.find(choice);

    Command& cmd = it->second;

    cmd.execute();
}