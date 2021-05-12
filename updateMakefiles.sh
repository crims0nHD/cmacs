#!/bin/sh

#check if makefiles in srcfolders exist
#if not: create makefile
for d in $(find ./src -maxdepth 1 -mindepth 1 -type d)
do
    echo "checking ${d}..."
    
    if test -f ${d}/Makefile; then
        echo "OK"
    else
        echo "generating Makefile..."

        n=$(basename ${d})
        awk -v n="$n" '{gsub("replaceme", n); print;}' ./Makefile.template > ${d}/Makefile

        
        echo "done"
    fi
    
    echo "done with ${d}"
done
