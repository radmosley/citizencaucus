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


def get_senators():
    #api call for senators
    print('Starting request...')
    s = requests.get('https://api.propublica.org/congress/v1/115/senate/members.json', headers=headers)
    print('Finished request...')
    #import data into json format
    data = s.json()
    x = 0
    #import json data into database cells
    for i in data['results']:
        x += 1
        print(x)
        for s in i['members']:
            print(s)
            new, created = Senator.objects.update_or_create (
            
                first_name=s['first_name'], last_name=s['last_name'], 

                defaults= { 
                    'short_title' : s['short_title'],
                    # 'party' : s['party'],
                    'member_id' : s['id'],
                    'state' : s['state']
                }

            )
            new.get_vote()
get_senators()
            # new.contact_url = r['contact_form']
            # new.next_election = r['next_election']
            # new.phone_num = r['phone']
            # new.email = r['email']
            # new.missed_vote_pct = r['missed_votes_pct']
            # new.party_votes = r['votes_with_party_pct']

#function to check for existing senators

#count members
# print(r.json(['results'][0]['members']))

# print(r.text)
