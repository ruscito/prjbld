#!/bin/bash

usage(){
    >&2 echo "Usage: $0 <project>"
    return 0
}


pname=$1
pdir="./${pname}"
tdir=/var/prjbld/templates



if [ -z "$pname" ]; then
    usage
    exit 1
elif ! [ -d "$tdir" ]; then
    >&2 echo "Unable to find template dir: $tdir"
    exit 2
elif [ -d "$pdir" ]; then
    >&2 echo "Project dir: $pdir already exsits"
    exit 3
fi


# Select template
cur="$PWD"
cd $tdir
echo "Please select a template"
select x in *; do
    template="$x"
    break
done


# Generate project form template
cd $cur
cp -R ${tdir}/$template $pdir
cd $pdir

for x in *; do
    if [ -f "$x" ]; then
        new=$(sed "s,PRJNM,$pname,g" <<< "$x")
        if [ "$x" = "$new" ]; then
            sed "s,PRJNM,$pname,g" < $x > temp
            mv -f temp $x
        else
            sed "s,PRJNM,$pname,g" < $x > $new
            if [ -e "$new" ]; then
                rm -f $x
            fi
        fi
    fi
done
