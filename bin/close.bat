@echo off
rem taskkill /f /im pause.exe /im netchatC.exe
rem taskkill /f /im netchatC.exe /im pause.exe

rem /im：程序名, /f:强制关闭,/t:关闭进程树(netchatC.exe最后调用了pause.exe)
taskkill /im iocp_ex_client.exe /f /t  
     
rem pause