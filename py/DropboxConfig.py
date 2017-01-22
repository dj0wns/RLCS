# Include the Dropbox SDK
import dropbox
import sys

# Get your app key and secret from the Dropbox developer website
app_key = 'bh9je1jzc7mheu1'
app_secret = '15x6plk4321q8hi'

flow = dropbox.client.DropboxOAuth2FlowNoRedirect(app_key, app_secret)

# argv[1] is config_file path
if len(sys.argv) >= 2:
	key_found = False

	with open(sys.argv[1], 'r+') as config_file:
		line = config_file.readline()
		while line and not key_found:
			words = line.split()
			if len(words)>=3 and words[0]=="Dropbox" and words[1]=="=":
				key = words[2]
				key_found = True
			else:
				line = config_file.readline()
		if not key_found:
			# Have the user sign in and authorize this token
			authorize_url = flow.start()
			print ('1. Go to: ' + authorize_url)
			print ('2. Click "Allow" (you might have to log in first)')
			print ('3. Copy the authorization code.')
			code = raw_input("Enter the authorization code here: ").strip()
			# This will fail if the user enters an invalid authorization code
			key, user_id = flow.finish(code)
		client = dropbox.client.DropboxClient(key)
		if not key_found:
			# write to config_file
			config_file.write("\nDropbox = " + key)
			key_found = True
		print ('linked account: ', client.account_info())
