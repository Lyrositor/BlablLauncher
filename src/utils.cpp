#include <map>
#include <sstream>
#include <windows.h>

#include "utils.h"

struct cmp_str {
    bool operator() (const char* a, const char* b) const
    {
        return strcmp(a, b) < 0;
    }
};

std::map<const char*, unsigned int, cmp_str> KEY_CODES = {
        {"ctrl", MOD_CONTROL}, {"alt", MOD_ALT}, {"shift", MOD_SHIFT},
        {"down", VK_DOWN}, {"left", VK_LEFT}, {"right", VK_RIGHT},
        {"up", VK_UP}, {"tab", VK_TAB}, {"back", VK_BACK}, {"enter", VK_RETURN},
        {"clear", VK_CLEAR}, {"pause", VK_PAUSE}, {"space", VK_SPACE},
        {"pgup", VK_PRIOR}, {"pgdown", VK_NEXT}, {"end", VK_END},
        {"home", VK_HOME}, {"insert", VK_INSERT}, {"delete", VK_DELETE},
        {"f1", VK_F1}, {"f2", VK_F2}, {"f3", VK_F3}, {"f4", VK_F4},
        {"f5", VK_F5}, {"f6", VK_F6}, {"f7", VK_F7}, {"f8", VK_F8},
        {"f9", VK_F9}, {"f10", VK_F10}, {"f11", VK_F11}
};

unsigned int get_key_code(const char* name)
{
    // Convert the name to lowercase.
    char* name_l = new char[strlen(name)];
    strcpy(name_l, name);
    for (unsigned int i = 0; i < strlen(name_l); i++)
        name_l[i] = (char) tolower(name_l[i]);

    // Check if it's a special key.
    if (KEY_CODES.find(name_l) != KEY_CODES.end())
        return KEY_CODES[name_l];

    // Otherwise, it's a normal character (hopefully).
    else
        return get_key_code(name_l[0]);
}

unsigned int get_key_code(char c)
{
    return (unsigned int) toupper(c);
}

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delimiter))
        elems.push_back(item);
    return elems;
}