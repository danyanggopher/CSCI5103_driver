printf "\n---------------------------------------------------------------\n"
printf "\n                      Test_CASE 2                              \n"
printf "\nBuilding logdirectory: test2_log\n"
if [ -d "test2_log" ]; then
  printf "test2_log/ existed... Removing test2_log/ to create a new one...\n"
  rm -r test2_log
fi
mkdir test2_log
printf "Starting Process Producer Black (log: test2_log/PBlack.txt)\n"
./producer/producer 50 BLACK >> test2_log/PBlack.txt &
pidP=$!
printf "Starting Process Consumer 1 (log: test2_log/C1.txt)\n"
./consumer/consumer 10 1 >> test2_log/C1.txt &
pidC=$!
printf "Waiting for process to complete.\n"
wait "$pidP" "$pidC"
printf "\n                  Test_Case 2 Complete                         \n"
printf "\n---------------------------------------------------------------\n"
