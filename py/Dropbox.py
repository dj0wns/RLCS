# Include the Dropbox SDK
import dropbox

# Get your app key and secret from the Dropbox developer website
app_key = 'bh9je1jzc7mheu1'
app_secret = '15x6plk4321q8hi'

flow = dropbox.client.DropboxOAuth2FlowNoRedirect(app_key, app_secret)


# Have the user sign in and authorize this token
authorize_url = flow.start()
print ('1. Go to: ' + authorize_url)
print ('2. Click "Allow" (you might have to log in first)')
print ('3. Copy the authorization code.')
code = input("Enter the authorization code here: ").strip()

# This will fail if the user enters an invalid authorization code
access_token, user_id = flow.finish(code)

client = dropbox.client.DropboxClient(access_token)
print ('linked account: ', client.account_info())
