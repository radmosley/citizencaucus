from django.urls import path
from .views import listMembers, detaillMembers

urlpatterns = [
    path('', listMembers.as_view()),
    path('<int:pk>/', detaillMembers.as_view())
]