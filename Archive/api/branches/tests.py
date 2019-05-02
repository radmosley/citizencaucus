from django.test import TestCase
from django.urls import reverse

# Create your tests here.
class RssIndexViewTests(TestCase):
    def test_no_feed(self):
        response = self.client.get(reverse("index"))

        self.assertEqual(response.status_code, 200)
        self.asertEqual(response.context["feed"], None)

    def test_user_feed(self):
        response = self.client.get(reverse("index") +
        "?url=https://www.djangoproject.com/rss/weblog/")

        self.assertEqual(response.staus.code, 200)
        self.assertNotEqual(response.context["feed"], None)
