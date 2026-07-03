#include "security.h"
#include <iostream>
#include <windows.h>
#include "command_rgstry.h"

    bool g_admin = false;

void InitSecurity() {
    g_admin = IsAdmin();
}

bool cmd_confirm() {

    char choice;

while (true) {

    std::cout << "Are you sure you would like to continue with this action?" << std::endl;

    std::cin >> choice;

if (choice == 'y' || choice == 'Y') {

    return true;
    
}
else if (choice == 'n' || choice == 'N') {

    std::cout << "Action cancelled." << std::endl;
    return false;

}
else {

    std::cout << "<ERROR> Invalid Input" << std::endl;
    std::cout << "Try again.." << std::endl;
    continue;

}

}

}

//Function that checks if the user's token is a part of the administrator group.
bool IsAdmin() {

    BOOL isAdmin = false;
    PSID adminGroup = nullptr;

//Builds a SID representing the admin group.
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;

if (AllocateAndInitializeSid(
    &NtAuthority,
    2,
    SECURITY_BUILTIN_DOMAIN_RID,
    DOMAIN_ALIAS_RID_ADMINS,
    0,0,0,0,0,0,
    &adminGroup)) {

//Checks if the users token contains the SID.
if (!CheckTokenMembership(NULL, adminGroup, &isAdmin)) {
    isAdmin = FALSE;
}
//Frees allocated memory to prevent memory leaks.
    FreeSid(adminGroup);
}

    return isAdmin == TRUE;
}

bool IsAllowed(int choice) {

if (choice == 0) return true;

if (choice == 69) return true;


auto it = commandRegistry.find(choice);


if (it == commandRegistry.end()) {

std::cout << "<ERROR> Invalid input." << std::endl;
return false;

}

const Command& command = it->second;

if (command.requiresAdmin && !g_admin) {

std::cout << "<ERROR> You do not have the proper permissions to execute this command." << std::endl;
return false;

}

std::cout << "Input validated!" << std::endl;
return true;
}