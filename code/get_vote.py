import os

os.environ.setdefault('DJANGO_SETTINGS_MODULE',

                      'citizencaucus.settings')

import django
import requests

# connect to django project
django.setup()
from pages.models import Senator, Vote

# connect to api


def get_vote(sen):
    print('updating')
    headers = {'X-API-Key': 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'}
    v = requests.get('https://api.propublica.org/congress/v1/members/' +
                     sen.member_id + '/votes.json', headers=headers)

    print()
    print(v.text)
    print()
    # import data into json format
    data = v.json()
    for i in data['results']:
        for s in i['votes']:
            print(s['bill'])
            if s['bill']['title'] and s['bill']['bill_id'] and s['position'] and s['result']:
                new, created = Vote.objects.update_or_create(
                        bill_id=s['bill']['bill_id'], member_id=sen,

                        defaults={
                        'title': s['bill']['title'],
                        'bill_id': s['bill']['bill_id'],
                        'vote': s['position'],
                        'results': s['result']
                        }
                )
                if created:
                        print('vote created')
                        continue
                else:
                        print('already updated skipping')


for i in Senator.objects.all():
    get_vote(i)
