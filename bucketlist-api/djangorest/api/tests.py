from django.test import TestCase
from django.contrib.auth.models import User
from rest_framework import status
from rest_framework.reverse import reverse as api_reverse
from rest_framework.test import APIClient

from .models import Bucketlist


class ModelTestCase(TestCase):
    """
    This class defines the test suite for
    the bucketlist model.
    """

    def setUp(self):
        """
        Define the test client and other test variables.
        """
        user = User.objects.create(username="nerd")
        self.bucketlist_name = "Write world class code"
        self.bucketlist = Bucketlist(name=self.bucketlist_name, owner=user)

    def test_model_can_create_a_bucketlist(self):
        """
        Test the bucketlist model can create a
        bucketlist.
        """
        old_count = Bucketlist.objects.count()
        self.bucketlist.save()
        new_count = Bucketlist.objects.count()
        self.assertNotEqual(old_count, new_count)


class ViewTestCase(TestCase):
    """
    Test suite for the api views.
    """

    def setUp(self):
        """
        Define the test client and other test
        variables.
        """
        user = User.objects.create(username="nerd")
        self.client = APIClient()
        self.client.force_authenticate(user=user)
        self.bucketlist_data = {'name': 'Go to Ibiza'}
        self.response = self.client.post(
            api_reverse('create'),
            self.bucketlist_data,
            format='json'
        )

    def test_api_can_create_a_bucketlist(self):
        """
        Test the api has bucket creation capability
        """
        self.assertEqual(self.response.status_code, status.HTTP_201_CREATED)

    def test_authorization_is_enforced(self):
        """
        Test that the api has user authorization
        """
        new_client = APIClient()
        response = new_client.get('/bucketlists/', kwargs={'pk': 3}, format="json")
        self.assertEqual(response.status_code, status.HTTP_401_UNAUTHORIZED)

    def test_api_can_get_a_bucketlist(self):
        """
        Test the api can get a given bucketlist.
        """
        bucketlist = Bucketlist.objects.get()
        response = self.client.get(
            api_reverse('details',
                        kwargs={'pk': bucketlist.id}),
            format='json'
        )
        self.assertEqual(response.status_code, status.HTTP_200_OK)
        self.assertContains(response, bucketlist)

    def test_api_can_update_bucketlist(self):
        """
        Test the api can update a given bucketlist.
        """
        bucketlist = Bucketlist.objects.get()
        change_bucketlist = {'name': 'Something new'}
        response = self.client.put(
            api_reverse('details', kwargs={'pk': bucketlist.id}),
            change_bucketlist, format='json'
        )
        self.assertEqual(response.status_code, status.HTTP_200_OK)

    def test_api_can_delete_bucketlist(self):
        """
        Test the api can delete a bucketlist.
        """
        bucketlist = Bucketlist.objects.get()
        response = self.client.delete(
            api_reverse('details', kwargs={'pk': bucketlist.id}),
            format='json',
            follow=True
        )
        self.assertEquals(response.status_code, status.HTTP_204_NO_CONTENT)
