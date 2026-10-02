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

7. modifications made
		Modified hash.c and hash.h extensively to fix the hashing algorithm and ensure that user values were actually being passed in instead of it using pregenerated values each time
		also modified user.c to take the actually created hash values instead of setting them as 0 every time
		also also fixed a wacky bug on user.c where it wasn't actually comparing the right hashes 
		additionally, there was some print statements that were useful for testing that I missed on pt 6 that I actually added this time. It's in hash.c and it just prints the old hash and new hash next to each other for ease of debugging
		Made the verification process run twice too to make sure that all hashes return the same value when given the same input. Since verification runs the hashing algorithm, running it twice with the same inputs should test that the hashes return the same outputs given the same inputs

8. absolutely not. 
   as you can see in line 27 where the old code is (but its commented out), the hashing algorithm does not work at all
   in line 37, A is added by 2 instead of being bit shifted. Terrible since addition is reversible so its not good for hashing
   in line 38, B is multiplied by 3 instead of being bit shifted. Also terrible for the same reasons as why A was terrible
   in line 40, A + E is multiplied by 5 for no reason
   The hashing algorithm also sets the new A to the calculated version of E (B + mst[i] + g) instead of the old E
   also, in lines 28-32, A B C D and E are all static values, meaning the hash would be the same for every single block in the chain.
   There are however, some things I do like
		The modulo is a nice touch, keeps the unsigned characters within bounds, and is also irreversable which is good for hashing
		Doing 8 rounds of hashing is also good since it makes it more secure.
