from django.shortcuts import render
from .models import Senator 
from django.http import JsonResponse
from django.db.models import Q
from django.template.loader import render_to_string
from django.utils.html import mark_safe

def pages(request):
    senator = Senator.objects.order_by('?')
    context = {'senator': senator}
    return render(request, 'pages/pages.html', context)

def search_titles(request):
    if request.method == 'POST':
        search_text = request.POST.get('search_text', '')
        senators = Senator.objects.filter(Q(first_name__contains=search_text)|Q(last_name__contains=search_text))
        html = render_to_string("pages/search.html", {'senators': senators})
        return JsonResponse({"message": "Success", 'html': mark_safe(html)})
    return JsonResponse({"message": "error must be post"})

def profile(request, first_name, last_name):
    return render(request, 'pages/profile.html')
