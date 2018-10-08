 FROM python:3
 ENV PYTHONUNBUFFERED 1
 WORKDIR /code
 COPY . /code
 RUN pip install --upgrade pip
 RUN pip  install pipenv
 RUN pip install -r requirements.txt