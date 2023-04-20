### AES Decryption:
Decryption is the reverse process of encryption. Thus, we perform the steps to undo the changes made to the plaintext.

Each round of decryption has the following rounds:(round 9 - 1)
1. Add round key: XOR the key for that particular round with the state matrix
2. Inverse MixColumns: Its same as the encryption MixColumns, but the constant matrix multiplied is different
<img width="129" alt="image" src="https://user-images.githubusercontent.com/105154462/210128704-3a88ddb1-0ea6-4721-874d-c02845961ec8.png">

(image from https://www.youtube.com/watch?v=SDrzMyqi2Sc)

3. ShiftRows: The row elements are shifted among each other. The first row is left unchanged, the second row is shifted to the RIGHT by 1, the third row is shifted to the RIGHT by 2, the fourth row is shifted to the RIGHT by 3.
4. Inverse SubByte: The elements in the matrix are substituted using the inverse S-box.

The initial round (round 10) of decryption doesn't have the inverse mix columns step
The final round (round 0) consists of just XORing the key (K0) again.
Note: The keys are also used in the reverse way. K10 is used in the initial round and K0 is used in the final round.
