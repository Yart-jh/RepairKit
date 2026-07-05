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

//Converts std::string into a std::wstring for use in CreateProcessW.
std::wstring ToWideString(const std::string& str) {
if (str.empty()) return {};

//Sets the size of the wstring to the same size of the std::string.
int size_needed = MultiByteToWideChar(CP_UTF8,
    0,
    str.c_str(),
    (int)str.size(),
    NULL,
    0);
if (size_needed == 0) return {};

//Converts the string into this sized wstring.
std::wstring wstr(size_needed, 0);
MultiByteToWideChar(CP_UTF8,
    0,
    str.c_str(),
    (int)str.size(),
    &wstr[0],
    size_needed);

    return wstr;

}


//Core function that runs windows commands.
int RunCommand(const std::string& cmd, bool wait = true, DWORD creationFlags = 0) {

    std::ofstream file(OpenLogfile());
    

if (!file) {
std::cout << "<ERROR> Failed to open repairtooll_log.txt" << std::endl;
std::cout << "Process and other log info may be untracked." << std::endl;
}

    STARTUPINFOW si{};
    PROCESS_INFORMATION pi{};

    si.cb = sizeof(si);

//converts the wstring into a dynamic vector that the windows API can use to remove character limit to commands.
std::wstring wcmd = ToWideString(cmd);
std::vector<wchar_t> cmdLine(wcmd.begin(), wcmd.end());
cmdLine.push_back(L'\0');

//Starts a new Windows process (Unicode).
    BOOL success = CreateProcessW(

    NULL,
    wcmd.data(),
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
    DWORD exitCode = 0;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    file << "Status: Failed" << std::endl;
    file << "Exit Code: " << exitCode << std::endl;
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
    file << "Exit Code: " << exitCode << std::endl;
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

bool exp_sysinfo = sysinfo_export();
std::string sysinfo_cmd;

if (exp_sysinfo) {

fs::path filepath(sysinfo_getpath());

sysinfo_cmd = "powershell -Command \"systeminfo | Out-File -FilePath '" + filepath.string() + "'\"";

}
else {

sysinfo_cmd = "systeminfo";
}
    std::cout << "Gathering System Info.." << std::endl;

    int result = RunCommand(sysinfo_cmd, true);

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

int pingcount = PingTst_n();
std::string pingTarget = PingTst_target();

    std::string pingCMD = "ping " + pingTarget + " -n " + std::to_string(pingcount);
    std::cout << "Starting Ping Test." << std::endl;
    
    int result = RunCommand(pingCMD, true);

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

void BootRepair() {

std::cout << "WARNING: This action touches upon critical boot system configuration." << std::endl;
std::cout << "It is strongly reccomended to learn what this exact action [Boot Repair] does before confirming." << std::endl;
std::cout << "Its also recommended to backup your BCD and close all other applications." << std::endl;
std::cout << "Do you still wish to continue with this action?" << std::endl;

bool confirm = cmd_confirm();

if (confirm) {

std::cout << "Executing Boot Repair.." << std::endl;

int result = RunCommand("bootrec /fixmbr", true);
int result2 = RunCommand("bootrec /fixboot", true);
int result3 = RunCommand("bootrec /scanos", true);
int result4 = RunCommand("bootrec /rebuildbcd", true);

if (result == 0 && result2 == 0 && result3 == 0 && result4 == 0) std::cout << "Boot Repair completed!" << std::endl;
else std::cout << "Boot Repair encountered an issue. Please reboot PC to verify normal boot before reopening program as admin." << std::endl;


}
}

void WindowsReport() {

std::cout << "Generating Windows Report.." << std::endl;

int result = RunCommand("perfmon /report", true);

if (result == 0) std::cout << "Windows Report generated!" << std::endl;
else std::cout << "Windows Report encountered an issue. Please reopen program as admin." << std::endl;

}

void Powerthermal_check() {

std::cout << "WARNING: This action may take ~60 seconds or longer to complete and may cause light load onto your PC." << std::endl;
std::cout << "Do you still wish to continue?" << std::endl;

bool confirm = cmd_confirm();

if (confirm) {

std::cout << "Executing Power & Thermal Check.." << std::endl;

int result = RunCommand("cmd.exe /c \"powercfg /energy\"", true);
int result2 = RunCommand("powershell -Command Get-CimInstance Win32_Processor | Select-Object Name,LoadPercentage\"", true);
int result3 = RunCommand("powershell -Command Get-CimInstance Win32_TemperatureProbe | Select-Object CurrentReading\"", true);

if (result == 0 && result2 == 0 && result3 == 0) std::cout << "Power & Thermal Check completed!" << std::endl;
else std::cout << "Power & Thermal Check encountered an issue. Please reopen program as admin." << std::endl;


}

}
//FINISH THESE FUNCTIONS!!!!!!!