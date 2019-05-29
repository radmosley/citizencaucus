# Citizen Caucus
Graphic interfacing with multiple API's to track Senate activity
- [Development-Environment](#)
- [Front-End](#)
- [API](#)
- [Database](#)

## Development Evnrionment
### Docker Compose
Docker is a platform for developers and sysadmins to develop, deploy, and run applications with containers. The use of Linux containers to deploy applications is called containerization.
- Flexible: Even the most complex applications can be containerized.
- Lightweight: Containers leverage and share the host kernel.
- Interchangeable: You can deploy updates and upgrades on-the-fly.
- Portable: You can build locally, deploy to the cloud, and run anywhere.
- Scalable: You can increase and automatically distribute container replicas.
- Stackable: You can stack services vertically and on-the-fly.
clone git directory: git clone https://github.com/radmosley/citizencaucus.git 
CD into directory
Run Docker Image: docker-compose up

## Front End:

### VUE
Vue is a progressive framework for building user interfaces. Unlike other monolithic frameworks,Vue is designed from the ground up to be incrementally adoptable. The core library is focused on the view layer only, and is easy to pick up and integrate with other libraries or existing projects. On the other hand, Vue is also perfectly capable of powering sophisticated Single-Page Applications when used in combination with modern tooling and supporting libraries.

## API

### Django REST Framework
Django REST framework is a powerful and flexible toolkit for building Web APIs. The Web browsable API is a huge usability win for your developers. Authentication policies including packages for OAuth1a and OAuth2. Serialization that supports both ORM and non-ORM data sources. Customizable all the way down - just use regular function-based views if you don't need the more powerful features. Extensive documentation, and great community support. Used and trusted by internationally recognised companies including Mozilla, Red Hat, Heroku, and Eventbrite.
  
### ProPublica
Using the Congress API, you can retrieve legislative data from the House of Representatives, the Senate and the Library of Congress. The API, which originated at The New York Times in 2009, includes details about members, votes, bills, nominations and other aspects of congressional activity. This document describes the requests that users can make of the API and the responses that it returns.

## Database

### PostGres
PostgreSQL is a powerful, open source object-relational database system with over 30 years of active development that has earned it a strong reputation for reliability, feature robustness, and performance.
## Custom Commands

update senators data using propublica api.
```
python manage.py getSenator
```