# Generated by Django 2.0.1 on 2018-02-26 17:37

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pages', '0011_auto_20180220_1751'),
    ]

    operations = [
        migrations.CreateModel(
            name='Vote',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('title', models.TextField()),
                ('member_id', models.CharField(max_length=20)),
                ('bill_id', models.CharField(max_length=50)),
                ('vote', models.CharField(max_length=20)),
                ('results', models.CharField(max_length=20)),
            ],
        ),
    ]
