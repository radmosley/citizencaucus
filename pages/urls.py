from django.urls import path
from .views import HomeView, profile, search_titles
from django.conf import settings
from django.conf.urls.static import static
from .models import Senator

urlpatterns = [
    path('', HomeView.as_view(), name='index'),
    path('search/', search_titles, name='search'),
    # path('search/', SenatorView.as_view(), name='search'),
    path('<slug:member_id>/', profile, name='profile'),
]