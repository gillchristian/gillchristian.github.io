#!/bin/bash

NODE_ENV=development;

npm run move:assets;

sudo docker-compose up -d;
