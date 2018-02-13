from .models import Senator
import django_filters

class MemberFilter(django_filters.FilterSet):
    class Meta:
        model = Senator
        fields = ['first_name', 'last_name', 'member_id', 'state' ]