#Starting image
FROM node

# install simple http server for serving static content
# RUN npm install -g http-server

# make the 'app' folder the current working directory
WORKDIR /app

# copy package.json and package-lock.json to working directory
COPY package*.json ./

# install project dependencies
RUN npm install

#Copy source files
COPY . .

EXPOSE 8080
CMD ["npm", "run", "serve"]