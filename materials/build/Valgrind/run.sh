#!/bin/bash

cd ../../../
docker rmi -f ereva/valgrind/list
docker build . -t ereva/valgrind/list -f materials/build/Valgrind/Dockerfile
docker run --rm ereva/valgrind/list
