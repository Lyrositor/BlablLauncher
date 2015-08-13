#include <inih/cpp/INIReader.h>
#include <iostream>
#include <windows.h>

#include "key_listener.h"
#include "process.h"

/**
 * The configuration file's relative path.
 */
const char* BLABL_CONFIG = "ConfigBlabl.txt";

/**
 * The default binary to launch.
 */
const char* DEFAULT_BIN = "Awesomenauts.exe";

/**
 * The default working directory (by default this is the current one).
 */
const char* DEFAULT_DIR = ".";

/**
 * Launches Awesomenauts, registers the chat binds and listens for key events.
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
	Process* awsmProcess = new Process();

    // Load the config file data.
    INIReader* reader = new INIReader(BLABL_CONFIG);
    if (reader->ParseError() < 0) {
        std::cerr << "ERROR: Failed to parse config file." << std::endl;
        return 1;
    }

    // Launch Awesomenauts.
    const char* awsmBin = reader->Get("Awesomenauts", "Bin", DEFAULT_BIN).c_str();
    const char* awsmDir = reader->Get("Awesomenauts", "Dir", DEFAULT_DIR).c_str();
    if (!awsmProcess->Launch(awsmBin, awsmDir)) {
        std::cerr << "ERROR: Failed to create process." << std::endl;
        return 1;
    }

    // Load the bindings and listen for hot key presses while Awesomenauts runs.
    KeyListener* awsmListener = new KeyListener(GetKeyboardLayout(0));
    awsmListener->LoadFromFile(reader);
    delete reader;
    while (awsmProcess->IsRunning())
        awsmListener->ProcessInput();

    delete awsmProcess;
    delete awsmListener;
    return 0;
}