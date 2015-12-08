# Read from the file words.txt and output the word frequency list to stdout.
set -x
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'
