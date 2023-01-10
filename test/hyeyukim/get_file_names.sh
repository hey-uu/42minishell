#! /bin/bash

touch files;
cd ../src/mandatory;
printf "mandatory files\n" >> ../../test/files;
ls *.c | cut -f 1 -d . | xargs printf "%s \\\\\n\t\t\t" >> ../../test/files;
printf "\n" >> ../../test/files;
cd ../bonus
printf "bonus files\n" >> ../../test/files;
ls *.c | cut -f 1 -d . | xargs printf "%s \\\\\n\t\t\t" >> ../../test/files;