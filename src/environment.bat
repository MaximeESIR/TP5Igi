@ECHO OFF
REM ---------------------------------------------------------------------------------------
REM A ADAPTER EN FONCTION DE LA PLATE FORME...
REM ---------------------------------------------------------------------------------------
set QTDIR=C:\Qt\5.15.2\msvc2019_64
set VISUALDIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community
set EXPRESS=0
REM ---------------------------------------------------------------------------------------
REM NE PLUS MODIFIER A PARTIR D'ICI
REM ---------------------------------------------------------------------------------------

REM -- nom solution --
set NAME=TP05

REM -- choix de la version de Visual C++ --
set QMAKESPEC=win32-msvc

REM -- mise en place environnement Visual
pushd "%VISUALDIR%\VC\Auxiliary\Build"
call vcvarsall.bat x64
popd

REM -- mise a jour du PATH pour le lancement des outils appeles par ce script --
set PATH=%QTDIR%\bin;%PATH%

REM -- repertoires de generation --
set ROOT_DIR=%~dp0/..
set SRC_DIR=%ROOT_DIR%/src
set TMP_DIR=%ROOT_DIR%/tmp
set BIN_DEBUG_DIR=%ROOT_DIR%/bin
set BIN_RELEASE_DIR=%ROOT_DIR%/bin