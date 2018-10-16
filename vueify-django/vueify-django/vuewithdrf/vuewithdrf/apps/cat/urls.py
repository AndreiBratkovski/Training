from django.conf.urls import url
from .views import CatListApiView, CatRetrieveApiView

app_name = 'cat'
urlpatterns = [
    url(r'^cats/$', CatListApiView.as_view()),
    url(r'^cats/(?P<cat_id>\w+)/?$', CatRetrieveApiView.as_view()),
]
