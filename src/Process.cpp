#include "process.h"

Process::Process()
{
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
}

bool Process::Launch(const char* program, const char* workingDirectory)
{
    if (CreateProcess(program, NULL, NULL, NULL, false, 0, NULL,
        workingDirectory, &si, &pi))
        return true;
    return false;
}

bool Process::IsRunning()
{
    DWORD exitCode = 0;
    if (GetExitCodeProcess(pi.hProcess, &exitCode) == 0)
        return false;
    return exitCode == STILL_ACTIVE;
}