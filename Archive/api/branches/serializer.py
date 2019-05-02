from rest_framework import serializers
from .models import Senator

class SenatorSerializer(serializers.ModelSerializer):
    class Meta:
        model = Senator
        fields = '__all__'