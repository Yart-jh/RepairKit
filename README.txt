RepairKit V 1.0.9

# DESCRIPTION

RepairKit is an open source utility tool that wraps 20+ windows system tools and commands that can help with diagnosing and maintaining windows systems into a interface which allows the user to execute them with a string input.

Program also includes admin privilege verification and locks users out of commands that usually require administrative privilege.

This program was built as both a learning project and a resume piece for an upcoming college program. This program is also my first ever GitHub repository and is one of my first modularized programs.

# REPAIRKIT COMMANDS

- SFC Scan
- DISM Restore
- CHKDSK
- Flush DNS
- Renew IP
- Reset Winsock
- Reset Network Stack
- Device Manager Scan
- Memory Diagnostics
- DXDIAG
- SSD/HDD Health
- System Information
- Event Viewer
- Driver Query
- Reliability Monitor
- Network Information
- Ping Test
- Open CMD
- Open Task Manager
- Open Device Manager
- Boot Repair
- Windows Report
- Power & CPU Load Report.
- Output Log Contents.


# REQUIREMENTS TO BUILD:

Windows
MinGW-w64 (or another compatible GCC)

# BUILD INSTRUCTION:

run "repairkit_releasebuilder.bat" to compile source code into a usable .exe . After the build is complete; run "RepairKit.exe" 

# PREBUILT RELEASE

If you do not wish to compile the program yourself or don't have MinGW; there is a compiled .exe included in releases that is updated along with every source code update.

# NOTES

Some commands may fail to work without administrative privilages so always run the program as administrator to prevent any issues.
