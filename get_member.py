import os

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 

					  'citizencaucus.settings')

import django
import requests

#connect to django project
django.setup()
from pages.models import Senator

#connect to api
headers = {'X-API-Key': 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'}
r = requests.get('https://api.propublica.org/congress/v1/members/A000360.json', headers=headers)

#import data into json format
data = r.json()

#import json data into database cells
# for i in data['results']:
#     for r in i['members']:
#         new = Senator()
#         new.first_name = r['first_name']
#         new.last_name = r['last_name']
#         new.short_title = r['short_title']
#         new.party = r['party']
        # new.contact_url = r['contact_form']
        # new.next_election = r['next_election']
        # new.phone_num = r['phone']
        # new.email = r['email']
        # new.state = r['state']
        # new.missed_vote_pct = r['missed_votes_pct']
        # new.party_votes = r['votes_with_party_pct']

        # new.save()

#function to check for existing senators

#count members
# print(r.json(['results'][0]['members']))

print(r.text)
