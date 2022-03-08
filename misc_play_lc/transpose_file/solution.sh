# Read from the file file.txt and print its transposed content to stdout.
cols=$( head -1 file.txt | wc -w | sed 's/ *//g')
for i in $(seq $cols);
do
    out=$(cut -d" " -f$i file.txt | tr '\n' ' ')
    echo $out
done
