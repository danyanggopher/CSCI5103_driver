list=$(find test*.sh -type f)

for file in $list;
  do
    ./$file
done
