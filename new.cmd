echo off
cls
set /p name="Name is " 
mkdir %name%
xcopy __template__ %name% /S /E /Y