*Last time information was updated: 22/10/2021*

# Notepad DOT Qt

## Table of contents

- [Latest Information](#latest-information)
- [Introduction](#introduction)
- [Screenshots](#screenshots)
- [Download](#download)
- [Installation guide](#installation-guide)
	- [Linux](#linux-guide-source)
		- [Using the GUI](#using-the-gui)
		- [Using the Terminal](#using-the-terminal)
	- [Windows](#windows)
		- [Using the Setup file](#using-the-setup-file)
		- [Using the winget tool](#using-the-winget-tool-guide-source)
- [Bug reports](#bug-reports)
- [FAQ](#faq)
- [Thanks to](#thanks-to)

## Latest Information

**Notepad DOT Qt v1.1.0-s1 is now available to download.**

## Introduction

**Notepad DOT Qt** is an open-source, cross-platform and highly customizable text editor.
It has all essential notepad functions with more handy stuff.
It is suitable for daily driving, from newbies to advanced users.

## Screenshots

<p align="center">
<img src="https://github.com/ncyxie/Notepad-DOT-Qt/blob/master/img/Screenshot_1.1.0-s1_Default.png" width="410" style="max-width:100%;">
<img src="https://github.com/ncyxie/Notepad-DOT-Qt/blob/master/img/Screenshot_1.1.0-s1_Customized.png" width="410" style="max-width:100%;">

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
	
#### Using the winget tool ([Guide source](https://docs.microsoft.com/en-us/windows/package-manager/winget))

**Install winget**
	
*Note: The winget tool requires Windows 10, version 1809 (10.0.17763), or a later version of Windows 10.*
	
There are several ways to install the winget tool:
* The **winget** tool is included in the flight or preview version of [Windows App Installer](https://www.microsoft.com/p/app-installer/9nblggh4nns1?ocid=9nblggh4nns1_ORSEARCH_Bing&rtc=1&activetab=pivot:overviewtab). You must install the preview version of **App Installer** to use **winget**. To gain early access, submit your request to the [Windows Package Manager Insiders Program](https://aka.ms/AppInstaller_InsiderProgram). Participating in the flight ring will guarantee you see the latest preview updates.

* Participate in the [Windows Insider flight ring](https://insider.windows.com).

* Install the Windows Desktop App Installer package located on the [Releases page for the winget repository](https://github.com/microsoft/winget-cli/releases).

**Installing Notepad DOT Qt via winget**
	
1. Open up **Command Prompt** or **Windows PowerShell** (**Windows Terminal** is suitable as well);
	
2. Enter this command: ``winget install ncyxie.Notepad-DOT-Qt`` and wait for the **winget** tool to finish up the setup process (the installation process is automatic);
	
3. That's it. Open up Notepad DOT Qt and enjoy. :P

## Bug reports

You can report bugs in the [Issues](https://github.com/ncyxie/Notepad-DOT-Qt/issues/) page on GitHub, or contact me using [Telegram](https://t.me/ncyxie) or Discord (ncyxie#0290).

## FAQ

1. **Can I "kang" a little of this Notepad code?**

For sure. This is why it is open-source. Do not hesitate, make it better. :)

2. **Does this Notepad run on Windows and Linux?**

Yes, it does. If you are Windows user, make sure you download the '.exe' file and setup the application. 
If you are Linux user, download the '.AppImage' file and allow it to execute.

3. **What are this Notepad operating system requirements?**

**For Windows operating system:**
* Minimum: Windows 7 SP1;
* **Recommended: Windows 10 21H1 *(or Windows 11 Insider build);***

* **Architecture: x86_64.**

**For Linux operating systems:**
* Minimum: Any Linux Distribution with glibc version 2.27 (e.g. Ubuntu 18.04 LTS);
* **Recommended: Any Linux Distribution with glibc version 2.33 (e.g. Ubuntu 21.04);**

* **Architecture: x86_64.**

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
