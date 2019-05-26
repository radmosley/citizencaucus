from django.urls import path
from .views import SenatorView

app_name = "api"

urlpatterns = [
    path('senators/', SenatorView.as_view())
]