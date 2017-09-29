import os
import sys
import shutil

from subprocess import call

assert len(sys.argv) >= 2, "This script must have at least one parameter!"

folder = sys.argv[1]
executable = ["cargo", "new", folder]
if sys.argv[2:]:
    executable.append(sys.argv[2:])
call(executable)

shutil.copy('rls.toml', folder)
shutil.copytree('.vscode', os.path.join(folder, '.vscode'))
