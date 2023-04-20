### AES Encryption:
It mainly consists of two parts: Key expansion and Encryption

#### Key Expansion:
For 128 bit key AES encryption, there are 11 rounds. For each round, one key is needed. All the keys need to be of 16 bytes.
From the 16 byte key given by the user, we generate 10 more keys to use in the following rounds. The procedure for generating the keys is as follows:
1. Create a 176 byte array (here, expandedKey) inorder to store the keys. 
2. The first 16 bytes will be used to store the original input key. 
3. The last four bytes of the current key will be passed through the g function (explained below).
4. The output from the g function will be XORed with the first four bytes of the current key to generate the first four bytes of the next key
   The first four bytes of the next key will be XORed with the 5th - 8th bytes of the current key to generate the 5th - 8th bytes of the next key
   The 5th - 8th bytes of the next key will be XORed with the 9th - 12th bytes of the current key to generate the 9th - 12th bytes of the next key
   The 9th - 12th bytes of the next key will be XORed with the last four bytes of the current key to generate the last four bytes of the next key
5. This will be continued until the keys are generated

##### G function:
1. The 4 bytes are shifted one to the left. eg: {B0, B1, B2, B3} becomes {B1, B2, B3, B0}
2. These bytes are substituted using the  forward substitution box for aes encryption.
3. The first byte is then XORed with the round constant.

<img width="407" alt="image" src="https://user-images.githubusercontent.com/105154462/209668441-c7f3f703-3a89-4cff-ab9f-25e660427a14.png">
(image from https://www.brainkart.com/article/AES-Key-Expansion_8410/)

#### Encryption:
We initially pad the message so that the length is a multiple of 16. 
Round 0:
1. The padded plaintext is then XORed with the first key. This (now called State Matrix) is now passed on to the next step.

Round 1 to Round 9:
2. Sub Bytes: The bytes in state matrix are replaced using the forward S-box 
3. Shift Rows: The row elements are shifted among each other. The first row is left unchanged, the second row is shifted to the left by 1, the third row is shifted to the left by 2, the fourth row is shifted to the left by 3.
4. Mix columns: The state matrix is multiplied by a constant matrix to form a new matrix

<img width="177" alt="image" src="https://user-images.githubusercontent.com/105154462/209670204-824377be-9d24-452a-9e5e-bbcd1bad8420.png">
(image from https://www.youtube.com/watch?v=Z_7aOkS8tOA&t=578s)

5. Add round key: The state matrix is XORed with the key for that round.
6. These 4 steps are done for each round

Round 10:
In the last round, we dont perform mix columns. We perform sub bytes, shift rows and add round key.
This gives us the cipher text.
