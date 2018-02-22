import os

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 

					  'citizencaucus.settings')

import django
import requests

#connect to django project
django.setup()
from pages.models import Senator

# connect to api
headers = {'X-API-Key': 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'}


def get_senators():
#     #api call for senators
    print('Starting request...')
    s = requests.get('https://api.propublica.org/congress/v1/115/senate/members.json', headers=headers)
    print('Finished request...')
#   #import data into json format
    data = s.json()
    x = 0
#     print(s.json)
    #import json data into database cells
    for i in data['results']:
        x += 1
        # print(x)
        for s in i['members']:
            # print(s['first_name'])
            new, created = Senator.objects.update_or_create (
            
                first_name=s['first_name'], last_name=s['last_name'], 

                defaults= { 
                    'lng_title' : s['title'],
                    'party' : s['party'],
                    # 'missed_votes_pct' : s['missed_votes_pct'],
                    # 'votes_with_party_pct' : s['votes_with_party_pct']
                }

            )
    new.save()


#             new.get_vote()
# get_senators()
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

get_senators()