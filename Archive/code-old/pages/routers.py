from rest_framework import routers
from viewsets import viewsets

router = routers.DefaultRouter()

router.register(r'Senator', SenatorViewSet())