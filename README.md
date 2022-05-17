# SpoolTrigger
Weaponizing for privileged file writes bugs with `PrintNotify` Service


#### Short Description:
Imre Rad found this technique in the winspool service which can be triggered via clsid`854a20fb-2d44-457d-992f-ef13785d2b51` by any user using OLEView.NET. That service is not running by default and it's running as `NT_AUTHORITY\SYSTEM`. When the service is start, it loads a dll denepdency called `winspool.drv` which dosen't actually exist in the directory `C:\Windows\System32\spool\drivers\x64\3\`. Then, Imre Rad modified the original one `winspool.drv` to reference to `mod-ms-win-core-apiquery-l1-1-0.dll`.Then, mod-ms-win-core-apiquery-l1-1-0.dll which normally doesn't exist has been loaded by `winspool.drv`. After all of this, I just created this poc to get the `NT_AUTHORITY\SYSTEM` shell.

#### Note:
This is not local privilege escalation bug. Just a technique which will help to get nt authority system shell via arb file write bugs such as CVE-2019-1315,CVE-2020-0787 and so on.

#### For testing purposes:
1. **As an administrator**, copy `winspool.drv` and `mod-ms-win-core-apiquery-l1-1-0.dll` to `C:\Windows\System32\spool\drivers\x64\3\`
2. Place all files which included in [/bin/](https://github.com/sailay1996/SpoolTrigger/tree/main/bin) into a same directory. 
3. Then, run powershell `. .\spooltrigger.ps1`.
4. Enjoy a shell as `NT AUTHORITY\SYSTEM`.

![test1](https://github.com/sailay1996/SpoolTrigger/blob/main/SpoolTrigger.jpg)

*by [@404death](https://twitter.com/404death)*

*Thanks to: Imre Rad for his finding.*


Ref: <br>
https://www.tiraniddo.dev/2018/09/finding-interactive-user-com-objects_9.html <br>
https://github.com/irsl/microsoft-diaghub-case-sensitivity-eop-cve
