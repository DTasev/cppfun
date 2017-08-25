import sys,os,os.path
sys.path.append(os.path.expanduser('~/code/eol_hsrl_python'))
os.environ['PATH']+='gvhsrl'
print("Post edit",os.environ['PATH']) 
import subprocess
subprocess.Popen("powershell", shell=True)
