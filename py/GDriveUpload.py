from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
import sys
import os.path

gauth = GoogleAuth()

# Create GoogleDrive instance with authenticated GoogleAuth instance.
drive = GoogleDrive(gauth)

if len(sys.argv) >= 2:
	# argv[2] is file path to upload
        file1 = drive.CreateFile({'title': os.path.basename(sys.argv[2])})
        file1.SetContentFile(sys.argv[2])
	file1.Upload()
	print('title: %s, id: %s' % (file1['title'], file1['id']))
