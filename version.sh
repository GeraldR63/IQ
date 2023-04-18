#!/bin/bash

BUILD=`cat build.dat`
BUILD=$[ $BUILD + 1]
echo "char * author=\"(w)2015 Gerald Roehrbein\";">version.h
echo "char * release=\""`date`"\";" >>version.h
echo "char * build=\"$BUILD\";" >>version.h

echo $BUILD >build.dat


cat version.h
