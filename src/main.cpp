#include "input.h"
#include "display.h"
#include "security.h"
#include <iostream>
#include "command_rgstry.h"
#include "input.h"
#include "log.h"
#include <fstream>



int main() {

//Initializes g_admin variable.
    InitSecurity();

//Creates a log file if one hasnt been created.
    Create_Logfile();
    std::ofstream file(OpenLogfile());
    int choice = 999;

//Initializes command options.
    Initcmds();

    file << "=======REPAIRTOOL STARTED=======" << std::endl;
    file << " " << std::endl;

    WelcomeBanner();
//Loop that keeps program active as long as user choice is not 0.
while (choice != 0) {

//Gives a warning if user didnt launch program with admin priveleges.
if (! g_admin) {
    std::cout << "<WARNING> Program is not being ran with administrative privelages." << std::endl;
    std::cout << "To prevent some options not working; please reopen the program in admin mode." << std::endl;
}

//Choice is set via UserInput function.
    choice = UserInput();



if (choice != 0) {

//ExecuteChoice executes commands based on user choice.
    ExecuteChoice(choice);

}
else {

//Program closes if user choice is 0.
    file.close();
    return 0;
}
}

    return 0;    
}