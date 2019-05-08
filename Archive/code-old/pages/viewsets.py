from rest_framework import viewsets
from .models import Senator
from pages.serializers import SenatorsSerializer

class SenatorViewSet(viewsets.ModelViewSet):
    queryset = Senator.objects.all()
    serializer_class = SenatorsSerializer