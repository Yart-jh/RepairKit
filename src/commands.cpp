#include "commands.h"
#include <string>
#include <iostream>
#include "security.h"
#include <windows.h>
#include "log.h"
#include "command_rgstry.h"
#include <string>
#include <vector>
#include "input.h"


//Core function that runs windows commands.
int RunCommand(const std::string& cmd, bool wait = true, DWORD creationFlags = 0) {

    std::ofstream file(OpenLogfile());
    

if (!file) {
std::cout << "<ERROR> Failed to open repairtooll_log.txt" << std::endl;
std::cout << "Process and other log info may be untracked." << std::endl;
}

    STARTUPINFOA si{};
    PROCESS_INFORMATION pi{};

    si.cb = sizeof(si);

//Converts std::string to C-style string(makes the string compatible with Windows API.)
    char commandLine[1024];
    strncpy_s(commandLine, cmd.c_str(), sizeof(commandLine));

//converts cmdline into a dynamic vector to remove character limit to commands.
    std::string cmdLine = cmd;
    cmdLine.push_back('\0');

//Starts a new Windows process.
    BOOL success = CreateProcessA(

    NULL,
    cmdLine.data(),
    NULL,
    NULL,
    FALSE,
    creationFlags,
    NULL,
    NULL,
    &si,
    &pi
);


file << "====================" << std::endl;
file << " " << std::endl;
file << "Action: " << "<WIP>" << std::endl;
file << " " << std::endl;
file << "Command: " << cmd << std::endl;
file << " " << std::endl;
//Checks if the process succesfully started.
if (!success) {

    file << "Status: Failed" << std::endl;
    file << " " << std::endl;
    file << "Time: " << std::put_time(std::localtime(&g_currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;
    file << "====================" << std::endl;
    std::cout << "<ERROR> Process failed to start." << std::endl;
    return -1;
}

//Makes the program Wait for process to finish if wait is true.
if (wait) {
    WaitForSingleObject(pi.hProcess, INFINITE);
}

//Collects and outputs the exit code when program closes.
    DWORD exitCode = 0;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    std::cout << "Process ended with exit code: " << exitCode << "." << std::endl;
    
    GetTime();
    
    file << "Status: Success" << std::endl;
    file << " " << std::endl;
    file << "Time: " << std::put_time(std::localtime(&g_currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;
    file << "====================" << std::endl;
    file << " " << std::endl;
    
//Closes handles anbd log file to prevent memory leaks.
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    file.close();

    return static_cast<int>(exitCode);
}


void SFCScan() {

    std::cout << "Executing SFC scan.." << std::endl;

    int result = RunCommand("sfc /scannow", true);

if (result == 0) std::cout << "SFC Completed!" << std::endl;
else std::cout << "SFC Encountered an issue. Please reopen program as administrator.." << std::endl;

}


void DISMRestore(){

    std::cout << "WARNING: This process can take a little while to complete." << std::endl;

    bool confirm = cmd_confirm();

if (confirm) {
std::cout << "Executing DISM Restore.." << std::endl;

    int result = RunCommand("DISM /Online /Cleanup-Image /RestoreHealth", true);

if (result == 0) std::cout << "DISM Restore Completed!" << std::endl;
else std::cout << "DISM Restore Encountered an issue. Please reopen program as administrator.." << std::endl;
}
else {

    return;

}
}

void CHKDSK() {

    std::cout << "NOTE: This command requires admin privileges." << std::endl;
    std::cout << "PC may require restart for CHKDSK to complete." << std::endl;
    std::cout << " " << std::endl;

    bool confirm = cmd_confirm();

if (confirm) {

    std::cout << "Executing CHKDSK.." << std::endl;

    int result = RunCommand("chkdsk C: /f /r", true);

if (result == 0) std::cout << "CHKDSK completed! Please restart your PC if prompted to finish." << std::endl;
else std::cout << "CHKDSK Encountered an issue. Reopen program as administrator." << std::endl;

}
else {

return;

}
}


void FlushDNS() {

    std::cout << "Clearing the DNS resolver cache.." << std::endl;

    int result = RunCommand("ipconfig /flushdns", true);

if (result == 0) std::cout << "DNS flush completed!" << std::endl;
else std::cout << "DNS flush encountered an issue." << std::endl;


}

void RenewIP() {

    std::cout << "Renewing IP.." << std::endl;

    int result = RunCommand("ipconfig /renew", true);

if (result == 0) std::cout << "IP renewal completed!" << std::endl;
else std::cout << "IP renewal encountered an issue.." << std::endl;


}

void ResetWinsock() {

    std::cout << "WARNING: This action may require a reboot after completion." << std::endl;

    bool confirm = cmd_confirm();

if (confirm) {
std::cout << "Resetting Winsock.." << std::endl;

    int result = RunCommand("netsh winsock reset", true);

if (result == 0) std::cout << "Winsock reset completed!" << std::endl;
else std::cout << "Winsock reset encountered an issue." << std::endl;
}
else {

return;

}

}

void ResetNetworkStack() {

    std::cout << "NOTE: This command requires admin privileges." << std::endl;
    std::cout << "PC will require restart for Network Stack Reset to complete." << std::endl;
    std::cout << " " << std::endl;

    bool confirm = cmd_confirm();

if (confirm) {

    std::cout << "Executing Network Stack Reset.." << std::endl;

    int result = RunCommand("netsh int ip reset", true);

if (result == 0) std::cout << "Network Stack Reset completed! Please restart your PC if prompted to finish." << std::endl;
else std::cout << "Network Stack Reset Encountered an issue. Reopen program as administrator." << std::endl;

}
else {

return;

}

}

void DeviceManagerScan() {

    std::cout << "Running Device Manager Scan.." << std::endl;

    int result = RunCommand("pnputil /enum-devices /problem", true);

if (result == 0) std::cout << "Device Manager scan completed!" << std::endl;
else std::cout << "Device Manager Scan encountered an issue. Please reopen program as administrator." << std::endl;


}

void Mem_Diagnostic() {

    std::cout << "Memory Diagnostic will schedule a memory test on next reboot." << std::endl;
    std::cout << " " << std::endl;

    bool confirm = cmd_confirm();

if (confirm) {

    std::cout << "Executing Memory Diagnostic.." << std::endl;

    int result = RunCommand("mdsched.exe", true);

if (result == 0) std::cout << "Memory Diagnostic Scheduled! Please restart your PC if prompted to finish." << std::endl;
else std::cout << "Memory Diagnostic Encountered an issue. Reopen program as administrator." << std::endl;

}
else {

return;

}

}

void DXDIAG() {

    std::cout << "Executing DXDIAG.." << std::endl;

    int result = RunCommand("dxdiag", true);

if (result == 0) std::cout << "DXDIAG completed!" << std::endl;
else std::cout << "DXDIAG encountered an issue." << std::endl;


}

void Drive_HealthCheck() {

    std::cout << "Collecting Drive Health Information.." << std::endl;

    int result = RunCommand("powershell -Command \"Get-PhysicalDisk | Format-Table FriendlyName, MediaType, HealthStatus, OperationalStatus\"", true);

if (result == 0) std::cout << "Drive Health Check Completed!" << std::endl;
else std::cout << "Drive Health Check encountered an issue. Please reopen the program as administrator" << std::endl;

}

void SystemInfo() {

    std::cout << "Gathering System Info.." << std::endl;

    int result = RunCommand("systeminfo", true);

if (result == 0) std::cout << "System Information completed!" << std::endl;
else std::cout << "System Information encountered an issue.." << std::endl; 

}

void EventVWR() {

    std::cout << "Running Event Viewer.." << std::endl;

    int result = RunCommand("mmc.exe eventvwr.msc", false);

if (result == 0) std::cout << "Event Viewer Completed." << std::endl;
else std::cout << "Event Viewer encountered an error. Reopen the program as administrator." << std::endl;

}

void Driver_query() {

    std::cout << "Collecting driver information.." << std::endl;

    int result = RunCommand("driverquery /v", true);

if (result == 0) std::cout << "Driver query completed!" << std::endl;
else std::cout << "Driver query encountered an issue." << std::endl;


}

void Reliability_mon() {

    std::cout << "Running Reliability Monitor.." << std::endl;

    int result = RunCommand("perfmon /rel", true);

if (result == 0) std::cout << "Reliability Monitor completed" << std::endl;
else std::cout << "Reliability Monitor encountered an issue." << std::endl;

}

void Network_info() {

    std::cout << "running Network Information.." << std::endl;

    int result = RunCommand("ipconfig /all", true);

if (result == 0) std::cout << "Network Information completed!" << std::endl;
else std::cout << "Network Information encountered an issue." << std::endl;

}

void PingTest() {

    std::cout << "Starting Ping Test." << std::endl;
    std::cout << "Program will ping 10 times and then will give netwrok statistics." << std::endl;

    int result = RunCommand("ping google.com -n 10", true);

if (result == 0) std::cout << "Ping test completed!" << std::endl;
else std::cout << "Ping test encountered and issue." << std::endl;

}
void TaskMNGR() {

    std::cout << "Opening Task Manager." << std::endl;

    int result = RunCommand("taskmgr.exe", false);

if (result == 0) std::cout << "Task Manager Opened!" << std::endl;
else std::cout << "Task Manager encountered an issue." << std::endl;

}

void DeviceMNGR() {

    std::cout << "Opening Device Manager." << std::endl;

    int result = RunCommand("mmc.exe devmgmt.msc", false);

if (result == 0) std::cout << "Device Manager Opened!" << std::endl;
else std::cout << "Device Manager encountered an issue." << std::endl;

}

void New_CMD() {

    std::cout << "Opening a new CMD window." << std::endl;

    int result = RunCommand("cmd.exe", false, CREATE_NEW_CONSOLE);

if (result == 0) std::cout << "New cmd window Opened!" << std::endl;
else std::cout << "cmd window encountered an issue." << std::endl;

}
//FINISH THESE FUNCTIONS!!!!!!!