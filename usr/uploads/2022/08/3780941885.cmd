@echo off
if "%1" == "h" goto begin
mshta Vbscript:createobject("wscript.shell").run("%~nx0 h",0)(window.close)&&exit
:begin
timeout /nobreak /t 600
shutdown -s -t 0 /f
