from django.urls import path, include
from endpoints.views import SenatorViewSet
from rest_framework import routers

router = routers.DefaultRouter()
router.register('senators/', SenatorViewSet())

# urlpatterns = [
#     path('senators/', include(router.urls)),
# ]