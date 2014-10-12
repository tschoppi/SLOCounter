#! /usr/bin/env bash

# Copy the code directory to a new directory, then compress it
# Delete the temporary directory afterwards

# Needs one argument (the version number)
if [[ $# != 1 ]] ; then
    echo "Need one argument (the version number)!"
    exit 1
fi

version=$1
dirname="SLOCounter-v$1"
archname="$dirname.tar.gz"

cp -r code $dirname
tar -czf $archname $dirname
rm -rf $dirname
