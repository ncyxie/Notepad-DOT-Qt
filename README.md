*Last time information was updated: 18/02/2022*

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
- [Thanks to](#thanks-to)

## Introduction

**Notepad DOT Qt** is an open-source, cross-platform and highly customizable text editor.
It has all essential notepad functions with more handy stuff.
It is suitable for daily driving, from newbies to advanced users.

## Screenshots

<p align="center">
<img src="https://github.com/ncyxie/Notepad-DOT-Qt/blob/master/img/Screenshot_1.1.0-s1_Default.png" width="390" style="max-width:100%;">
<img src="https://github.com/ncyxie/Notepad-DOT-Qt/blob/master/img/Screenshot_1.1.0-s1_Customized.png" width="390" style="max-width:100%;">

## Download

**[Download Notepad DOT Qt](https://github.com/ncyxie/Notepad-DOT-Qt/releases/)**

**If you are Windows user, select '.exe' file. If you are Linux user, select '.AppImage' file.**

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
[Download the latest Notepad DOT Qt version](https://github.com/ncyxie/Notepad-DOT-Qt/releases) '.exe' file, open it up and follow further Notepad DOT Setup guide;
	
#### Using the winget tool
	
*Note: The winget command line tool is only supported on **Windows 10 (1709)** and **Windows 11 (21H2)** or later versions.*
	
*Note: If your Windows version is suitable for winget and winget still doesn't work, make sure that 'App Installer' package is up-to-date.*

**Installing Notepad DOT Qt via winget**
	
1. Open up **Command Prompt** or **Windows PowerShell** (**Windows Terminal** is suitable as well);
	
2. Enter this command: ``winget install ncyxie.Notepad-DOT-Qt`` and wait for the **winget** tool to finish up the setup process (the installation process is automatic);
	
3. That's it. Open up Notepad DOT Qt and enjoy. :P

## Bug reports

You can report bugs in the [Issues](https://github.com/ncyxie/Notepad-DOT-Qt/issues/) page on GitHub, or contact me using [Telegram](https://t.me/ncyxie) or Discord **(ncyxie#0290)**.

## FAQ

1. **Can I "kang" a little of this Notepad code?**

For sure. This is why it is open-source. Do not hesitate, make it better. :)

2. **Does this Notepad run on Windows and Linux?**

Yes, it does. If you are Windows user, make sure you download the '.exe' file and setup the application. 
If you are Linux user, download the '.AppImage' file and allow it to execute.

3. **What are this Notepad operating system requirements?**

* **Architecture: x86_64.**	

**For Windows operating system:**
* Minimum: Windows 7 SP1;
* **Recommended: Windows 10 (21H2) / 11 (21H2);**

**For Linux operating systems:**
* Minimum: Any Linux Distribution with glibc version 2.27 (e.g. Ubuntu 18.04 LTS);
* **Recommended: Any Linux Distribution with glibc version 2.34 (e.g. Ubuntu 21.10);**

If your OS meets the requirements *(or if doesn't)* and Notepad DOT Qt doesn't work properly, make sure your 
operating system is up to date.
	
4. **Where is Notepad DOT Qt config file/folder stored?**
	
**For Windows operating system:**
	
* Normally it is in registry, located in ``HKEY_CURRENT_USER\Software\ncyxie`` and config folder with config contents is called ``Notepad-DOT-Qt``.

**For Linux operating systems:**

* Normally it is located in ``~/.config/ncyxie`` and config file is called ``Notepad-DOT-Qt.conf``.
	
5. **How to check my Linux distribution glibc version?**
	
It's simple. Open up terminal and enter this line: ``ldd --version``.

6. **Why Notepad DOT Qt doesn't officially support macOS?**

I don't have macOS computer, so I cannot test for bugs, how it works and etc. 
Actually, Notepad DOT Qt *might* work on macOS, but you will have to compile, test and fix application bugs by yourself.

## Thanks to

- [zero9178](https://github.com/zero9178);
- [amirmohsen1384](https://github.com/amirmohsen1384);
- [XeZrunner](https://github.com/XeZrunner);
- YouTube tutorials;
- Forums support;
- and most importantly.. YOU!
