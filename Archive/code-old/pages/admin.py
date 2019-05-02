from django.contrib import admin

from .models import Senator, Vote

admin.site.register(Senator)
admin.site.register(Vote)