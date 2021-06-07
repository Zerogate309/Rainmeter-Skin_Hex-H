[Rainmeter]


[Metadata]
Name=Hex H Suite
Author=Zerogate309
Information=Measures for the Suite
FileVersion=0.6
License=Creative Commons Attribution-Non-Commercial-Share Alike 4.0

; ###### Index Measures ######
; ========== Time ==========
; ========== Date ==========
; ========== Drives ==========
; ========== Network ==========
; ========== WLAN ==========
; ========== Audio ==========
; ========== Mainboard ==========
; ========== CPU ==========
; ========== RAM ==========
; ========== Swap ==========
; ========== Windows ==========
; ========== User ==========
; ========== Binary (Trash)==========
; ========== Screen ==========
; ========== Battery ==========
; ========== Color Transparency ==========
; ========== Currency ==========


; ########## Measures ##########

; ========== Time ==========

[Measure_Time]
Measure=Time

; --- 24 Hours ---
[Measure_Clock_24h]
Measure=Time
Format=%H
; --- 12 Hours ---
[Measure_Clock_12h]
Measure=Time
Format=%#I
; --- Minutes ---
[Measure_Clock_XXm]
Measure=Time
Format=%M
; --- Seconds ---
[Measure_Clock_XXs]
Measure=Time
Format=%S
; --- 24 Hours & Minutes ---
[Measure_Clock_24h_XXm]
Measure=Time
Format=%H:%M
; --- 24 Hours & Minutes & Seconds ---
[Measure_Clock_24h_XXm_XXs]
Measure=Time
Format=%H:%M:%S
; --- 12 Hours & Minutes ---
[Measure_Clock_12h_XXm]
Measure=Time
Format=%I:%M
; --- AM/PM indicator for 12-hour clock ---
[Measure_AM/PM]
Measure=Time
Format=%p
; --- Let the colon twinkle ---
[Measure_Blink]
Measure=Calc
Formula=Measure_Time %2
MaxValue=1
MinValue=0
Substitute="0":"","1":":"

; ========== Date ==========

; --- Full weekday name. (e.g. "Saturday") Local ---
[Measure_Date_Weekday_Local]
Measure=Time
FormatLocale=Local
Format=%A
; --- Day of month as number, zero padded (01 - 31)
[Measure_Date_DD]
Measure=Time
Format=%d
; --- Month as number (01 - 12) ---
[Measure_Date_MM]
Measure=Time
Format=%m
; --- Abbreviated month name. (e.g. "Dec") ---
[Measure_Date_MMM]
Measure=Time
Format=%b
; --- Full month name. (e.g. "December") ---
[Measure_Date_M_Full]
Measure=Time
Format=%B
; --- Year without century (00 - 99) ---
[Measure_Date_JJ]
Measure=Time
Format=%y
; --- Year with century ---
[Measure_Date_JJJJ]
Measure=Time
Format=%Y
; ---Week of year as number, with first Monday as first day of week one. (00 - 53) ---
[Measure_Date_WW]
Measure=Time
Format=%W
; --- Day (01 - 31); Month (e.g. "01 - 12") ---
[Measure_Date_DD_MM]
Measure=Time
Format=%d.%m.
; --- Weekday (Thu) Day (01. - 31.); Month (e.g. "Dec"); in Local Format ---
[Measure_Date_WD_DD_MMM_Local]
Measure=Time
Format=%a %d. %b
FormatLocale=Local
; --- Day (01 - 31); Month (01 - 12); Year (Year with century) ---
[Measure_Date_DD_MM_JJJJ]
Measure=Time
Format=%d.%m.%Y
; --- Day (01 - 31); Month (e.g. "Dec"); Year (00 - 99) in Local Format ---
[Measure_Date_DD_MMM_JJ]
Measure=Time
Format=%d %b %y
FormatLocale=Local
; --- Day (01 - 31); Month (e.g. "Dec"); Year (Year with century) in Local Format ---
[Measure_Date_DD_MMM_JJJJ]
Measure=Time
Format=%d %b %Y
FormatLocale=Local
; --- Day (01 - 31); Month (e.g. "Dec"); Year (00 - 99) in Local Format ---
[Measure_Date_DD_MMM_JJ_Local]
Measure=Time
Format=%d. %b %Y
FormatLocale=Local
; --- Weekday (Thu) Day (01. - 31.); Month (e.g. "Dec"); Year (00 - 99) in Local Format ---
[Measure_Date_WD_DD_MMM_JJJJ_Local]
Measure=Time
Format=%a %d. %b %Y
FormatLocale=Local

; ========== Drives ==========

; ---- Drive_00 (RAM-Drive)----
; ---- Drive_00 Complete Size ----
[Measure_Drive_00_Size]
Measure=FreeDiskSpace
Drive=#Drive_00#:
Total=1
; ---- Drive00 Space Used ----
[Measure_Drive_00_Used]
Measure=FreeDiskSpace
Drive=#Drive_00#:
InvertMeasure=1
UpdateDivider=5
; ---- Drive00 Space Free ----
[Measure_Drive_00_Free]
Measure=FreeDiskSpace
Drive=#Drive_00#:
UpdateDivider=5
; ---- Drive00 Access ----
[Measure_Drive_00_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_00#:

; ---- Drive01 ----
[Measure_Drive_01_Size]
Measure=FreeDiskSpace
Drive=#Drive_01#:
Total=1
IgnoreRemovable=0

[Measure_Drive_01_Used]
Measure=FreeDiskSpace
Drive=#Drive_01#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_01_Free]
Measure=FreeDiskSpace
Drive=#Drive_01#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_01_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_01#:
IgnoreRemovable=0

[Measure_Drive_01_Access1]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=Disk Read Bytes/sec
;Name=C:
Name=#Drive_01#:
IgnoreRemovable=0

[Measure_Drive_01_ReadNumber]
Measure=Calc
Formula=[Measure_Drive_01_Access1:]
;DynamicVariables=1

; ---- Drive_02 ----
[Measure_Drive_02_Size]
Measure=FreeDiskSpace
Drive=#Drive_02#:
Total=1
IgnoreRemovable=0

[Measure_Drive_02_Used]
Measure=FreeDiskSpace
Drive=#Drive_02#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_02_Free]
Measure=FreeDiskSpace
Drive=#Drive_02#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_02_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_02#:
IgnoreRemovable=0

[Measure_Drive_02_Access1]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=Disk Read Bytes/sec
Name=#Drive_02#:
IgnoreRemovable=0

[Measure_Drive_02_ReadNumber]
Measure=Calc
Formula=[Measure_Drive_02_Access1:]
;DynamicVariables=1

; ---- Drive_03 ----
[Measure_Drive_03_Size]
Measure=FreeDiskSpace
Drive=#Drive_03#:
Total=1
IgnoreRemovable=0

[Measure_Drive_03_Used]
Measure=FreeDiskSpace
Drive=#Drive_03#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_03_Free]
Measure=FreeDiskSpace
Drive=#Drive_03#:
UpdateDivider=5

[Measure_Drive_03_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_03#:
IgnoreRemovable=0

; ---- Drive_04 ----
[Measure_Drive_04_Size]
Measure=FreeDiskSpace
Drive=#Drive_04#:
Total=1
IgnoreRemovable=0

[Measure_Drive_04_Used]
Measure=FreeDiskSpace
Drive=#Drive_04#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_04_Free]
Measure=FreeDiskSpace
Drive=#Drive_04#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_04_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_04#:
IgnoreRemovable=0

; ---- Drive_05 ----
[Measure_Drive_05_Size]
Measure=FreeDiskSpace
Drive=#Drive_05#:
Total=1
IgnoreRemovable=0

[Measure_Drive_05_Used]
Measure=FreeDiskSpace
Drive=#Drive_05#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_05_Free]
Measure=FreeDiskSpace
Drive=#Drive_05#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_05_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_05#:
IgnoreRemovable=0

; ---- Drive_06 ----
[Measure_Drive_06_Size]
Measure=FreeDiskSpace
Drive=#Drive_06#:
Total=1
IgnoreRemovable=0

[Measure_Drive_06_Used]
Measure=FreeDiskSpace
Drive=#Drive_06#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_06_Free]
Measure=FreeDiskSpace
Drive=#Drive_06#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_06_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_06#:
IgnoreRemovable=0

; ---- Drive_07 ----
[Measure_Drive_07_Size]
Measure=FreeDiskSpace
Drive=#Drive_07#:
Total=1
IgnoreRemovable=0

[Measure_Drive_07_Used]
Measure=FreeDiskSpace
Drive=#Drive_07#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_07_Free]
Measure=FreeDiskSpace
Drive=#Drive_07#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_07_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_07#:
IgnoreRemovable=0

; ---- Drive_08 ----
[Measure_Drive_08_Size]
Measure=FreeDiskSpace
Drive=#Drive_08#:
Total=1
IgnoreRemovable=0

[Measure_Drive_08_Used]
Measure=FreeDiskSpace
Drive=#Drive_08#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_08_Free]
Measure=FreeDiskSpace
Drive=#Drive_08#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_08_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_08#:
IgnoreRemovable=0

; ---- Drive_09 ----
[Measure_Drive_09_Size]
Measure=FreeDiskSpace
Drive=#Drive_09#:
Total=1
IgnoreRemovable=0

[Measure_Drive_09_Used]
Measure=FreeDiskSpace
Drive=#Drive_09#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_09_Free]
Measure=FreeDiskSpace
Drive=#Drive_09#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_09_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_09#:
IgnoreRemovable=0

; ---- Drive_10 ----
[Measure_Drive_10_Size]
Measure=FreeDiskSpace
Drive=#Drive_10#:
Total=1
IgnoreRemovable=0

[Measure_Drive_10_Used]
Measure=FreeDiskSpace
Drive=#Drive_10#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_10_Free]
Measure=FreeDiskSpace
Drive=#Drive_10#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_10_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_10#:
IgnoreRemovable=0

; ---- Drive_11 ----
[Measure_Drive_11_Size]
Measure=FreeDiskSpace
Drive=#Drive_11#:
Total=1
IgnoreRemovable=0

[Measure_Drive_11_Used]
Measure=FreeDiskSpace
Drive=#Drive_11#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_11_Free]
Measure=FreeDiskSpace
Drive=#Drive_11#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_11_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_11#:
IgnoreRemovable=0

; ---- Drive_12 ----
[Measure_Drive_12_Size]
Measure=FreeDiskSpace
Drive=#Drive_12#:
Total=1
IgnoreRemovable=0

[Measure_Drive_12_Used]
Measure=FreeDiskSpace
Drive=#Drive_12#:
InvertMeasure=1
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_12_Free]
Measure=FreeDiskSpace
Drive=#Drive_12#:
UpdateDivider=5
IgnoreRemovable=0

[Measure_Drive_12_Access]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Bytes/sec"
PerfMonInstance=#Drive_12#:
IgnoreRemovable=0

; ========== Network ==========
; ---- LAN Connectivity ----
[Measure_LAN_Connectivity]
Measure=Plugin
Plugin=SysInfo
SysInfoType=LAN_CONNECTIVITY
; ---- Internet Connectivity ----
[Measure_INTERNET_Connectivity]
Measure=Plugin
Plugin=SysInfo
SysInfoType=INTERNET_CONNECTIVITY
; ---- Uploadspeed Main Connection ----
[Measure_UL]
Measure=Netout
Interface=Best
; ---- Downloadspeed Main Connection ----
[Measure_DL]
Measure=NetIn
Interface=Best
; ---- Connection Host Name ----
[Measure_HOST_NAME]
Measure=Plugin
Plugin=SysInfo
SysInfoType=HOST_NAME
; ---- Connection Domain Name ----
[Measure_DOMAIN_NAME]
Measure=Plugin
Plugin=SysInfo
SysInfoType=DOMAIN_NAME
; ---- Connection Domain or WORKGROUP Name ----
[Measure_DOMAIN_WORKGROUP]
Measure=Plugin
Plugin=SysInfo
SysInfoType=DOMAINWORKGROUP
; ---- Connection DNS Server ----
[Measure_DNS_SERVER]
Measure=Plugin
Plugin=SysInfo
SysInfoType=DNS_SERVER
; ---- Connection Net Mask ----
[Measure_NET_MASK]
Measure=Plugin
Plugin=SysInfo
SysInfoType=NET_MASK
; ---- Connection Your IP Address ----
[Measure_IP_ADDRESS]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
; ---- Connection Gateway Address ----
[Measure_GATEWAY_ADDRESS]
Measure=Plugin
Plugin=SysInfo
SysInfoType=GATEWAY_ADDRESS

[Measure_LAN_CONNECTIVITY]
Measure=Plugin
Plugin=SysInfo
SysInfoType=LAN_CONNECTIVITY

[Measure_INTERNET_CONNECTIVITY]
Measure=Plugin
Plugin=SysInfo
SysInfoType=INTERNET_CONNECTIVITY
; ---- Ping Address ----
[Measure_Ping]
Measure=Plugin
Plugin=PingPlugin
DestAddress=#Ping#


; ====== WLAN ======

[Measure_SSID]
Measure=Plugin
Plugin=WiFiStatus
WiFiIntfID=0
WiFiInfoType=SSID
WiFiListStyle=3
; ---- WiFi Top 4 Networks ----
[Measure_Networks]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=LIST
WiFiIntfID=0
WiFiListStyle=0
WiFiListLimit=4

[Measure_PHY]
Measure=Plugin
Plugin=WiFiStatus
WiFiIntfID=0
WiFiInfoType=PHY

[Measure_Encryption]
Measure=Plugin
Plugin=WiFiStatus
WiFiIntfID=0
WiFiInfoType=Encryption

[Measure_AUTH]
Measure=Plugin
Plugin=WiFiStatus
WiFiIntfID=0
WiFiInfoType=AUTH

[Measure_WiFi_Quality]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=Quality
WiFiIntfID=0
IfCondition=((Measure_WiFi_Quality <=14))
IfTrueAction=[!SetOption "Meter_Wifi_Quality" "ImageName" "#@#Icons\Icon-Signal_0.png"]
IfCondition2=((Measure_WiFi_Quality >=25) && (Measure_WiFi_Quality <=34))
IfTrueAction2=[!SetOption "Meter_Wifi_Quality" "ImageName" "#@#Images\Icon-Signal_1.png"]
IfCondition3=((Measure_WiFi_Quality >=35) && (Measure_WiFi_Quality <=44))
IfTrueAction3=[!SetOption "Meter_Wifi_Quality" "ImageName" "#@#Images\Icon-Signal_2.png"]
IfCondition4=((Measure_WiFi_Quality >=45) && (Measure_WiFi_Quality <=64))
IfTrueAction4=[!SetOption "Meter_Wifi_Quality" "ImageName" "#@#Icons\Icon-Signal_3.png"]
IfCondition5=((Measure_WiFi_Quality >=65) && (Measure_WiFi_Quality <=89))
IfTrueAction5=[!SetOption "Meter_Wifi_Quality" "ImageName" "#@#Icons\Icon-Signal_4.png"]
IfCondition6=((Measure_WiFi_Quality >= 90))
IfTrueAction6=[!SetOption "Meter_Wifi_Quality" "ImageName" "#@#Icons\Icon-Signal_5.png"]
DynamicVariables=1

; ========== Audio ==========
; ---- System Volume ----
[Measure_Volume]
Measure=Plugin
Plugin=Win7AudioPlugin
; ---- System Volume in Percent ----
[Volume_Percentage]
Measure=Calc
Formula=(Measure_Volume+1-1)
MinValue=0
MaxValue=100
; ---- Media Player ----
[Measure_Player]
Measure=NowPlaying
PlayerName=#PlayerName#
;PlayerName=foobar2000
;PlayerName=iTunes
PlayerType=Genre
DisableLeadingZero=1
TrackChangeAction=!SetVariable reset 0

[Measure_Player_Volume]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Volume

[Measure_Player_State]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=State
Substitute="0":"#@#\Icons\Icon-Play.png","1":"#@#\Icons\Icon-Pause.png","2":"#@#\Icons\Icon-Play.png"

[Measure_Radio_Player_State]
Measure=NowPlaying
PlayerName=CAD
PlayerType=State
Substitute="0":"#@#\Icons\Icon-Play.png","1":"#@#\Icons\Icon-Pause.png","2":"#@#\Icons\Icon-Play.png"

[Measure_Title]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Title

[Measure_Artist]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Artist

[Measure_Album]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Album

[Measure_TrackNumber]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Number
Substitute="":"N/A"

[Measure_Cover]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Cover
Substitute="":"#@#\Icons\No_Cover.png"

[Measure_Rating]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Rating

[Measure_Genre]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Genre

; ---- Song Position ----
[Measure_Song_Position]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Position

[Measure_Song_Duration]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Duration

[Measure_Song_Progress]
Measure=NowPlaying
PlayerName=[Measure_Player]
PlayerType=Progress


; ---- Spectrum Visualizer ----

[Measure_Audio]
Measure=Plugin
Plugin=AudioLevel
Port=Output
Type=DeviceName
FFTSize=1024
FFTAttack=15
FFTDecay=250
Bands=10
RMSAttack=100
RMSDecay=300
RMSGain=2.0

; --- Stereo Level ---
[Measure_Audio_L]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Channel=L
Type=RMS

[Measure_Audio_R]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Channel=R
Type=RMS

; --- Band Visualization ---
[Measure_Band_0]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=0


[Measure_Band_1]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=1

[Measure_Band_2]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=2

[Measure_Band_3]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=3

[Measure_Band_4]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=4

[Measure_Band_5]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=5

[Measure_Band_6]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=6

[Measure_Band_7]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=7

[Measure_Band_8]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=8

[Measure_Band_9]
Measure=Plugin
Plugin=AudioLevel
Parent=Measure_Audio
Type=Band
BandIdx=9


; ========== Mainboard ==========

[Measure_BoardManufacturer]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\BIOS\
RegValue=BaseBoardManufacturer
UpdateDivider=3000

[Measure_Board]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\BIOS\
RegValue=BaseBoardProduct
UpdateDivider=3000

; ========== CPU ==========

[Measure_CPU]
Measure=CPU

[Measure_CPU_Name]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
UpdateDivider=3000

[Measure_CPU_Identifier]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=Identifier
UpdateDivider=3000

; xxx Ersetzen mit Measure_CPUCore0Usage
[Measure_CPU1]
Measure=Plugin
Plugin=UsageMonitor
Alias=CPU
Index=0

[Measure_CPU_Core_0_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=0
MinValue=0
MaxValue=100

[Measure_CPU_Core_1_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=1
MinValue=0
MaxValue=100

[Measure_CPU_Core_2_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=2
MinValue=0
MaxValue=100

[Measure_CPU_Core_3_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=3
MinValue=0
MaxValue=100

[Measure_CPU_Core_4_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=4
MinValue=0
MaxValue=100

[Measure_CPU_Core_5_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=5
MinValue=0
MaxValue=100

[Measure_CPU_Core_6_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=6
MinValue=0
MaxValue=100

[Measure_CPU_Core_7_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=7
MinValue=0
MaxValue=100

[Measure_CPU_Core_8_Usage]
Measure=Plugin
Plugin=UsageMonitor
Category=Processor
Counter=% Processor Time
Index=8
MinValue=0
MaxValue=100

; ========== RAM ==========

[Measure_RAM_Total]
Measure=PhysicalMemory
Total=1
UpdateDivider=3600

[Measure_RAM_Used]
Measure=PhysicalMemory
UpdateDivider=2

[Measure_RAM_Free]
Measure=PhysicalMemory
InvertMeasure=1
UpdateDivider=2

; ========== Swap ==========

[Measure_SWAP_Total]
Measure=SwapMemory
Total=1
MaxValue=100

[Measure_SWAP_Used]
Measure=SwapMemory
MaxValue=100

[Measure_SWAP_Free]
Measure=SwapMemory
InvertMeasure=1

; ========== Windows ==========

[Measure_WinVersion] ;[WINDOWS VERSION]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=ProductName
UpdateDivider=3000

[Measure_WinReleaseId] ;[WINDOWS ReleaseId NUMBER]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=ReleaseId
UpdateDivider=3000

[Measure_WinBuild] ;[WINDOWS BUILD NUMBER]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=CurrentBuild
UpdateDivider=3000

[Measure_OS_BITS] ;[WINDOWS Bits]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_BITS

; ========== User ==========

[Measure_USER_NAME]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME

[Measure_User_Logon_Time]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_LOGONTIME
UpdateDivider=-1

[Measure_User_UpTime]
Measure=UpTime
SecondsValue=([Measure_Time:] - [Measure_User_Logon_Time:])
Format="%4!i!d %3!i!h %2!i!m"
DynamicVariables=1

; ========== Binary (Trash)==========

[Measure_Bin_Count]
Measure=RecycleManager
Drives=ALL
RecycleType=Count
Updatedivider=1
MinValue=0
MaxValue=500

[Measure_Bin_Size]
Measure=RecycleManager
Drives=ALL
RecycleType=Size
UpdateDivider=5
;MinValue=0
;MaxValue=500

; ========== Screen ==========

[Measure_Screen_Width_1]
Measure=Plugin
Plugin=SysInfo
SysInfoType=SCREEN_WIDTH
SysInfoData=1				; ### Number of the Monitor in System ###

[Measure_Screen_Height_1]
Measure=Plugin
Plugin=SysInfo
SysInfoType=SCREEN_HEIGHT
SysInfoData=1				; ### Number of the Monitor in System ###

[Measure_Screen_Width_2]
Measure=Plugin
Plugin=SysInfo
SysInfoType=SCREEN_WIDTH
SysInfoData=2	    		; ### Number of the Monitor in System ###

[Measure_Screen_Height_2]
Measure=Plugin
Plugin=SysInfo
SysInfoType=SCREEN_HEIGHT
SysInfoData=2				; ### Number of the Monitor in System ###

[Measure_Screen_Width_3]
Measure=Plugin
Plugin=SysInfo
SysInfoType=SCREEN_WIDTH
SysInfoData=3		    	; ### Number of the Monitor in System ###

[Measure_Screen_Height_3]
Measure=Plugin
Plugin=SysInfo
SysInfoType=SCREEN_HEIGHT
SysInfoData=3				; ### Number of the Monitor in System ###

; ========== Battery ==========

; --- Battery lifetime as a percentage ---
[Measure_Battery_Percent]     
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent
IfCondition=((Measure_Battery_Percent <=14))
IfTrueAction=[!SetOption "Icon_Battery_Percent" ImageName "#@#Icons\Icon-Battery_6.png"][!SetOption "Icon_Battery_Percent" ImageTint #ColorLow#][!Redraw]
IfCondition2=((Measure_Battery_Percent >=15) && (Measure_Battery_Percent <=34))
IfTrueAction2=[!SetOption "Icon_Battery_Percent" ImageName "#@#Icons\Icon-Battery_1.png"];[!Redraw]
IfCondition3=((Measure_Battery_Percent >=35) && (Measure_Battery_Percent <=54))
IfTrueAction3=[!SetOption "Icon_Battery_Percent" ImageName "#@#Icons\Icon-Battery_2.png"];[!Redraw]
IfCondition4=((Measure_Battery_Percent >=55) && (Measure_Battery_Percent <=74))
IfTrueAction4=[!SetOption "Icon_Battery_Percent" ImageName "#@#Icons\Icon-Battery_3.png"];[!Redraw]
IfCondition5=((Measure_Battery_Percent >=75) && (Measure_Battery_Percent <=89))
IfTrueAction5=[!SetOption "Icon_Battery_Percent" ImageName "#@#Icons\Icon-Battery_4.png"];[!Redraw]
IfCondition6=((Measure_Battery_Percent >= 90))
IfTrueAction6=[!SetOption "Icon_Battery_Percent" ImageName "#@#Icons\Icon-Battery_5.png"];[!Redraw]

[Measure_Battery_ACLine]
Measure=Plugin
Plugin=PowerPlugin
PowerState=ACLine
; --- for using battery ---
IfCondition=(Measure_Battery_ACLine = 0)
IfTrueAction=[!SetOption "Icon_Battery_ACLine" ImageName "#@#Icons\Icon-Battery_0.png"][!SetOption "Icon_Battery_ACLine" ImageTint "#Color3#,#Color3Alpha#"][!Redraw]
; --- when plugged in ---
IfCondition2=(Measure_Battery_ACLine = 1)
IfTrueAction2=[!SetOption "Icon_Battery_ACLine" ImageName "#@#Icons\Icon-Battery_7.png"][!SetOption "Icon_Battery_ACLine" ImageTint "#Color3#,#Color3Alpha#"][!Redraw]

[Measure_Battery_Status]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Status
; --- for no battery ---
IfCondition=(Measure_Battery_Status = 0)
IfTrueAction=[!SetOption "Icon_Battery_Status" ImageName "#@#Icons\Icon-Battery_0.png"][!SetOption "Icon_Battery_Status" ImageTint "#Color4#,#Color4Alpha#"];[!Redraw]
; --- for charging ---
IfCondition2=(Measure_Battery_Status = 1)
IfTrueAction2=[!SetOption "Icon_Battery_Status" ImageName "#@#Icons\Icon-Battery_7.png"][!SetOption "Icon_Battery_Status" ImageTint "#ColorHigh#"];[!Redraw]
; --- for critical ---
IfCondition3=(Measure_Battery_Status = 2)
IfTrueAction3=[!SetOption "Icon_Battery_Status" ImageName "#@#Icons\Icon-Battery_6.png"][!SetOption "Icon_Battery_Status" ImageTint "#ColorLow#"];[!Redraw]
; --- for low ---
IfCondition4=(Measure_Battery_Status = 3)
IfTrueAction4=[!SetOption "Icon_Battery_Status" ImageName "#@#Icons\Icon-Battery_0.png"][!SetOption "Icon_Battery_Status" ImageTint "#ColorLow#"];[!Redraw]
; --- for above low ---
IfCondition5=(Measure_Battery_Status = 4)
IfTrueAction5=[!SetOption "Icon_Battery_Status" ImageName "#@#Icons\Icon-Battery_0.png"][!SetOption "Icon_Battery_Status" ImageTint "#Color4#,0"];[!Redraw]
IfMatchMode=1

[Measure_Battery_Lifetime]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Lifetime


; ========== Color Transparency ==========
[Measure_Transparency_Color_1]
Measure=String
String=#Color1Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_2]
Measure=String
String=#Color2Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_3]
Measure=String
String=#Color3Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_4]
Measure=String
String=#Color4Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_5]
Measure=String
String=#Color5Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_6]
Measure=String
String=#Color6Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_7]
Measure=String
String=#Color7Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_8]
Measure=String
String=#Color8Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_9]
Measure=String
String=#Color9Alpha#
MinValue=0
MaxValue=255

[Measure_Transparency_Color_B]
Measure=String
String=#ColorBAlpha#
MinValue=0
MaxValue=255

