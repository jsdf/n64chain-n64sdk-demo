set startpath=%cd%
set startdrive=%CD:~0,2%

C:
cd C:\ultra
call setup.bat

%startdrive%
cd %startpath%
@echo "aaaaa"
exew32 make
@echo "aaaaa"
