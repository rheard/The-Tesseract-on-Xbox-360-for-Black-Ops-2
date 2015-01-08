# The Tesseract on Xbox 360 for Black Ops 2

Bug Reporting: If a bug is found with the dll, report it to CraigChrist8239 immedietly. If a bug is found with a gsc menu running this dll, I do not care. It is the responsibility of the menu's creator to deal with their bugs.

What is the Tesseract?
The Tesseract is a cross-game modding tool for any devkit or RGH/JTAG. It is NOT a mod menu. The biggest feature is the numerous asset loaders including a script loader (GSC and CSC). Also included is various xex patches and my attempt at a challenge response (for an online bypass).

How to install:
1. Create a filerip of your legal, legit copy of Black Ops 2 for Xbox 360 and put it somewhere where your system can run it (either on the hard drive or a USB drive). 
2. Any DLC files you wish to install must be extracted from their container and the files must be installed to the Black Ops 2 folder. Use a program such as Horizon, Le Fluffie or even Modio to extract all the files from a container. Then copy any file ending in .sabs to the /stream/ folder and any file ending in .sabl to the /load/ folder. Any other files go into the installation path.
3. Last step is to install the TU file. Make sure this is done after ALL the DLC files you wish to install are installed. Again any .sabs files go in the /stream/ folder and any .sabl files go in the /load/ folder, the rest go in the installation path.
4. Last step is to patch the XEX. You can either do this manually, or have a friend do it, as this is warez. First you must patch the XEX with the XEXp from the TU file using XexPatcher. After that you can either patch the XEX to load the DLL or use a small app to launch the XEX then the DLL. 

List of Patches and Hooks:
[] A challenge response. Keep in mind that I in no way garuntee that this will keep you from getting banned. I do not go online much and I do not have a fleet of BETA testers to make sure that no one gets banned... but this should work. 
[] External DLC maps. The game will think all DLC is present at all times, and instead of loading the DLC containers, the map files will be loaded from the installation folder. 
[] Remove DVAR system checks.
[] Remove invalid gamertag check.
[] Remove clan tag checks.
[] Remove custom class name checks.
[] GSC++. A concept I made up that currently consists of 2 parts. The first is to report extra error information from the script loader. The second is to load "new" gscs, that do not exist yet.

Lastly there is the list of asset editors:
[] PhysPreset editor
[] PhysConstraints editor
[] Destructibles editor
[] Map Entities editor
[] Graphics light editor 
[] Localize entry editor
[] Weapon Variant editor
[] Weapon Attachment editor
[] Weapon Unique Attachment editor
[] Raw File editor
[] String Table editor
[] Script loader and editor
[] Vehicle editor
[] QDB and Slug editor. If you know what these are for, let me know.
[] Footstep Table and Footstep FX Table editors. These assets don't appear to actually be used by the game however.
[] Zombie Barrier editor

A note to developers, the load address is at 0x88000000.

Change Log:
v2.0
Gutted the entire Tesseract and rebuilt almost everything.
Went open-source.
Note that the playlist update editor has been removed and will be replaced by a .wad file loader in the future.
v1.1
Weapon editor fixes.
Allow loading of custom gsc files.
Failed function linkage reporting.
Include manual patches for DLC files.
Added Playlist Update Editor.
