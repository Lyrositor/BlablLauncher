BlablLauncher
=============

*An alternative launcher for Awesomenauts.*

BlablLauncher is a new launcher for [Awesomenauts](http://www.awesomenauts.com/). Features of BlablLauncher include:

* **Chat Bindings:** your keyboard's keys can be bound to send a team or global message in the game chat.

**License:** BlablLauncher is licensed under the [WTFPL](http://www.wtfpl.net/).

## Installation ##

To install BlablLauncher, follow the steps below.

1. Download the latest BlablLauncher release and unzip it somewhere on your computer. You can place it in your Awesomenauts directory for convenience.
2. Open the `ConfigBlabl.txt` file and set the `Bin` and `Dir` options to point to your Awesomenauts installation.
3. Create a Steam shortcut to BlablLauncher.exe. Follow [this link](https://support.steampowered.com/kb_article.php?ref=2219-YDJV-5557) for instructions on how to do so.
4. Now, whenever you want to run Awesomenauts through BlablLauncher you can use the new Steam shortcut you have created.

### Uninstallation ###

To remove BlablLauncher, simply delete BlablLauncher.exe and ConfigBlabl.txt from where you installed them. You can also remove your Steam shortcut if you created one.

## Building ##

If you wish to compile your own version of BlablLauncher, you will need a MinGW installation and a decently recent version of CMake. 

*Note: While BlablLauncher compiles under Visual Studio 2015, the library it depends on for reading INI files is faulty and will not work in VS.*