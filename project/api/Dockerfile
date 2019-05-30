 FROM python:3
 ENV PYTHONUNBUFFERED 1
 # install pip and python dependencies
 RUN pip install --upgrade pip
 COPY requirements.txt .
 RUN pip install -r requirements.txt