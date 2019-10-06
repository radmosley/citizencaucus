# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.shortcuts import render
from django.http import HttpResponse
from .models import Member
from .serializers import MemberSerializers
from rest_framework import generics

# Create your views here.
def index(request):
    name = request.GET.get('first_name')
    return HttpResponse('{}'.format(name))


class MemberList(generics.ListCreateAPIView):
    queryset = Member.objects.all()
    serializer_class = MemberSerializers