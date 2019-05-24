# import json
# import requests
# import secrets
# import psycopg2
# import datetime

# #database connection
# # conn = psycopg2.connect(dbname='postgres', user='postgres', password=secrets.db_password, host='db')
# # cur = conn.cursor()
# # print('database connected')
# ## print all records in the senators table
# # cur.execute("Select * FROM public.endpoints_senator;")
# # records = cur.fetchall()
# # print(records)


# def client():
#         conn = psycopg2.connect(dbname='postgres', user='postgres', password='P4ssword', host='db')
#         cur = conn.cursor()
#         print('database connected')
#     #Api credentials
#         api_url = 'https://api.propublica.org/congress/v1/115/senate/members.json'
    

#     #get response
#         res = requests.get(api_url, headers={'X-API-Key': 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'})

#         if (res.ok):
#                 print('Request accepted loading json')
#                 data = json.loads(res.content.decode('utf-8'))
#                 results = data['results'][0]['members']
#                 print('json loaded')
#                 for member in results:
#                         print('{} {} {} {} {} {} {}'.format(
#                                 str(member['first_name']), 
#                                 str(member['last_name']), 
#                                 str(member['short_title']), 
#                                 datetime.datetime.now(tz=None), 
#                                 None,
#                                 str(member['state']), 
#                                 str(member['id']), 
#                                 # str(member['title']), 
#                                 str(member['party'])
#                         ))

#                         # (first_name, last_name, short_title, state, member_id, lng_title, party)
#                         insert_query = "INSERT INTO endpoints_senator (first_name, last_name) VALUES ({}, {})".format(member['first_name'], member['last_name'])
#                         print(insert_query)
#                         cur.execute(insert_query)
#                         conn.commit()
#                         print('member {} created'.format(member['id']))
#                 # conn.commit()

#                 # for member in results:
#                 #         cur.execute(insert_query)
#                 #         conn.commit()
#                 #         # print(member['first_name']+ ' ' + member['last_name'])
#                 #         print('Member {} created'.format(member['id']))

#         else:
#                 print('something went wrong with the request')

# client()

"""
Import json data from URL to Datababse
"""
import requests
import json
from api.endpoints.models import Senator #Import your model here
from django.core.management.base import BaseCommand
from datetime import datetime
 
IMPORT_URL = 'https://api.propublica.org/congress/v1/115/senate/members.json' # URL to import from
 
class Command(BaseCommand):
        def import_senator(self, data):
                first_name = data.get(member['first_name'])
                last_name = data.get(member['last_name']);
                short_title = data.get(member['short_title'])
                try: #try and catch for saving the objects
                        senator, created = Senator.objects.get_or_create(
                        first_name = first_name,
                        last_name = last_name,
                        short_title = short_title
                        )
                        if created:
                                senator.save()
                                display_format = "\nMovie, {}, has been saved."
                                print(display_format.format(movie))
                except Exception as ex:
                        print(str(ex))
                        msg = "\n\nSomething went wrong saving this movie: {}\n{}".format(title, str(ex))
                        print(msg)

        def handle(self, *args, **options):
"""
Makes a GET request to the API.
"""
                headers = {'X-API-Key:': 'application/json'}
                response = requests.get(
                url=IMPORT_URL,
                headers=headers,
                )
                response.raise_for_status()
                data = response.json()
                for data_object in data:
                self.import_movie(data_object)