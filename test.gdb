set pagination off
set logging file gdb.txt
set logging on
b main
commands 1
	print argc
	print /s argv[0]
	print /s argv[1]
	continue
end
b error_cb
commands
bt
continue
end
info breakpoints
r
set logging off
quit
