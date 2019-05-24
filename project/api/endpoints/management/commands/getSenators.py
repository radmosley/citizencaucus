from django.core.management.base import BaseCommand
from ...models import Senator

class Command(BaseCommand):
    help = 'Loads Senators data into the database'

    def handle(self, *args, **kwargs):
        self.stdout.write('this command is working')