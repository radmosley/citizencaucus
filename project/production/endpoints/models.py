from django.db import models
from datetime import datetime
from django.utils import timezone
import requests
import pytz

class Senator(models.Model):
    first_name = models.CharField(max_length=200)
    last_name = models.CharField(max_length=200)
    short_title = models.CharField(max_length=5)
    state = models.CharField(max_length=10, blank=True)
    lst_update = models.DateTimeField(default=timezone.now)
    # bio_pic = models.ImageField(null=True)
    member_id = models.CharField(max_length=20,primary_key=True)
    lng_title = models.CharField(max_length=50, blank=True)
    party = models.CharField(max_length=50, blank=True)
    missed_votes_pct = models.FloatField(blank=True)
    votes_with_party_pct = models.FloatField(blank=True)
    contact_url = models.CharField(max_length=200, blank=True, null=True)
    next_election = models.CharField(max_length=200, blank=True, null=True)
    phone_num = models.CharField(max_length=15, blank=True, null=True)
    # party_votes = models.ManytoMany(max_length=200, blank=True, null=True)

    def __str__(self):
        return '{} {}'.format(self.short_title, self.last_name)
    
    # def get_vote(self):
    # tz = pytz.timezone('America/Los_Angeles')
    # difference = tz.localize(datetime.now()) - self.lst_update
    # if difference.total_seconds() > 900:
    #     print('updating')
    #     headers = {'X-API-Key': 'pcDFqM1JDUUtsNyhkf4oE40QUpyC1So2ae4kMMaP'}
    #     v = requests.get('https://api.propublica.org/congress/v1/members/' + self.member_id + '/votes.json', headers=headers)
    #     print()
    #     print(v.text)
    #     print()
    #     data = v.json()
    #     for i in data['results']:
    #         for s in i['votes']:
    #             new, created = Vote.objects.get_or_create (
    #             bill_id = s['bill']['bill_id'], member_id=self,
    #             defaults = { 
    #                 'title' : s['title'],
    #                 'member_id' : s['member_id'],
    #                 'bill_id' : s['bill_id'],
    #                 'vote' : s['position']
    #                 'results': s['results']
    #             }
    #             )
    #             if created:
    #                 print('vote created')
    #                 continue
    #             print('vote updated')
    #     self.lst_update = datetime.now()
    # else: 
    #         print('already updated skipping')

    # def __str__(self):
    #     return '{} {}'.format(self.short_title, self.last_name)


# class Vote(models.Model):
#     title  = models.TextField()
#     member_id = models.ForeignKey(Senator, on_delete=models.CASCADE, related_name="votes")
#     bill_id = models.CharField(max_length=50)
#     # member_title = models.ManyToManyField()
#     vote = models.CharField(max_length=1000)
#     results = models.CharField(max_length=1000)

#     def __str__(self):
#         return '{}'.format(self.title)

# class Party(models.Model):
#     party = models.CharField(max_length=10)
#     senators = models.ForeignKey('Senator', related_name='Senator', on_delete=models.SET('Ind'),)
# #   chair_person = 

