from django.shortcuts import render
from django.views.generic import TemplateView
from .models import Senator 
from django.http import JsonResponse, HttpResponse
from django.db.models import Q
from django.template.loader import render_to_string
from django.utils.html import mark_safe


class HomeView(TemplateView):
    pages = "pages/pages.html"

    def get(self, request):
        senator = Senator.objects.all()
        context = {'senator': senator}
        return render(request, self.pages, context)
    
    # def pages(self):
    #     senator = Senator.objects.order_by('?')
    #     context = {'senator': senator}
    #     return render(request, 'pages/pages.html', context)

# class SearchView(BlogListView):
#     """
#     Display a Blog List page filtered by the search query.
#     """
#     paginate_by = 10

#     def get_queryset(self):
#         result = super(SearchView, self).get_queryset()

#         query = self.request.GET.get('q')
#         if query:
#             query_list = query.split()
#             result = result.filter(
#                 reduce(operator.and_,
#                        (Q(title__icontains=q) for q in query_list)) |
#                 reduce(operator.and_,
#                        (Q(content__icontains=q) for q in query_list))
#             )

#         return result



# class MemberLookup(autocomplete.Select2QuerySetView):
#     def get_queryset(self):
#         # Don't forget to filter out results depending on the visitor !
#         qs = Senator.objects.all()

#         if self.q:
#             qs = qs.filter(name__istartswith=self.q)

#         return qs

def profile(request, member_id):
    # x = Senator.objects.get(member_id=member_id)
    senator = Senator.objects.get(member_id=member_id)
    context = {'senator': senator}
    return render(request, 'pages/profile.html', context)


def search_titles(request):
    if request.method == "POST":
        search_text = request.POST['search_text']

    else:
        search_text = ''

    senator_list = Senator.objects.filter(first_name__contains=search_text)
    context = {'senator_list':senator_list}
    return render(request, 'pages/search.html', context)