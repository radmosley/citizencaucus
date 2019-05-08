from rest_framework import routers
from branches.viewsets import SenatorViewSet
import sys
sys.path.append("..")

router = routers.DefaultRouter()

router.register(r'senator', SenatorViewSet)