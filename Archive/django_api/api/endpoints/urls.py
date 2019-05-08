from django.conf.urls import include, re_path
from rest_framework.routers import DefaultRouter
from .views import CompanyViewSet


router = DefaultRouter()
router.register(company, CompanyViewSet, base_name='company')

urlpatterns = [
    re_path('^', include(router.urls)),
]