printf "\n---------------------------------------------------------------\n"
printf "\n                      Test_CASE 1                              \n"
printf "\nBuilding logdirectory: test1_log\n"
if [ -d "test1_log" ]; then
  printf "test1_log/ existed... Removing test1_log/ to create a new one...\n"
  rm -r test1_log
fi
mkdir test1_log
printf "Starting Process Producer Black (log: test1_log/PBlack.txt)\n"
./producer/producer 50 BLACK >> test1_log/PBlack.txt &
pidP=$!
printf "Starting Process Consumer 1 (log: test1_log/C1.txt)\n"
./consumer/consumer 50 1 >> test1_log/C1.txt &
pidC=$!
printf "Waiting for process to complete.\n"
wait "$pidP" "$pidC"
printf "\n                  Test_Case 1 Complete                         \n"
printf "\n---------------------------------------------------------------\n"
