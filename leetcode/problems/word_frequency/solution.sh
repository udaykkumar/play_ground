# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | egrep "[a-z]" |sort | uniq -c |sort -r | awk '{print $2,$1}' 