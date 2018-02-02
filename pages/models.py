from django.db import models
from datetime import datetime
import requests
from django.contrib.auth.models import Vote
import pytz

class Senator(models.Model):
    first_name = models.CharField(max_length=200)
    last_name = models.CharField(max_length=200)
    short_title = models.CharField(max_length=5)
    state = models.CharField(max_length=5 )
    lst_update = models.DateTimeField(default=datetime.strptime('01/01/2018', '%M/%d/%Y'))
    bio_pic = models.ImageField(null=True)
    member_id = models.CharField(max_length=20)
    # contact_url = models.CharField(max_length=200 blank=True null=True)
    # next_election = models.CharField(max_length=200 blank=True null=True)
    # phone_num = models.CharField(max_length=15 blank=True null=True)
    # missed_votes_pct = models.CharField(max_length=200 blank=True null=True)
    # party_votes = models.ManytoMany(max_length=200 blank=True null=True)

    def get_vote(self):
        tz = pytz.timezone('America/Los_Angeles')
        difference = tz.localize(datetime.now()) - self.lst_update
        if difference.total_seconds() > 900:
            print('updating')
            headers = {'X-API-Key': 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'}
            v = requests.get('https://api.propublica.org/congress/v1/members/' + self.member_id + '/votes.json', headers=headers)
            print()
            print(v.text)
            print()
            data = v.json()
            for i in data['results']:
                for s in i['votes']:
                    new, created = Vote.objects.get_or_create (
                
                    bill_id = s['bill']['bill_id'], member=self,
                    defaults = { 
                        'descrip' : s['description'],
                        # 'party' : s['party'],
                        'vote' : s['position']
                    }
                    )
                    if created:
                        print('vote created')
                        continue
                    print('vote updated')
            self.lst_update = datetime.now()
        else: 
            print('already updated skipping')

    def __str__(self):
        return '{} {}'.format(self.short_title, self.last_name)

class Vote(models.Model):
    descrip  = models.TextField()
    bill_id = models.CharField(max_length=50)
    member = models.ForeignKey('Senator', on_delete=models.CASCADE, related_name='votes')
    # member_title = models.ManyToManyField()
    vote = models.CharField(max_length=20)

# class Party(models.Model):
#     party = models.CharField(max_length=10)
#     senators = models.ForeignKey('Senator', related_name='Senator', on_delete=models.SET('Ind'),)
# #   chair_person = 

# class Member(models.Model):
#     first_name
#     last_name
#     party =
#     title
#     twitter
#     facebook
#     youtube
#     session

# class Chamber(models.Model):

