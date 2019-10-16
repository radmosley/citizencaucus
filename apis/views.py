from django.shortcuts import render
from rest_framework import generics
from  members import models
from .serializers import MemberSerializer

# Create your views here.
class listMembers(generics.ListCreateAPIView):
    queryset = models.Member.objects.all()
    serializer_class = MemberSerializer

class detaillMembers(generics.ListCreateAPIView):
    queryset = models.Member.objects.all()
    serializer_class = MemberSerializer
