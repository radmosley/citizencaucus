FROM python:3
ENV PYTHONUNBUFFERED 1
#Copy requirements and directory into the container
COPY requirements.txt .
COPY . .
# install pip and python dependencies
RUN pip install --upgrade pip
RUN pip install pipenv
RUN pip install -r requirements.txt
EXPOSE 5432
EXPOSE 8000


