FROM python:3
ENV PYTHONUNBUFFERED 1

ADD requirements.txt /app/requirements.txt
RUN /env/bin/pip install --upgrade pip && /env/bin/pip install -r /app/requirements.txt
ADD . /app

CMD gunicorn -b :$PORT mysite.wsgi
