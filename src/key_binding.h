#ifndef key_binding_h
#define key_binding_h

#include <windows.h>

/**
 * Represents a chat message bound to a hot key.
 */
class KeyBinding {
public:
    /**
     * Creates the new key binding with the specified data.
     *
     * @param modCode The modifier key code for the hot key.
     * @param keyCode The main key code for the hot key.
     * @param message The bound message.
     * @param isGlobal Whether the message is for global or team chat.
     * @param keyboardLayout The OS keyboard layout to use.
     */
    KeyBinding(unsigned int modCode, unsigned int keyCode, const char* message,
               bool isGlobal, HKL keyboardLayout) :
            modCode(modCode), keyCode(keyCode), message(message),
            isGlobal(isGlobal), keyboardLayout(keyboardLayout) {};

    /**
     * Registers the hot key with the operating system.
     *
     * @param id The ID to attribute to the hot key in the operating system.
     */
    void Register(int id);


    /**
     * Types out the bound chat message and sends it.
     */
    void SendMessage();

private:
    unsigned int modCode;
    unsigned int keyCode;
    const char* message;
    bool isGlobal;
    HKL keyboardLayout;

    /**
     * Types out one character.
     *
     * @param character The character to type out.
     */
    void SendChar(char character);

    /**
     * Sends the Enter key, optionally with a Shift modifier first.
     *
     * A short pause is required for Awesomenauts to detect that Enter is pressed.
     * @param withShift Specifies whether or not to press Shift before.
     */
    void SendEnter(bool withShift = false);

    /**
     * Sends a key event to the operating system.
     *
     * @param keyCode The VK code to send.
     * @param flags Event flags (e.g. whether the key is pressed down or released).
     */
    void SendKeyEvent(unsigned int keyCode, DWORD event);
};

#endif // key_binding_h