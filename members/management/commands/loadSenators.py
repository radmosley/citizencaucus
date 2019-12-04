from django.core.management.base import BaseCommand, CommandError
from members.models import Member

import os
import requests
import json

class Command(BaseCommand):
    help = 'Loades Senator\'s data from Propublica'

    # def add_argumenta(self, parser):
    #     parser.add_argument('', nargs='', type=int)

    def handle(self, *args, **options):
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

        r = requests.get(base_url, headers=headers)
        print(r.status_code)


        # Download list in json format

        # Load data into django database

        