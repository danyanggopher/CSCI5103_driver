printf "\n---------------------------------------------------------------\n"
printf "\n                      Test_CASE 5                              \n"
printf "\nBuilding logdirectory: test5_log\n"
if [ -d "test5_log" ]; then
  printf "test5_log/ existed... Removing test5_log/ to create a new one...\n"
  rm -r test5_log
fi
mkdir test5_log
printf "Starting Process Producer Black (log: test5_log/PBlack.txt)\n"
./producer/producer 50 BLACK >> test5_log/PBlack.txt &
pidPB=$!
printf "Starting Process Consumer 1 (log: test5_log/C1.txt)\n"
./consumer/consumer 50 1 >> test5_log/C1.txt &
pidC1=$!
printf "Starting Process Consumer 1 (log: test5_log/C2.txt)\n"
./consumer/consumer 50 2 >> test5_log/C2.txt &
pidC2=$!
printf "Waiting for process to complete.\n"
wait "$pidPB" "$pidC1" "$pidC2"
printf "\n                  Test_Case 5 Complete                         \n"
printf "\n---------------------------------------------------------------\n"
