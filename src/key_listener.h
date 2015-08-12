#ifndef key_listener_h
#define key_listener_h

#include <inih/cpp/INIReader.h>
#include <string>
#include <vector>
#include <windows.h>

#include "key_binding.h"

/**
 * The keyboard listener responsible for catching hot key presses.
 */
class KeyListener {
public:
    /**
     * Creates the key listener with the specified keyboard layout.
     *
     * @param keyboardLayout The layout to use for sending out messages.
     */
    KeyListener(HKL keyboardLayout) : keyboardLayout(keyboardLayout) {};

    /**
     * Loads a set of bindings from an opened INI file.
     *
     * @param reader An opened INI file reader with configuration settings.
     * @return True if the data was loaded successfully, false otherwise.
     */
    bool LoadFromFile(INIReader* reader);

    /**
     * Processes every event since the last call.
     *
     * If a hot key was triggered, send the bound message.
     */
    void ProcessInput();

private:
    std::vector<KeyBinding*> bindings;
    HKL keyboardLayout;

    /**
     * Adds a new key binding to the list and registers it.
     *
     * The hot key's id is its position in the bindings list.
     * @param keys The list of keys associated with the hot key.
     * @param message The message to type out.
     * @param isGlobal Whether or no the message is intended for the global chat.
     */
    void Add(std::vector<std::string> keys, const char* message, bool isGlobal);

    /**
     * Sends the message associated with the hot key.
     *
     * @param id The ID of the hot key which was pressed.
     */
    void ProcessHotKey(unsigned int id);
};

#endif // key_listener_h