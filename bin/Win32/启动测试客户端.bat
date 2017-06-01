@echo off

taskkill /f /im test_client.exe
cd test_client
start "" test_client.exe
cd ..



