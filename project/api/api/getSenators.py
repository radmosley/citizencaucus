import requests
import json
from django.core.management.base import BaseCommand
from datetime import datetime
# from .artifacts import secrets
from .api.api.endpoints.models import Senator


IMPORT_URL = 'https://api.propublica.org/congress/v1/115/senate/members.json'

def Client():
    api_key = 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'
    headers = {'X-API-Key': api_key}
    
    response = requests.get(
        url = IMPORT_URL,
        headers = headers
    )
    
    print('api connection established')
    response.raise_for_status()
    data = response.json()
    print('Json data loaded')
    
    for data_object in data['results'][0]['members']:
        print(data_object)
        print('.'*100)
        # idnumber = data_object['short_title']
        # first_name = data_object['first_name']
        # last_name = data_object['last_name']
        # senator, created = Senator.objects.update_or_create(
        #     short_title = data_object['short_title'],
        #     first_name = data_object['first_name'],
        #     last_name = data_object['last_name']
        # )


Client()