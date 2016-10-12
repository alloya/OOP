set PROGRAM="%~1" 

echo ----------

%PROGRAM% 6 > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt correctnumber.txt
if ERRORLEVEL 1 goto err 

echo ----------

%PROGRAM% > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt invallidArguments.txt
if ERRORLEVEL 1 goto err 

echo ----------

%PROGRAM% 256 > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt incorrectnumber.txt
if ERRORLEVEL 1 goto err 

echo ----------

%PROGRAM% letters > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt letters.txt
if ERRORLEVEL 1 goto err 

echo ----------

echo Program testing succeeded 
exit 0 

:err 
echo Program testing failed 
exit 1