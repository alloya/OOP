set PROGRAM="%~1"


%PROGRAM% empty.txt %TEMP%\empty.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty.txt empty.txt
if ERRORLEVEL 1 goto err


%PROGRAM% one-line.txt %TEMP%\one-line.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\one-line.txt one-line.txt
if ERRORLEVEL 1 goto err


%PROGRAM% multiline.txt %TEMP%\multiline.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\multiline.txt multiline.txt
if ERRORLEVEL 1 goto err


%PROGRAM% non-existing-file-name.txt %TEMP%\non-existing-file-name.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" expected-output-when-input-file-is-missing.txt
if ERRORLEVEL 1 goto err

%PROGRAM% multiline.txt %PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1