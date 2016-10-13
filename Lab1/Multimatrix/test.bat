set PROGRAM="%~1" 

echo ----------

%PROGRAM% first.txt second.txt > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt multiplied.txt
if ERRORLEVEL 1 goto err 


%PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% first.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded 
exit 0 

:err 
echo Program testing failed 
exit 1