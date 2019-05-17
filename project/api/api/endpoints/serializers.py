from .models import Senator
from rest_framework import serializers

class SenatorSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Senator
        fields = ('first_name','last_name','short_title')