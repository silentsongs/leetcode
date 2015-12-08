# Read from the file file.txt and output the tenth line to stdout.
set -x
tail -n +10 file.txt | head -n 1
