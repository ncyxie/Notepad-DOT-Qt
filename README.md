# Notepad DOT Qt

## Table of contents

- [Introduction](#introduction)
- [Screenshots](#screenshots)
- [Download](#download)
- [Installation guide](#installation-guide)
	- [Linux](#linux-guide-source)
		- [Using the GUI](#using-the-gui)
		- [Using the Terminal](#using-the-terminal)
	- [Windows](#windows)
		- [Using the Setup file](#using-the-setup-file)
		- [Using the winget tool](#using-the-winget-tool)
- [Bug reports](#bug-reports)
- [FAQ](#faq)
- [Special thanks to](#special-thanks-to)

## Introduction

**Notepad DOT Qt** is an open source, cross-platform and highly customizable text editor.
It has all the essential notepad features with more handy stuff.
It is suitable for everyday use, from beginners to advanced users.

## Screenshots

<p align="center">
<img src="https://github.com/ncyxie/Notepad-DOT-Qt/blob/master/img/Screenshot_1.1.0-s1_Default.png" width="390" style="max-width:100%;">
<img src="https://github.com/ncyxie/Notepad-DOT-Qt/blob/master/img/Screenshot_1.1.0-s1_Customized.png" width="390" style="max-width:100%;">

## Download

**[Download Notepad DOT Qt](https://github.com/ncyxie/Notepad-DOT-Qt/releases/)**

**If you are a Windows user, select the '.exe' file. If you are a Linux user, select the '.AppImage' file.**

## Installation guide

### Linux ([Guide source](https://docs.appimage.org/introduction/quickstart.html))

#### Using the GUI
1. [Download the latest Notepad DOT Qt version](https://github.com/ncyxie/Notepad-DOT-Qt/releases) '.AppImage' file;

2. Open your file manager and browse to the location of the Notepad DOT AppImage;

3. Right-click on the Notepad DOT AppImage and click the ‘Properties’ entry;

4. Switch to the Permissions tab;

5. Click the ‘Allow executing file as program’ checkbox if you are using a Nautilus-based file manager (Files, Nemo, Caja), or click the ‘Is executable’ checkbox if you are using Dolphin, or change the ‘Execute’ drop down list to ‘Anyone’ if you are using PCManFM;

6. Close the dialog;

7. Double-click on the Notepad DOT AppImage file to run.

#### Using the Terminal
1. [Download the latest Notepad DOT Qt version](https://github.com/ncyxie/Notepad-DOT-Qt/releases) '.AppImage' file;

2. Open a terminal;

3. Change to the directory containing the AppImage, e.g., using ``cd <my directory>``;

4. Make the AppImage executable: ``chmod +x Notepad_DOT_v1.1.0-s1.AppImage``;

5. Run the AppImage: ``./Notepad_DOT_v1.1.0-s1.AppImage``.

### Windows

#### Using the Setup file
[Download the latest Notepad DOT Qt version](https://github.com/ncyxie/Notepad-DOT-Qt/releases) '.exe' file, open it and follow the instructions for setting up Notepad DOT;
	
#### Using the winget tool
	
*Note: The winget command line utility is only supported on **Windows 10 (since version 1709)** and later versions.
If your version of Windows is compatible with Winget and Winget still doesn't work, make sure that the 'App Installer' package is up to date.*

**Installing Notepad DOT Qt via winget**
	
1. Open **Command Prompt** or **Windows PowerShell** (**Windows Terminal** will also work);
	
2. Type this command: ``winget install ncyxie.Notepad-DOT-Qt`` and wait for the **winget** tool to finish the setup process (the installation process is automatic);
	
3. That's it. Open up Notepad DOT Qt and enjoy.

## Bug reports

You can report bugs in the [Issues](https://github.com/ncyxie/Notepad-DOT-Qt/issues/) page on GitHub, or contact me via [Telegram](https://t.me/ncyxie) or Discord **(@ncyxie)**.

## FAQ

1. **Can I take some of the Notepad DOT Qt code for my own project?**

Absolutely. That is why it is open source. Feel free to make it better.

2. **Does Notepad DOT Qt run on Windows and Linux operating systems?**

Yes, it does. If you are a Windows user, make sure you download the '.exe' file and set up the application. 
If you are a Linux user, download the '.AppImage' file and allow it to run.

3. **What are the operating system requirements for Notepad DOT Qt?**

* **Architecture: x86-64.**

**For Windows operating system:**
* Minimum: Windows 7 SP1;
* **Recommended: Any newer Windows operating system that is more recent than Windows 7 SP1.**

**For Linux operating systems:**
* Minimum: Any Linux Distribution with glibc version 2.27 (e.g. Ubuntu 18.04 LTS);
* **Recommended: Any Linux Distribution with glibc version above 2.27;**

If your computer meets the requirements and Notepad DOT Qt is still not working properly, please make sure that your 
operating system and required components are up to date.
	
4. **Where is the Notepad DOT Qt config file/folder stored?**
	
**For Windows operating system:**
	
* It is usually found in the registry at ``HKEY_CURRENT_USER\Software\ncyxie`` with a config folder called ``Notepad-DOT-Qt``.

**For Linux operating systems:**

* It is usually located in ``~/.config/ncyxie`` with a config file called ``Notepad-DOT-Qt.conf``.
	
5. **How to check my Linux distribution glibc version?**
	
It's simple. Open a terminal and type this line: ``ldd --version``.

6. **Why Notepad DOT Qt doesn't officially support macOS?**

I don't have macOS computer, so development capabilities for macOS would be very limited. 
In fact, Notepad DOT Qt *should* work on macOS, but the responsibility for compiling and debugging the application lies with you.

## Special thanks to

- [XeZrunner](https://github.com/XeZrunner);
- [zero9178](https://github.com/zero9178);
- [amirmohsen1384](https://github.com/amirmohsen1384);
- and most importantly.. YOU!
