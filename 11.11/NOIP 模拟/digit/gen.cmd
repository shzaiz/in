
cls
:start
echo off
set /a RandomNumber= %random%%%10000+1
set /a b= %random%%%10+1
echo %b% %RandomNumber%
echo %b% %RandomNumber%>digit.in
digit
baoli
fc baoli.out digit.out
if not errorlevel 1 goto start
pause
