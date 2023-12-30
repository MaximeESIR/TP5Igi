@ECHO OFF

REM -- mise en place environnement --
if exist src\environment.bat (
	call src\environment.bat
) else (
	echo "Missing environment.bat !!"
	goto:eof
)

REM -- lancement exe --
bin\ihm.exe
