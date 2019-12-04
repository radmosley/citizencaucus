from django.core.management.base import BaseCommand
from ...models import Member

import json

class Command(BaseCommand):
    help = 'populate database with data from a json'

    def handle(self, *args, **kwargs):
        with open('./artifacts/senate_80_data.json') as json_file:
            data = json.load(json_file)
            for obj in data['results'][0]['members']:
                # print(obj['first_name'])
                # print('*' * 20)
                senator = Member(
                    first_name = obj['first_name'],
                    last_name = obj['last_name'],
                    title = obj['title']
                )

                senator.save()
                print('{} {} have been saved'.format(obj['first_name'], obj['last_name']))

                # self.stdout.write('{} loaded'.format(first_name, last_name))