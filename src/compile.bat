@ECHO OFF

REM -- mise en place environnement --
if exist environment.bat (
	call environment.bat
) else (
	echo "Missing environment.bat !!"
	goto:eof
)

REM -- creation de la solution Visual --
qmake -tp vc -recursive "QMAKE_CXXFLAGS=/Fd$(IntDir)" %NAME%.pro

REM -- lancement de Visual --
if %EXPRESS%==0 (
	start "Visual Studio" "%VISUALDIR%\Common7\IDE\devenv.exe" %NAME%.sln
) else (
	start "Visual Studio" "%VISUALDIR%\Common7\IDE\VCExpress.exe" %NAME%.sln
)
