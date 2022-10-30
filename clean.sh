#!/bin/bash

clean_latex () {
    rm *-blx.bib
    rm *.aux
    rm *.dvi
    rm *.fdb_latexmk
    rm *.fls
    rm *.log
    rm *.run.xml
    rm *.synctex.gz
    rm *.toc
    rm *.ilg
    rm *.out
    rm *.xdv
    rm __latexindent_temp.tex
    # rm *.pdf
}

main () {
    for node in *; do
        if [ -d "$node" ]; then
            cd "$node"
            main
            cd ..
        fi
    done
    echo -n `pwd`
    echo -ne "\r"
    sleep 0.1 # this is only for the swag
    clean_latex > /dev/null 2>&1
}

main