#include "display.h"
#include <iostream>

void WelcomeBanner() {

    std::cout << "Welcome to RepairTool!" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "--REPAIR--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[sfc] SFC SCAN" << std::endl;
    std::cout << "[dism] DISM RESTORE" << std::endl;
    std::cout << "[chkdsk] CHKDSK" << std::endl;
    std::cout << "[flushdns] FLUSH DNS (NETWORK)" << std::endl;
    std::cout << "[renewip] RENEW IP (NETWORK)" << std::endl;
    std::cout << "[resetwinsock] RESET WINSOCK (NETWORK)" << std::endl;
    std::cout << "[resetnetworkstack] RESET NETWORK STACK (NETWORK)" << std::endl;
    std::cout << "[bootrepair] BOOT REPAIR" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "--DIAGNOSE--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[windowsreport] WINDOWS REPORT" << std::endl;
    std::cout << "[powerthermal_check] POWER & THERMAL CHECK" << std::endl;
    std::cout << "[driver_status] SSD/HDD HEALTH" << std::endl;
    std::cout << "[sysinfo] SYSTEM INFORMATION" << std::endl;
    std::cout << "[eventvwr] EVENT VIEWER" << std::endl;
    std::cout << "[driverquery] DRIVER QUERY" << std::endl;
    std::cout << "[reliability_mon] RELIABILITY MONITOR" << std::endl;
    std::cout << "[networkinfo] NETWORK INFO (NETWORK)" << std::endl;
    std::cout << "[pingtest] PING TEST(NETWORK)" << std::endl;
    std::cout << "[newcmd] OPEN CMD" << std::endl;
    std::cout << "[taskmngr] OPEN TSK MANAGER" << std::endl;
    std::cout << "[devicemngr] OPEN DEVICE MANAGER" << std::endl;
    std::cout << "[devicemanagerscan] DEVICE MANAGER SCAN" << std::endl;
    std::cout << "[memdiag] MEMORY DIAGNOSTIC" << std::endl;
    std::cout << "[dxdiag] DXDIAG" << std::endl;

    std::cout << " " << std::endl;
    std::cout << "--OTHER--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[exit] EXIT" << std::endl;
    std::cout << "[info] INFO" << std::endl;

    std::cout << "======================================" << std::endl;

}

void WelcomeBan_noadmin() {

    std::cout << "Welcome to RepairTool!" << std::endl;
    std::cout << "[Some options may be unavailable due to lack of admin privilages]" << std::endl;
    std::cout << "[Reopen the program as administrator to gain full access to the program]" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "--REPAIR--" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "[flushdns] FLUSH DNS (NETWORK)" << std::endl;
    std::cout << "[renewip] RENEW IP (NETWORK)" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "--DIAGNOSE--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[windowsreport] WINDOWS REPORT" << std::endl;
    std::cout << "[powerthermal_check] POWER & THERMAL CHECK" << std::endl;
    std::cout << "[driver_status] SSD/HDD HEALTH" << std::endl;
    std::cout << "[sysinfo] SYSTEM INFORMATION" << std::endl;
    std::cout << "[eventvwr] EVENT VIEWER" << std::endl;
    std::cout << "[driverquery] DRIVER QUERY" << std::endl;
    std::cout << "[reliability_mon] RELIABILITY MONITOR" << std::endl;
    std::cout << "[networkinfo] NETWORK INFO (NETWORK)" << std::endl;
    std::cout << "[pingtest] PING TEST(NETWORK)" << std::endl;
    std::cout << "[newcmd] OPEN CMD" << std::endl;
    std::cout << "[taskmngr] OPEN TSK MANAGER" << std::endl;
    std::cout << "[devicemngr] OPEN DEVICE MANAGER" << std::endl;
    std::cout << "[devicemanagerscan] DEVICE MANAGER SCAN" << std::endl;
    std::cout << "[dxdiag] DXDIAG" << std::endl;

    std::cout << " " << std::endl;
    std::cout << "--OTHER--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[exit] EXIT" << std::endl;
    std::cout << "[info] INFO" << std::endl;

    std::cout << "======================================" << std::endl;

}



void HelpBanner() {

std::cout << "====================================================================================" << std::endl;
std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << "REPAIR TOOLS" << std::endl;
std::cout << " " << std::endl;

std::cout << "[sfc]: scans sfc for corrupted files and replaces them. " << std::endl;
std::cout << "[dism]: Checks and restores DISM health.";
std::cout << " Do this before SFC scan." << std::endl;
std::cout << "[chkdsk]: Checks drive for corrupted data and other incorrect states. " << std::endl;
std::cout << "[flushdns]: Flushes your DNS, potentially giving a more stable connection. " << std::endl;
std::cout << "[renewip]: Removes and requests a new IP address.";
std::cout << " Closing program/crashing may result in temporary network issues." << std::endl;
std::cout << "[resetwinsock]: Resets your winsock, which fixes many connection issues. " << std::endl;
std::cout << "[resetnetworkstack]: Resets network stack, which helps with unstable connections. " << std::endl;
std::cout << "[bootrepair]: Repairs your boot configuration, which can fix boot issues." << std::endl;

std::cout << " " << std::endl;
std::cout << "DIAGNOSTIC TOOLS" << std::endl;
std::cout << " " << std::endl;

std::cout << "[windowsreport]: Generates a windows report which can help diagnose system issues." << std::endl;
std::cout << "[powerthermal_check]: checks your PC's power and thermal state with a stress test. Takes ~60 seconds and causes light load" << std::endl;
std::cout << "[driver_status]: Checks and displays SSD/HDD information, such as health and status. " << std::endl;
std::cout << "[sysinfo]: Displays OS and hardware information. " << std::endl;
std::cout << "[eventvwr]: Runs event viewer to check system errors that may have caused BSODS/crashes. " << std::endl;
std::cout << "[driverquery]: Scans all installed drivers for critical failures." << std::endl;
std::cout << "[reliability_mon]: Shows any driver failures and windows update failures." << std::endl;
std::cout << "[networkinfo]: Displays network information" << std::endl;
std::cout << "[pingtest]: Tests your PC's internet connectivity. Press CTRL+C to stop the test" << std::endl;
std::cout << "[newcmd]: Opens a new cmd terminal." << std::endl;
std::cout << "[taskmngr]: Opens task manager." << std::endl;
std::cout << "[devicemngr]: Opens device manager." << std::endl;
std::cout << "[devicemanagerscan]: Scans all drives on device manager, telling which ones arent working properly. " << std::endl;
std::cout << "[memdiag]: Schedules a memory diagnostic on your next reboot. " << std::endl;
std::cout << "[dxdiag]: Scans your dxdiag for gpu/driver issues. " << std::endl;
std::cout << " " << std::endl;
std::cout << "====================================================================================" << std::endl;


}

void HelpBanner_noadmin() {

std::cout << "====================================================================================" << std::endl;
std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << "REPAIR TOOLS" << std::endl;
std::cout << " " << std::endl;


std::cout << "[flushdns]: Flushes your DNS, potentially giving a more stable connection. " << std::endl;
std::cout << "[renewip]: Removes and requests a new IP address.";
std::cout << " Closing program/crashing may result in temporary network issues." << std::endl;

std::cout << " " << std::endl;
std::cout << "DIAGNOSTIC TOOLS" << std::endl;
std::cout << " " << std::endl;

std::cout << "[windowsreport]: Generates a windows report which can help diagnose system issues." << std::endl;
std::cout << "[powerthermal_check]: checks your PC's power and thermal state with a stress test. Takes ~60 seconds and causes light load" << std::endl;
std::cout << "[driver_status]: Checks and displays SSD/HDD information, such as health and status. " << std::endl;
std::cout << "[sysinfo]: Displays OS and hardware information. " << std::endl;
std::cout << "[eventvwr]: Runs event viewer to check system errors that may have caused BSODS/crashes. " << std::endl;
std::cout << "[driverquery]: Scans all installed drivers for critical failures." << std::endl;
std::cout << "[reliability_mon]: Shows any driver failures and windows update failures." << std::endl;
std::cout << "[networkinfo]: Displays network information" << std::endl;
std::cout << "[pingtest]: Tests your PC's internet connectivity. Press CTRL+C to stop the test" << std::endl;
std::cout << "[newcmd]: Opens a new cmd terminal." << std::endl;
std::cout << "[taskmngr]: Opens task manager." << std::endl;
std::cout << "[devicemngr]: Opens device manager." << std::endl;
std::cout << "[devicemanagerscan]: Scans all drives on device manager, telling which ones arent working properly. " << std::endl;
std::cout << "[dxdiag]: Scans your dxdiag for gpu/driver issues. " << std::endl;
std::cout << " " << std::endl;
std::cout << "====================================================================================" << std::endl;

}