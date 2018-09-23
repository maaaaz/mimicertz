mimicertz
============

Description
-----------
A minimal safe version of mimikatz to only allow the export of non-exportable Windows certificates 


Features
--------
* Based on the latest stable mimikatz version `2.1.1`
* Compiled following that [awesome article](https://insinuator.net/2017/10/extract-non-exportable-certificates-and-evade-anti-virus-with-mimikatz-and-powersploit/) guidance
* Compiled with only the `standard` and [`crypto`](https://adsecurity.org/?page_id=1821#CRYPTOCertificates) modules and removing all the other **offensive** ones (`privilege`, `sekurlsa`, `kerberos`, `lsadump` etc.)
* Removing most of the `mimikatz` textual occurences in the code and even the icon to try to stay **undetected by antimalware solutions**
* Providing **x86 and x64 self-signed binaries**, compatible from Windows 7 (tested on Windows 7 x86 and Windows 10 x64)


Common usage: exporting non-exportable personal certificates (`MY` certificate store) 
-------------------------------------------------------------------------------------
1. Download the binary matching your architecture (x86 or x64)
2. Execute ```mimicertz_x64.exe "crypto::capi" "crypto::certificates /export /store:MY /systemstore:CURRENT_USER" "exit"```
3. PFX certificates will be exported in the current directory
4. Use `mimicertz` as passphrase to import your PFX certificate 
5. Profit


Building your own version
-------------------------
1. Follow the [provided prerequisites](https://github.com/gentilkiwi/mimikatz/#build)
2. Download the `source` folder from this repository
3. Open the `mimikatz.sln` Visual Studio Solution and build it


Changelog
---------
* version 2.1.1 - 23/09/2018: initial commit


Copyright and license
---------------------
The very same of the original [`mimikatz`](https://github.com/gentilkiwi/mimikatz/#licence) project which is **CC BY 4.0 licence**  
Last but not least, antivirus softwares might report these binaries as hacktools or even malwares: this is a known and common issue. If you don't trust this compilation, just don't download it.