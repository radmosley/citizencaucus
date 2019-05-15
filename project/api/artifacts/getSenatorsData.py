import json
import requests

#Api credentials
api_url = 'https://api.propublica.org/congress/v1/115/senate/members.json'
api_key = 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'
headers = {'X-API-Key': api_key}

#get response
res = requests.get(api_url, headers=headers)

#Transform response into json format
data = res.json()

#If response is 200 then print the length of the data
if (res.ok):
    print(len(data))
    
#If response is not 200 then print "something went wrong"
else:
    print('something is wrong')
