## LSB Decryption:
To extract the hidden message from the steganographic image, the reverse process of LSB encoding is followed. 
The least significant bit of each pixel in the steganographic image is 
extracted and combined to form the hidden binary message.

It should be noted that the LSB technique is not foolproof, and can be detected by 
analyzing the distribution of the least significant bits in the image. Additionally, 
compression or editing of the image can result in loss of the hidden message. 

We sort the cluster data and then we add a flag to help understand where the 
encrypted data ends. We modify data in LSB and then save the remaining pixels. 

While decrypting, we fetch LSB from image file using the flag. The cipher text is 
then decrypted to obtain the message. File storing the key is used for decryption.
