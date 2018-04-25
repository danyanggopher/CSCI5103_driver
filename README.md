# ScullBuffer
Team Member:
Kah Hin Lai   laixx330
DanYang Wang  wang6132
## Instruction
### Compiling and installing the scullbuffer devices:
--------------------------------------------------
1. Execute Make: <br>
run command ```make``` in ScullBuffer directory (NOTE: not the scullbuffer subdirectory)
2. Run Installation: <br>
run ```./install.sh```. <br>
This may ask you for your root password.<br>

### Testing the functioning of scullbuffer devices:
-------------------------------------------------
1.  Run All Tests:<br>
run command ```./RunAllTests.sh```.<br>
This will Create all (5) log directories and store output of All (5) tests.<br>
2.  Run Specific Tests:<br>
To run a specific test (1-5) just run ./testX.sh<br>
For Example, run command ```./test1.sh``` to run test 1.<br>
This will create one log directory with its test number to store the test output.
--------------------------------------------------

## Test Description
--------------------------------------------------
1. Testcase 1: <br>
 Start a producer which will produce 50 items before exiting.
 Start a consumer which will consume try to 50 items before exiting.

2. Testcase 2: <br>
 Start a producer which will produce 50 items before exiting.
 Start a consumer which will try to consume only 10 items before exiting.

3. Testcase 3: <br>
 Start a producer which will produce 50 items before exiting.
 Start a consumer which will try to consume 100 items before exiting.

4. Testcase 4: <br>
 Start two producers which will both produce 50 items each before exiting (total = 100 items).
 Start a consumer which will try to consume 200 items before exiting.

5. Testcase 5: <br>
 Start a producer which will produce 50 items before exiting.
 Start two consumers which will consume the 50 deposited items.
--------------------------------------------------
