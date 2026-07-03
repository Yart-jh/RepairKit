#include "display.h"
#include <iostream>

void WelcomeBanner() {

    std::cout << "Welcome to RepairTool!" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "--REPAIR--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[1] SFC SCAN" << std::endl;
    std::cout << "[2] DISM RESTORE" << std::endl;
    std::cout << "[3] CHKDSK" << std::endl;
    std::cout << "[4] FLUSH DNS (NETWORK)" << std::endl;
    std::cout << "[5] RENEW IP (NETWORK)" << std::endl;
    std::cout << "[6] RESET WINSOCK (NETWORK)" << std::endl;
    std::cout << "[7] RESET NETWORK STACK (NETWORK)" << std::endl;
    std::cout << "[8] BOOT REPAIR" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "--DIAGNOSE--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[9] WINDOWS REPORT" << std::endl;
    std::cout << "[10] POWER & THERMAL CHECK" << std::endl;
    std::cout << "[11] SSD/HDD HEALTH" << std::endl;
    std::cout << "[12] SYSTEM INFORMATION" << std::endl;
    std::cout << "[13] EVENT VIEWER" << std::endl;
    std::cout << "[14] DRIVER QUERY" << std::endl;
    std::cout << "[15] RELIABILITY MONITOR" << std::endl;
    std::cout << "[16] NETWORK INFO (NETWORK)" << std::endl;
    std::cout << "[17] PING TEST(NETWORK)" << std::endl;
    std::cout << "[18] OPEN CMD" << std::endl;
    std::cout << "[19] OPEN TSK MANAGER" << std::endl;
    std::cout << "[20] OPEN DEVICE MANAGER" << std::endl;
    std::cout << "[21] DEVICE MANAGER SCAN" << std::endl;
    std::cout << "[22] MEMORY DIAGNOSTIC" << std::endl;
    std::cout << "[23] DXDIAG" << std::endl;

    std::cout << " " << std::endl;
    std::cout << "--OTHER--" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "[0] EXIT" << std::endl;
    std::cout << "[69] INFO" << std::endl;

    std::cout << "======================================" << std::endl;

}

void HelpBanner() {

std::cout << "====================================================================================" << std::endl;
std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << "REPAIR TOOLS" << std::endl;
std::cout << " " << std::endl;

std::cout << "[1]: scans sfc for corrupted files and replaces them. " << std::endl;
std::cout << "[2]: Checks and restores DISM health.";
std::cout << " Do this before SFC scan." << std::endl;
std::cout << "[3]: Checks drive for corrupted data and other incorrect states. " << std::endl;
std::cout << "[4]: Flushes your DNS, potentially giving a more stable connection. " << std::endl;
std::cout << "[5]: Removes and requests a new IP address.";
std::cout << " Closing program/crashing may result in temporary network issues." << std::endl;
std::cout << "[6]: Resets your winsock, which fixes many connection issues. " << std::endl;
std::cout << "[7]: Resets network stack, which helps with unstable connections. " << std::endl;
std::cout << "[8] Repairs your boot configuration, which can fix boot issues." << std::endl;

std::cout << " " << std::endl;
std::cout << "DIAGNOSTIC TOOLS" << std::endl;
std::cout << " " << std::endl;

std::cout << "[9] Generates a windows report which can help diagnose system issues." << std::endl;
std::cout << "[10]: checks your PC's power and thermal state with a stress test. Takes ~60 seconds and causes light load" << std::endl;
std::cout << "[11]: Checks and displays SSD/HDD information, such as health and status. " << std::endl;
std::cout << "[12]: Displays OS and hardware information. " << std::endl;
std::cout << "[13]: Runs event viewer to check system errors that may have caused BSODS/crashes. " << std::endl;
std::cout << "[14]: Scans all installed drivers for critical failures." << std::endl;
std::cout << "[15]: Shows any driver failures and windows update failures." << std::endl;
std::cout << "[16]: Displays network information" << std::endl;
std::cout << "[17]: Tests your PC's internet connectivity. Press CTRL+C to stop the test" << std::endl;
std::cout << "[18]: Opens a new cmd terminal." << std::endl;
std::cout << "[19]: Opens task manager." << std::endl;
std::cout << "[20] Opens device manager." << std::endl;
std::cout << "[21]: Scans all drives on device manager, telling which ones arent working properly. " << std::endl;
std::cout << "[22]: Schedules a memory diagnostic on your next reboot. " << std::endl;
std::cout << "[23]: Scans your dxdiag for gpu/driver issues. " << std::endl;
std::cout << " " << std::endl;
std::cout << "====================================================================================" << std::endl;


}