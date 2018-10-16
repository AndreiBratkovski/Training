from rest_framework import status
from rest_framework.generics import ListAPIView, RetrieveAPIView
from rest_framework.permissions import AllowAny
from rest_framework.response import Response
from .models import Cat
from .renderers import CatJSONRenderer
from .serializers import CatSerializer, CatListSerializer

class CatListApiView(ListAPIView):
    model = Cat
    queryset = Cat.objects.all()
    permissions_classes = (AllowAny,)
    renderer_classes = (CatJSONRenderer,)
    serializer_class = CatListSerializer

class CatRetrieveApiView(RetrieveAPIView):
    permission_classes = (AllowAny,)
    renderer_classes = (CatJSONRenderer,)
    serializer_class = CatSerializer
    
    def retrieve(self, request, cat, *args, **kwargs):
      cat = Cat.objects.get(id = cat.id) 
      serializer = self.serializer_class(cat)
      return Response(serializer.data, status = status.HTTP_200_OK)