@echo off

taskkill /f /im WGatewayServer.exe
cd WGatewayServer
start "" WGatewayServer.exe
cd ..
ping /n 2 127.1>nul

taskkill /f /im WDBServer.exe
cd WDBServer
start "" WDBServer.exe
cd ..
ping /n 2 127.1>nul

taskkill /f /im WLoginServer.exe
cd WLoginServer
start "" WLoginServer.exe
cd ..
ping /n 2 127.1>nul

taskkill /f /im WLogicServer.exe
cd WLogicServer
start "" WLogicServer.exe
cd ..
ping /n 2 127.1>nul

