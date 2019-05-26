from django.core.management.base import BaseCommand
from ...models import Senator
import requests
import json

class Command(BaseCommand):
    help = 'Loads Senators data into the database'
    # URL to import from
    def handle(self, *args, **kwargs):
        import_url = 'https://api.propublica.org/congress/v1/115/senate/members.json' 

        headers = {'X-API-Key': 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'}
        self.stdout.write('API Connected')
        response = requests.get(
        url = import_url,
        headers=headers,
        )
        response.raise_for_status()
        data = response.json()
        self.stdout.write('JSON Loaded')
        for data_object in data['results'][0]['members']:
            s = Senator(
                first_name = data_object['first_name'],
                last_name = data_object['last_name'],
                short_title = data_object['short_title'],
                state = data_object['state'],
                member_id = data_object['id'],
                lng_title = data_object['title'],
                party = data_object['party'],
                missed_votes_pct = data_object['missed_votes_pct'],
                votes_with_party_pct = data_object['votes_with_party_pct'],
                contact_url = data_object['url'],
                next_election = data_object['next_election'],
                phone_num = data_object['phone'],  
            )
            s.save()
            self.stdout.write(data_object['first_name'] + ' ' + data_object['last_name'])
            # s = Senator(
            #     first_name = data_object['first_name'],
            #     last_name = data_object['last_name'],
            #     short_title = data_object['short_title'],
            #     state = data_object['state'],
            #     member_id = data_object['id'],
            #     lng_title = data_object['title'],
            #     party = data_object['party'],
            #     missed_votes_pct = data_object['missed_votes_pct'],
            #     votes_with_party_pct = data_object['votes_with_party_pct'],
            #     contact_url = data_object['url'],
            #     next_election = data_object['next_election'],
            #     phone_num = data_object['phone'],
            #     )
            # s.save()
            # self.stdout.write('Senator {} {} created'.format(s.first_name, s.last_name))