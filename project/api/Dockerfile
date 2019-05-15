 FROM python:3
 ENV PYTHONUNBUFFERED 1
#  WORKDIR /code
 COPY requirements.txt .
 COPY . .
 # install pip and python dependencies
 RUN pip install --upgrade pip
 RUN pip install pipenv
 RUN pip install -r requirements.txt
FROM python:3
ENV PYTHONUNBUFFERED 1
RUN mkdir /code
WORKDIR /code
COPY requirements.txt /code/
RUN pip3 install -r requirements.txt
COPY . /code/


