set PROGRAM="%~1" 

echo ----------

echo Expected result: Text not found
echo Actual result: 
%PROGRAM% empty.txt "you"
if ERRORLEVEL 1 goto err 

echo ----------

echo Expected result: Searching text should not be empty
echo Actual result:
%PROGRAM% input.txt ""
if ERRORLEVEL 1 goto err 

echo ----------

%PROGRAM% input.txt "loves" > %TEMP%\output.txt
if ERRORLEVEL 1 goto err 
fc.exe %TEMP%\output.txt first.txt
if ERRORLEVEL 1 goto err

echo ----------

%PROGRAM% input.txt "movie" > %TEMP%\output.txt
if ERRORLEVEL 1 goto err 
fc.exe %TEMP%\output.txt second.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded 
exit 0 

:err 
echo Program testing failed 
exit 1