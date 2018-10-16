"""vuewithdrf URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from django.views.generic import TemplateView
from rest_framework import routers

router = routers.DefaultRouter()

app_name = 'vuewithdrf'

urlpatterns = [
    path('', TemplateView.as_view(template_name='index.html'), name="uHome"),
    path('admin/', admin.site.urls),
    path('api/', include('vuewithdrf.apps.cat.urls', namespace='cats')),
    path('api/',include(router.urls)),
]
urlpatterns += staticfiles_urlpatterns()
