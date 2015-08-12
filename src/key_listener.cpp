#include <iostream>

#include "key_listener.h"
#include "utils.h"

/**
 * The INI section for messages intended for global chat.
 */
const char* GLOBAL_SECTION = "GlobalBindings";

/**
 * The INI section for messages intended for team chat.
 */
const char* TEAM_SECTION = "TeamBindings";

bool KeyListener::LoadFromFile(INIReader* reader)
{
    // Register the global bindings.
    for (std::string field : reader->GetFields(GLOBAL_SECTION)) {
        std::vector<std::string> keys = split(field, '+');
        const char* message = reader->Get(GLOBAL_SECTION, field, "").c_str();
        if (strlen(message))
            Add(keys, message, true);
    }

    // Register the team bindings.
    for (std::string field : reader->GetFields(TEAM_SECTION)) {
        std::vector<std::string> keys = split(field, '+');
        const char* message = reader->Get(TEAM_SECTION, field, "").c_str();
        if (strlen(message))
            Add(keys, message, false);
    }

    return true;
}

void KeyListener::ProcessInput() {
    MSG msg = {0};
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0) {
        if (msg.message == WM_HOTKEY) {
            std::cout << "Hot Key Triggered: " << msg.wParam << std::endl;
            ProcessHotKey(msg.wParam);
        }
    }
}

void KeyListener::Add(std::vector<std::string> keys, const char* message,
                      bool isGlobal)
{
    // Discard the hot key if it has three or more keys in it.
    if (keys.size() > 2)
        return;

    std::cout << "Adding Hot Key: " << keys[0];
    unsigned int modCode = 0, keyCode;

    // Get the code for the modifier, if there is one.
    if (keys.size() == 2) {
        modCode = get_key_code(keys[0].c_str());
        std::cout << "(" << modCode << ") + " << keys[1];
    }

    // Get the code for the key itself.
    keyCode = get_key_code(keys[keys.size() - 1].c_str());
    std::cout << "(" << keyCode << ")" << std::endl;

    // Register the new binding.
    KeyBinding* binding = new KeyBinding(modCode, keyCode, message, isGlobal,
                                         keyboardLayout);
    binding->Register(bindings.size());
    bindings.push_back(binding);
}

void KeyListener::ProcessHotKey(unsigned int id)
{
    if (id < bindings.size())
        bindings[id]->SendMessage();
}