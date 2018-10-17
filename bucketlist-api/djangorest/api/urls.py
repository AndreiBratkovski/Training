from django.urls import path
from django.conf.urls import include
from rest_framework.urlpatterns import format_suffix_patterns
from .views import CreateView

urlpatterns = [
    path('bucketlist/', CreateView.as_view(), name='create'),
]

urlpatterns = format_suffix_patterns(urlpatterns)