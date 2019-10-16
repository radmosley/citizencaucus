from rest_framework import serializers
from members import models

class MemberSerializer(serializers.ModelSerializer):
    class Meta:
        fields = (
            'first_name',
            'last_name',
            'title',
        )
        model = models.Member