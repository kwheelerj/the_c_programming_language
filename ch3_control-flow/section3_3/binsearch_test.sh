#!/bin/ksh

BIN_FL=binsearch.out
BINF_FL=binsearch_fast.out
BINSRH_LOOP=binsrh.sh
BINFSRH_LOOP=binfsrh.sh

export BIN_FL BINF_FL

cc binsearch.c -o ${BIN_FL}
cc binsearch_fast.c -o ${BINF_FL}

echo "binsearch.c"
time ./${BINSRH_LOOP}
echo "=================="
echo "binsearch_fast.c"
time ./${BINFSRH_LOOP}

rm ./${BIN_FL}
rm ./${BINF_FL}
