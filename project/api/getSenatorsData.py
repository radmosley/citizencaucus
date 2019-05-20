import json
import requests
import secrets
import psycopg2
import datetime

#database connection
# conn = psycopg2.connect(dbname='postgres', user='postgres', password=secrets.db_password, host='db')
# cur = conn.cursor()
# print('database connected')
## print all records in the senators table
# cur.execute("Select * FROM public.endpoints_senator;")
# records = cur.fetchall()
# print(records)


def client():
        conn = psycopg2.connect(dbname='postgres', user='postgres', password=secrets.db_password, host='db')
        cur = conn.cursor()
        print('database connected')
    #Api credentials
        api_url = 'https://api.propublica.org/congress/v1/115/senate/members.json'
    

    #get response
        res = requests.get(api_url, headers=secrets.headers)

        if (res.ok):
                print('Request accepted loading json')
                data = json.loads(res.content.decode('utf-8'))
                results = data['results'][0]['members']
                print('json loaded')
                for member in results:
                        print('{} {} {} {} {} {} {}'.format(
                                str(member['first_name']), 
                                str(member['last_name']), 
                                str(member['short_title']), 
                                datetime.datetime.now(tz=None), 
                                None,
                                str(member['state']), 
                                str(member['state']), 
                                str(member['id']), 
                                str(member['title']), 
                                str(member['party'])
                        ))
                        insert_query = """INSERT INTO public.endpoints_senator
                        VALUES {}, {}, {}, {}, {}, {}, {}, {}, {}""".format(str(member['first_name']), str(member['last_name']), str(member['short_title']), str(member['state']), datetime.datetime.now(tz=None), None, str(member['id']), str(member['title']), str(member['party']))
                        cur.execute(insert_query)
                        print('member {} created'.format(member['id']))
                # conn.commit()

                # for member in results:
                #         cur.execute(insert_query)
                #         conn.commit()
                #         # print(member['first_name']+ ' ' + member['last_name'])
                #         print('Member {} created'.format(member['id']))

        else:
                print('something went wrong with the request')

client()
