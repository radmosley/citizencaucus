from rest_framework import serializers
from .models import Senator
from rest_framework.renderers import JSONRenderer

class SenatorSerializer(serializers.ModelSerializer):

    class Meta:
        model = Senator
        fields = (
            'first_name',
            'last_name',
            'short_title',
            'state',
            'member_id',
            'lng_title',
            'party',
            'missed_votes_pct',
            'votes_with_party_pct',
            'contact_url',
            'next_election',
            'phone_num'
        )
# serializer = SenatorSerializer()
# print(repr(serializer))
# serializer = SenatorSerializer(Senator)
# serializer.data
# json = JSONRenderer().render(serializer.data)
# json