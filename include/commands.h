#pragma once
#include <string>

void SFCScan();
void DISMRestore();
void CHKDSK();
void FlushDNS();
void RenewIP();
void ResetWinsock();
void ResetNetworkStack();
int RunCommand(const std::string& cmd);
void DeviceManagerScan();
void Mem_Diagnostic();
void DXDIAG();
void Drive_HealthCheck();
void SystemInfo();
void EventVWR();
void Driver_query();
void Reliability_mon();
void Network_info();
void PingTest();
void TaskMNGR();
void DeviceMNGR();
void New_CMD();
