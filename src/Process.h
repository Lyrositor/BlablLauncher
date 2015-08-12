#ifndef process_h
#define process_h

#include <windows.h>

/**
 * Represents a running process.
 */
class Process {

public:
    /**
     * Prepares the process information.
     */
    Process();

    /**
     * Launches the specified executable from the specified working directory.
     *
     * @param program The executable to launch.
     * @param workingDirectory The working directory for the program.
     * @return True if the process was created, false otherwise.
     */
    bool Launch(const char* program, const char* workingDirectory);

    /**
     * Returns whether or not the process is still running.
     *
     * @return True if the process is still running, false otherwise.
     */
    bool IsRunning();

private:
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
};

#endif // process_h
