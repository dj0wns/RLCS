from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
import sys

gauth = GoogleAuth()

# Create GoogleDrive instance with authenticated GoogleAuth instance.
drive = GoogleDrive(gauth)

if len(sys.argv) >= 3:
	# argv[2] is where to download to
	# argv[3] is file path to download
	file_name = sys.argv[3]
	file_list = drive.ListFile({'q': "title='%s'" % file_name}).GetList()
	
	file1 = drive.CreateFile({'id': file_list[0]['id']})
	file1.GetContentFile(sys.argv[2]+sys.argv[3]) # Download file as

	print('title: %s, id: %s' % (file1['title'], file1['id']))