from rest_framework import generics
from rest_framework import permissions
from .serializers import BucketlistSerializer
from .models import Bucketlist
from .permissions import IsOwner

class CreateView(generics.ListCreateAPIView):
    """
    This class defines the create behavior of
    our rest api
    """
    queryset = Bucketlist.objects.all()
    serializer_class = BucketlistSerializer
    permission_classes = (permissions.IsAuthenticated, IsOwner)

    def perform_create(self, serializer):
        """
        Save the post data when creating a new
        buckelist.
        """
        serializer.save(owner=self.request.user)

class DetailsView(generics.RetrieveUpdateDestroyAPIView):
    """
    This class handles the http GET, PUT, and
    DELETE requests.
    """
    queryset = Bucketlist.objects.all()
    serializer_class = BucketlistSerializer
    permission_classes = (permissions.IsAuthenticated, IsOwner)