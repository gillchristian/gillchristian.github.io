#!/bin/bash

NODE_ENV=production;

npm run move:assets;

npm run js:build;

sudo docker-compose -f docker-compose.prod.yml up -d;
