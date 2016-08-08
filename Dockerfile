FROM octohost/harp-nginx

WORKDIR /app

ADD . /app

EXPOSE 9000
