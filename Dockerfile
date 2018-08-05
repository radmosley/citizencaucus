# Citizen Caucus
# Version 1.0

FROM python:3.4

# Install Python and packages
ENV PYTHONUNBUFFERED 1

RUN mkdir /web
WORKDIR /web
ADD . /web/requirements.txt /web/
RUN  pip install -r /web/requirements.txt
ADD . /web/