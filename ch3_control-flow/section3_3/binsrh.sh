#!/bin/ksh

exec 1>/dev/null

for i in {1..10}
do
	./${BIN_FL}
done
