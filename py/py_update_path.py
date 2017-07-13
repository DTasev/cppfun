import os

mingw_path = '~/test/path'

os.environ['PATH'] = mingw_path + ';' + os.environ['PATH']
print(os.environ['PATH'])