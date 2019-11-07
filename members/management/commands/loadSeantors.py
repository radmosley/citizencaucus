from django.core.management.base import BaseCommand, CommandError
from members.models import Member

class Command(BaseCommand):
    help = 'Loades Senator\'s data from Propublica'

    # def add_argumenta(self, parser):
    #     parser.add_argument('', nargs='', type=int)

    def handle(self, *args, **options):
        #Connect to propublica
        print('Connection initiated')

        # Load data into corresponding list
        