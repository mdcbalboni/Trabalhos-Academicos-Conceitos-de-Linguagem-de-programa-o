import os
cmd = "make teste"
cmd2="make teste2"
print "PThread"
for i in range(5):
	os.system(cmd)
print " "
print " "
print "OpenMP"
for i in range(5):
	os.system(cmd2)
os.system("make clean")
