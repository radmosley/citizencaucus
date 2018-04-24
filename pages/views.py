from django.shortcuts import render
from django.views.generic import TemplateView
from django.views import generic
from django.core import serializers
from .models import Senator, Vote
from django.http import JsonResponse, HttpResponse
from django import http
from django.db.models import Q
from django.template.loader import render_to_string
from django.utils.html import mark_safe

class HomeView(TemplateView):
    pages = "pages/pages.html"

    def get(self, request):
        senator = Senator.objects.all()
        context = {'senator': senator}
        return render(request, 'pages/pages.html', context)

def profile(request, member_id):
    senator = Senator.objects.get(member_id=member_id)
    votes = senator.votes.all()
    context = {'senator': senator, 'votes': votes}
    return render(request, 'pages/profile.html', context)

def search_titles(request):
    if request.is_ajax():
        search_text = request.POST.get('search_text', 'none').split()

        if len(search_text) > 2:
            senators = Senator.objects.filter(
            Q(first_name__icontains=search_text[0]) | Q(last_name__icontains=search_text[0]) |
            Q(first_name__icontains=search_text[1]) | Q(last_name__icontains=search_text[1])
            )

        else:
            senators = Senator.objects.filter(
            Q(first_name__icontains=search_text[0]) |
            Q(last_name__icontains=search_text[0])
            )

        html = render_to_string("pages/search.html", {'senators': senators})
        return JsonResponse({"message": "Success", 'html': mark_safe(html)})
    return JsonResponse({"message": "error must be post"})