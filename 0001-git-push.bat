@echo off
set GMT=GMT+8
set DATEINTERAL=/
set TIMEINTERAL=:
set SPACE=" "
set ZERO=0
:: 1 获取日期
set THISDATE=%DATE:~0,4%%DATEINTERAL%%DATE:~5,2%%DATEINTERAL%%DATE:~8,2%
:: 2 如果小时是一位数H的话，将其该为0H
set ThISHOUR01=%TIME:~0,1%
if "%ThISHOUR01%" == " "  (
	set ThISHOUR01=%ZERO%%TIME:~1,1%
)else  (
	set ThISHOUR01=%TIME:~0,2%
)
:: 3 修改后的时间串
set ThISTIME=%ThISHOUR01%%TIMEINTERAL%%TIME:~3,2%%TIMEINTERAL%%TIME:~6,2%
:: 4 组合后的日期时间串
set ThISDATETIME=%THISDATE%%SPACE%%ThISTIME%
set RESULT=%ThISDATETIME%
git add .
git commit -m %RESULT%
git push
pause