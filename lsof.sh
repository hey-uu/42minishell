#!/bin/bash

while :
do
	lsof | grep minishell| wc -l;
	sleep 0.2;
done
