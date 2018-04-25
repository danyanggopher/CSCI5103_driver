printf "\n---------------------------------------------------------------\n"
printf "\n                      Test_CASE 4                              \n"
printf "\nBuilding logdirectory: test4_log\n"
if [ -d "test4_log" ]; then
  printf "test4_log/ existed... Removing test4_log/ to create a new one...\n"
  rm -r test4_log
fi
mkdir test4_log
printf "Starting Process Producer Black (log: test4_log/PBlack.txt)\n"
./producer/producer 50 BLACK >> test4_log/PBlack.txt &
pidPB=$!
printf "Starting Process Producer Red (log: test4_log/PRed.txt)\n"
./producer/producer 50 Red >> test4_log/PRed.txt &
pidPR=$!
printf "Starting Process Consumer 1 (log: test4_log/C1.txt)\n"
./consumer/consumer 100 1 >> test4_log/C1.txt &
pidC=$!
printf "Waiting for process to complete.\n"
wait "$pidPB" "$pidPR" "$pidC"
printf "\n                  Test_Case 4 Complete                         \n"
printf "\n---------------------------------------------------------------\n"
