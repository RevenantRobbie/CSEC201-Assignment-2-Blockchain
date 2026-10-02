#include "hash.h"
#include "user.h"

unsigned char* SSHA(struct User* usr, size_t length) {
    unsigned char A, B, C, D, E; //Initial Seed Value
    unsigned char* msg = (unsigned char*)usr; // creates msg by casting usr to unsigned char, but we still need usr to access the hash values
    A = usr->hash.hash0; //I don't think A-E are based on the msg... shouldn't this be A = msg->hash.hash0?
    B = usr->hash.hash1;
    C = usr->hash.hash2;
    D = usr->hash.hash3;
    E = usr->hash.hash4;

    for (int i = 0; i < length; i++) {
        for (int round = 0; round < 8; round++) {
            unsigned char g = (B & C) | (C & D);
            unsigned char old_A = A;
            unsigned char old_E = E;
            A = (A >> 2) % 256;
            B = (B >> 1) % 256;
            E = (g + B + msg[i]);
            D = (A ^ B) % 256;
            C = (A + E) % 256;
            A = old_E;
            B = old_A;
        }
    }

    /* old hashing algorithm(terrible)
    A = 56;
    B = 99;
    C = 102;
    D = 67; 
    E = 76;
    for (int i = 0; i < length; i++) {
        for (int round = 0; round < 8; round++) {
            unsigned char g = (B & C) | (C & D);
            unsigned char old_A = A;
            A = (A + 2) % 256;
            B = (B * 3) % 257;
            E = (g + msg[i] + B);
            D = (A ^ B) % 256;
            C = ((A + E) * 5) % 257;
            A = E;
            B = old_A;
        }
    }*/

    unsigned char* digest = (unsigned char*)malloc(DIGEST_SIZE * sizeof(unsigned char));
    digest[0] = A;
    digest[1] = B;
    digest[2] = C;
    digest[3] = D;
	digest[4] = E; //originally digest[4] = D;, should be digest[4] = E; 

	printf("%s\n", usr->Username);
	printf("User Hash: ");
	printDigest(usr->hash);
    printf("Calculated Digest: ");
	printDigest((struct Digest) { digest[0], digest[1], digest[2], digest[3], digest[4] });
    return digest;
}

//made by chatGPT
unsigned char* SSHA2(struct User* usr, size_t length) {
    if (usr == NULL)
		return NULL;

    /*
    * Initial hash state
    */
	unsigned char A = usr->hash.hash0;
	unsigned char B = usr->hash.hash1;
	unsigned char C = usr->hash.hash2;
	unsigned char D = usr->hash.hash3;
	unsigned char E = usr->hash.hash4;

    /*
    * Treat the User structure itself as the message.
    */
	unsigned char* msg = (unsigned char*)usr;

    for (size_t i = 0; i < length; i++) {
        /*
        * Compute the next state from the OLD values of A-E
        * Using temporary vareiables is important because all five
        * values are updated simultaneously in the diagram.
        */
        unsigned char newA = E;

        unsigned char newB = A;

		unsigned char newC = 
            (unsigned char)((A >> 2) + E);

        unsigned char newD = 
            (unsigned char)((A >> 2) ^ (B >> 1));

        unsigned char newE =
            (unsigned char)(
                (B >> 1)
                + ((B & C) | (C & D))
                + msg[i]
            );

        A = newA;
		B = newB;
		C = newC;
		D = newD;
		E = newE;
    }

	unsigned char* result = malloc(5 * sizeof(unsigned char));

    if (result == NULL)
        return NULL;

	result[0] = A;
	result[1] = B;
	result[2] = C;
	result[3] = D;
	result[4] = E;

	return result;
}

int digest_equal(struct Digest digest1, struct Digest digest2) {
    return ((digest1.hash0 == digest2.hash0) &&
        (digest1.hash1 == digest2.hash1) &&
        (digest1.hash2 == digest2.hash2) &&
        (digest1.hash3 == digest2.hash3) &&
        (digest1.hash4 == digest2.hash4));
    
}

void printDigest(struct Digest digest) {
    printf("%d %d %d %d %d\n", digest.hash0, digest.hash1, digest.hash2, digest.hash3, digest.hash4);
}