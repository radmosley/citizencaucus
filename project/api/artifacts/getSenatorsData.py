import json
import requests

#Get Senators by chamber and 
api_url = 'https://api.propublica.org/congress/v1/115/senate/members.json'
api_key = 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'
# congress = Congress(api_key)
headers = {'X-API-Key': api_key}
res = requests.get(api_url, headers=headers)
data = res.json()
if (res.ok):
    print(len(data))
else:
    print('something is wrong')
