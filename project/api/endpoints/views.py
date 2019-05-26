from rest_framework.response import Response
from rest_framework.views import APIView
from .models import Senator
from .serializers import SenatorSerializer

class SenatorView(APIView):
    def get(self, request):
        senators = Senator.objects.all()
        serializer = SenatorSerializer(senators)
        return Response(serializer.data)
    


    