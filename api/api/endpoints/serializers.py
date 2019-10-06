from rest_framework import serializers
from .models import Member

class MemberSerializers(serializers.ModelSerializer):
    class Meta:
        model = Member
        fields = ('first_name', 'last_name', 'member_id', 'title')