"""
- After some reports from various users of the system, it has become apparent
that some cars tracked in the system are duplicated (from 1 up to a few dozen times).
Write a script to identify these duplicate cars and resolve the data discrepancies.
Additionally, summarize the total cost associated with these cars in order to
provide the basis for the revision of sales projections produced by the
business team.
"""

#
# Django/Python script to identify and delete all duplicate cars in
# a Car table
#
from .models import Car
from django.db import models


#
# To make this script more useful, I would have the fields and model parameters
# be something that the user can input, so that the script can be used on
# any model
#
def delete_car_duplicates():
    all_cars = Car.objects.all()
    fields = [field.name for field in Car._meta.get_fields()]
    duplicates = Car.objects.values(*fields).annotate(min_id=models.Min(
        'id'))
    #
    # Remove all duplicates in given set except for first
    # occurrence
    #
    for duplicate in duplicates:
        (Car.objects.filter(**{x: duplicate[x] for x in fields})
         .exclude(id=duplicate['min_id'])
         .delete())
