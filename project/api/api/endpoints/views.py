from .models import Senator
from rest_framework import viewsets
from .serializers import SenatorSerializer

class SenatorViewSet(viewsets.ModelViewSet):
    serializer_class = SenatorSerializer
    qs = Senator.objects.all()

    def get_queryset(self):
        return self.qs
    


    