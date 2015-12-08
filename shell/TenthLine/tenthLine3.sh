# Read from the file file.txt and output the tenth line to stdout.
set -x
sed -n '10p' file.txt
