#include "key_binding.h"

// For some reason, for MinGW installations INPUT isn't defined through
// windows.h, so we need to import the deprecated winable.h.
#ifdef __MINGW32__
#include <winable.h>
#endif // __MINGW32__

void KeyBinding::Register(int id)
{
    RegisterHotKey(NULL, id, modCode, keyCode);
}

void KeyBinding::SendMessage()
{
    Sleep(200);
    SendEnter(isGlobal);
    for (unsigned int i = 0; i < strlen(message); i++)
        SendChar(message[i]);
    SendEnter();
}

void KeyBinding::SendChar(char character)
{
    // Get the virtual keyboard key code and any modifier keys required.
    SHORT ret = VkKeyScanEx(character, keyboardLayout);
    WORD wVk = LOBYTE(ret);
    BYTE mods = HIBYTE(ret);
    bool withShift = (bool) (mods & 1);
    bool withCtrl = (bool) ((mods >> 1) & 1);
    bool withAlt = (bool) ((mods >> 2) & 1);

    // Press down any necessary modifier keys.
    if (withShift)
        SendKeyEvent(VK_SHIFT, 0);
    if (withCtrl)
        SendKeyEvent(VK_CONTROL, 0);
    if (withAlt)
        SendKeyEvent(VK_MENU, 0);

    // Send the key.
    SendKeyEvent(wVk, 0);
    Sleep(5);
    SendKeyEvent(wVk, KEYEVENTF_KEYUP);

    // Release the modifier keys.
    if (withShift)
        SendKeyEvent(VK_SHIFT, KEYEVENTF_KEYUP);
    if (withCtrl)
        SendKeyEvent(VK_CONTROL, KEYEVENTF_KEYUP);
    if (withAlt)
        SendKeyEvent(VK_MENU, KEYEVENTF_KEYUP);
}

void KeyBinding::SendEnter(bool withShift)
{
    // Optionally press Shift, for a global message.
    if (withShift)
        SendKeyEvent(VK_SHIFT, 0);

    // Press Enter and wait before releasing it, to let Awesomenauts detect it.
    SendKeyEvent(VK_RETURN, 0);
    Sleep(100);
    SendKeyEvent(VK_RETURN, KEYEVENTF_KEYUP);

    // Release Shift, if it was pressed down.
    if (withShift)
        SendKeyEvent(VK_SHIFT, KEYEVENTF_KEYUP);
}

void KeyBinding::SendKeyEvent(unsigned int keyCode, DWORD flags)
{
    // Prepare the keyboard input event.
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = (WORD) keyCode;
    ip.ki.dwFlags = flags;

    // Send the input to the operating system.
    SendInput(1, &ip, sizeof(INPUT));
}