from rest_framework.response import Response
from rest_framework.views import APIView
from .models import Senator

class SenatorView(APIView):
    def get(self, request):
        senators = Senator.objects.all()
        return Response({"senators": senators})
    


    