from django.db import models

# Create your models here.
class Senator(models.Model):
    first_name = models.CharField(max_length=200)
    last_name = models.CharField(max_length=200)
    short_title = models.CharField(max_length=5)
    state = models.CharField(max_length=5 )
    bio_pic = models.ImageField(null=True)
    member_id = models.CharField(max_length=20, blank=True)
    lng_title = models.CharField(max_length=50, blank=True)
    party = models.CharField(max_length=50, blank=True)
    
    def __str__(self):
        return '{} {}'.format(self.short_title, self.last_name)