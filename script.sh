#!/bin/bash

: '
author      :   Poojan Patel  poojanpatel888@gmail.com
date        :   05-11-2019 23:49
Description :   create directory/files for fast competitive coding.
                create files using deafult template provided.
                Ex: ./script.sh -d dir1 5  #creates directory name dir1 
                    ./script.sh -d dir2 5 py
                    ./scrupt.sh -f file1
                default extension of file is cpp :D
                default template file name is template.
'       


case $1 in
    -f) filename=$2;ext=$3;;
    -d) dirname=$2;files=$3;ext=$4;;
    -*) echo "Wrong parameters passed -d dirname numberof files upto 26 or -f filename">&2; exit 1;;
esac

echo "Filename" $filename
echo "Dirname" $dirname
echo "Files" $files

if [ "$ext" = "" ];then
    ext='cpp'
fi
if  [ "$filename" != "" ] ;then
    echo "file here"
    cat template > "$filename"
else
    if [ "$files" = "" ] ;then
        files=5
    fi
    chars=({a..z})
    mkdir $dirname 2>/dev/null
    if [ $? -eq 1 ];then
        echo "Directory creation failed. check if directory already exits";
        exit 1;
    fi
    for ((i=0;i<${files};i++))
    do
        echo "file added" ${PWD}/${dirname}/${chars[i]}.${ext}
        cat template > ${PWD}/${dirname}/${chars[i]}.${ext}
    done
fi
