from rest_framework import serializers
from .models import Cat

class CatListSerializer(serializers.ModelSerializer):
    owner = serializers.CharField(max_length = 150, allow_blank = True, required = False)
    name = serializers.CharField(max_length = 50, allow_blank = True, required = False)
    age = serializers.IntegerField(required = False)
    photo = serializers.URLField(required = False)
class Meta:
    model = Cat
    fields = ('id', 'owner', 'name', 'age', 'photo')

class CatSerializer(serializers.ModelSerializer):
    owner = serializers.CharField(max_length = 150, allow_blank = True, required = False)
    name = serializers.CharField(max_length = 50, allow_blank = True, required = False)
    colors = serializers.CharField(max_length = 3, required = False)
    age = serializers.IntegerField(required = False)
    toy = serializers.CharField(max_length = 50, allow_blank = True, required = False)
    mood = serializers.CharField(max_length = 3, required = False)
    photo = serializers.URLField(required = False)
class Meta:
    model = Cat
    fields = ('id', 'owner', 'name', 'colors', 'age',
                    'toy', 'mood', 'photo')