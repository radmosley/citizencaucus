import requests
import json
import os
import ssl

# if (not os.enviorn.get('PYTHONHTTPSVERIFY', '') and getattr(ssl, '_create_unverified_context', None)):
#     ssl._create_default_https_context = ssl._create_unverified_context

if (not os.environ.get('PYTHONHTTPSVERIFY', '') and getattr(ssl, '_create_unverified_context', None)):
    ssl._create_default_https_context = ssl._create_unverified_context

#Connect to propublica
# senate version
version = 'v1/80/senate/members.json'
# url of api call
base_url = 'https://api.propublica.org/congress/{}/'.format(version)
#api key
api_key = str(os.environ['api_key'])

headers = {
    'X-API-Key': api_key
}


r = requests.get('https://api.propublica.org/congress/v1/80/senate/members.json', headers=headers)

print('Hello world')