#!/bin/bash

NM=node_modules
PUBLIC_STYLE=public/assets/style;
HL_FILE=agate;

mkdir ${PUBLIC_STYLE}/libs;

rm -fr ${PUBLIC_STYLE}/libs/hack;

cp -r ${NM}/hack ${PUBLIC_STYLE}/libs/hack;

cp ${NM}/highlight.js/styles/${HL_FILE}.css ${PUBLIC_STYLE}/generic/${HL_FILE}.scss;
