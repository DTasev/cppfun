import os
from subprocess import Popen, PIPE, STDOUT
username = 'dtasev'
host = 'localhost'

read, write = os.pipe()
os.write(write, "ei2vp_ys3>")
os.close(write)

p = Popen(['ssh', '{0}@{1}'.format(username, host),
           'uname -a'], stdout=PIPE, stdin=read, stderr=STDOUT)

outs, errs = p.communicate()

print("Output:", outs)
print("Error:", errs)
