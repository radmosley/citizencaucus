from django.shortcuts import render

from .models import Senator

def pages(request):
    senator = Senator.objects.order_by('?')
    context = {'senator': senator}
    return render(request, 'pages/pages.html', context)