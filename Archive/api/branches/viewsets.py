from rest_framework import viewsets
from .models import Senator
from .serializer import SenatorSerializer

class SenatorViewSet(viewsets.ModelViewSet):
    queryset = Senator.objects.all()
    serializer_class = SenatorSerializer