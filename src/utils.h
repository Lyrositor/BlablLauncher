#ifndef utils_h
#define utils_h

#include <string>
#include <vector>

/**
 * Returns the OS key code for the specified key alias.
 *
 * @param name The alias for the key.
 * @return The OS key code associated with the key alias.
 */
unsigned int get_key_code(const char* name);

/**
 * Returns the OS key code for the specified character.
 *
 * @param c The character to get the key code for.
 * @return The OS key code associated with the character.
 */
unsigned int get_key_code(char c);

/**
 * Splits a string with a delimiter.
 *
 * Source: http://stackoverflow.com/questions/236129/split-a-string-in-c
 */
std::vector<std::string> split(const std::string &s, char delimiter);

#endif // utils_h
