![BlablLauncher](http://i.imgur.com/1dImyPk.png)
=============

*An alternative launcher for Awesomenauts.*

BlablLauncher is a new launcher for [Awesomenauts](http://www.awesomenauts.com/). It is not intended as a replacement for the vanilla launcher, but as a complementary launcher to be used when the graphical settings do not need to be changed. Features of BlablLauncher include:

* **Chat Bindings:** your keyboard's keys can be bound to send a team or global message in the game chat. Your bindings remain active until Awesomenauts is closed, even if you switch windows.
    * Tip: Try to avoid moving when you hit your key combinations, to avoid dropping letters from your message.
    * Tip: Test our your new bindings in bot matches beforehand to ensure that nothing is wrong. Try to avoid unusual characters.

**Requirements:** BlablLauncher only works on Windows systems.

**License:** BlablLauncher is licensed under the [WTFPL](http://www.wtfpl.net/).

## Installation ##

To install BlablLauncher, follow the steps below.

1. Download the latest BlablLauncher release and unzip it somewhere on your computer. You can place it in your Awesomenauts directory for convenience.
    * Default Awesomenauts directory: `C:\Program Files (x86)\Steam\SteamApps\common\Awesomenauts`
2. If you didn't place BlablLaucnher in your Awesomenauts directory, open the `ConfigBlabl.txt` file and set the `Bin` and `Dir` options to point to your Awesomenauts installation.
3. Create a Steam shortcut to `Blabl.exe`. Follow [this link](https://support.steampowered.com/kb_article.php?ref=2219-YDJV-5557) for instructions on how to do so.
    * If you plan on using BlablLauncher regularly, a better option is to rename `AwesomenautsLauncher.exe` to something else (e.g. `AwesomenautsLauncher_old.exe`), and then to rename `Blabl.exe` to `AwesomenautsLauncher.exe`. When you launch Awesomenauts through Steam, it will now use Blabl instead of the normal launcher. Note that if the launcher ever gets patched and overwritten (which is not likely), you will have to repeat this procedure.
4. Now, whenever you want to run Awesomenauts through BlablLauncher you can use the new Steam shortcut you have created (or the old Awesomenauts shortcut, if you used the second method).

### Uninstallation ###

To remove BlablLauncher, simply delete `Blabl.exe` and `ConfigBlabl.txt` from where you installed them. You can also remove your Steam shortcut if you created one.

## Building ##

If you wish to compile your own version of BlablLauncher, you will need a MinGW installation and a decently recent version of CMake. 

*Note: While BlablLauncher compiles under Visual Studio 2015, the library it depends on for reading INI files is faulty and will not work in VS.*