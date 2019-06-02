from rest_framework.response import Response
from .models import Senator
from .serializers import SenatorSerializer
from rest_framework import viewsets

class SenatorViewSet(viewsets.ModelViewSet):
    queryset = Senator.objects.all()
    serializer_class = SenatorSerializer
    


    