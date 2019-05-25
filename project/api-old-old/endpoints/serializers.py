from .models import Senator
from rest_framework import serializers

class SenatorSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Senator
        fields = (
            'first_name',
            'last_name',
            'short_title',
            'state',
            'lst_update',
            'member_id',
            'lng_title',
            'party',
            'missed_votes_pct',
            'votes_with_party_pct',
            'contact_url',
            'next_election',
            'phone_num',
            'party_votes'
            )