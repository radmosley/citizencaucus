#Starting image
FROM node

# install simple http server for serving static content
# RUN npm install -g http-server

# copy package.json and package-lock.json to working directory
COPY package*.json ./

# install project dependencies
RUN npm install
