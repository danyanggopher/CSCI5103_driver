printf "\n---------------------------------------------------------------\n"
printf "\n                      Test_CASE 3                              \n"
printf "\nBuilding logdirectory: test3_log\n"
if [ -d "test3_log" ]; then
  printf "test3_log/ existed... Removing test3_log/ to create a new one...\n"
  rm -r test3_log
fi
mkdir test3_log
printf "Starting Process Producer Black (log: test3_log/PBlack.txt)\n"
./producer/producer 50 BLACK >> test3_log/PBlack.txt &
pidP=$!
printf "Starting Process Consumer 1 (log: test3_log/C1.txt)\n"
./consumer/consumer 100 1 >> test3_log/C1.txt &
pidC=$!
printf "Waiting for process to complete.\n"
wait "$pidP" "$pidC"
printf "\n                  Test_Case 3 Complete                         \n"
printf "\n---------------------------------------------------------------\n"
