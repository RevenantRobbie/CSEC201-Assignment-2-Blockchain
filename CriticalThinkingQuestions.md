# CSEC201-Assignment-2-Blockchain

haii!

1. Core functions
	1. The program should successfully be able to create hashes
	2. The program should be able to create a unique hash for every unique input
	3. These hashes should be constent with the provided diagram
	4. The linked list/blockchain should be implemented correctly
	5. There should be no glaring errors that cause the code to fail to compile

2. Tests
	1. Given an input, the program should be able to generate a valid hash
	2. Given a second, different, input, the generated hash should be distinct from the previous hash
	3. Given a known input, the generated output should match the expected output
	4. Given a known previous input, the blockchain generator should create the next block in the chain correctly
	5. The code should be able to compile and run successfully without any errors

3. Did it compile?
	1. See screenshot 1

4. No changes made to the code to get it to compile, but a *lot* of the code is EXTREMELY questionable and needs to be improve or deleted.
	They all result in logical errors rather than compilation errors, so none of them need to be addressed at this very moment
	I still hate the line of code on line 8, but it probably needs to be there to simulate staggered logon times. I still hate it though

5. I might need some code to print out the user's Digest at certain critical moments 
   Additionally, I need to add a custom user who or chain of users who are identical to the users in blockchain 1 to test that the generated hashes are consistent
   Didn't actually need any new code to be written, since the code already prints the digests for me which I can use to debug fine
   also, I can just run the code twice and try to get the same output to test a chain of identical users

6. Ohhh kayyyyy
   As it currently stands, test one passes, test 2, 3, and 4 fail, and test 5 passes, which is pretty much the bare minimum for what this blockchain code should be a able to do
   Look to screenshot 2 for evidence. The hashes are technically valid, but the repitition of their values is not expected behavior
1. 