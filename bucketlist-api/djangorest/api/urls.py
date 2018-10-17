from django.urls import path
from django.conf.urls import include
from rest_framework.urlpatterns import format_suffix_patterns
from .views import CreateView, DetailsView

urlpatterns = [
    path('bucketlists/', CreateView.as_view(), name='create'),
    path('bucketlists/<int:pk>/', DetailsView.as_view(), name='details'),
]

urlpatterns = format_suffix_patterns(urlpatterns)