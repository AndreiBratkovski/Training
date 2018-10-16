from django.db import models
# from django.contrib.auth.models import (
#     AbstractBaseUser, BaseUserManager, PermissionsMixin
# )
BLACK = "BLK"
WHITE = "WHE"
GREY = "GRY"
BROWN = "BRW"
RED = "RED"
COLORS = (
    (BLACK, 'black'),
    (WHITE, 'white'),
    (GREY, 'grey'),
    (BROWN, 'brown'),
    (RED, 'red'),
)
HAPPY = "HAY"
GRUMPY = "GRY"
BAD = "BAD"
MILKHOLIC = "MIC"
MOODS = (
    (HAPPY, 'happy'),
    (GRUMPY, 'grumpy'),
    (BAD, 'bad'),
    (MILKHOLIC, 'milkholic'),
)
class Cat(models.Model):
    owner = models.CharField(max_length = 150, blank = True)
    name = models.CharField(max_length = 50, blank = True)
    colors = models.CharField(max_length = 3, choices = COLORS, default = BLACK)
    age = models.IntegerField(blank = True)
    photo = models.URLField(blank=True)
    toy = models.CharField(max_length = 50, blank = True)
    mood = models.CharField(max_length = 3, choices = MOODS, default = HAPPY)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    class Meta:
      ordering = ('created_at',)
