from django.urls import path
from . import views
from django.conf import settings
from django.conf.urls.static import static
from .models import Senator

urlpatterns = [
    path('', views.pages, name='index'),
    path('search/', views.search_titles, name='search'),
    path('s.last_name' + '-' + 's.first_name' + '/', views.profile, name='profile'),
]
