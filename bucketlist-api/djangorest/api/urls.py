from django.urls import path
from django.conf.urls import include
from rest_framework.urlpatterns import format_suffix_patterns
from rest_framework.authtoken.views import obtain_auth_token
from .views import CreateView, DetailsView

urlpatterns = [
    path('auth/', include('rest_framework.urls', namespace='rest_framework')),
    path('bucketlists/', CreateView.as_view(), name='create'),
    path('bucketlists/<int:pk>/', DetailsView.as_view(), name='details'),
    path('get-token/', obtain_auth_token),
]

urlpatterns = format_suffix_patterns(urlpatterns)