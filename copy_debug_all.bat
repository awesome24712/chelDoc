@echo off
cls
copy "chelTester\Debug\chelTester.dll" "%CD%"
copy "chelTypes\Debug\chelTypes.dll" "%CD%"
copy "chelMath\Debug\chelMath.dll" "%CD%"
::copy "chelDocBase\Debug\chelDocBase.dll" "%CD%"
copy "chelConsole\Debug\chelConsole.dll" "%CD%"
::copy "chelProjectScanner\Debug\chelProjectScanner.dll" "%CD%"
::copy "chelInterpBase\Debug\chelInterpBase.dll" "%CD%"
::copy "chelWeb\Debug\chelWeb.dll" "%CD%"
::copy "chelInterp\Debug\chelInterp.dll" "%CD%"
::copy "chelDoc\Debug\chelDoc.dll" "%CD%"
::copy "chelTUI\Debug\chelTUI.exe" "%CD%"
copy "chelGUI\Debug\chelGUI.exe" "%CD%"
copy "..\SDL\lib\SDL.dll" "%CD%"
pause
