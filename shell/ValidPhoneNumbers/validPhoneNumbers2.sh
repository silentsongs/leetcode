# Read from the file file.txt and output all valid phone numbers to stdout.
set -x
grep -E '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
