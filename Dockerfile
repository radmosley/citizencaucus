# Citizen Caucus
# Version 1.0

FROM python:3.6

# Install Python and packages
ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1

# Install dependencies
RUN pip install --upgrade pip
RUN pip install pipenv
COPY ./Pipfile /citizencaucus/Pipfile
RUN pip install --user pipenv

# Copy project
COPY . /citizencaucus/