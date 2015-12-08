# Read from the file file.txt and output all valid phone numbers to stdout.
set -x
sed -n -E '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
