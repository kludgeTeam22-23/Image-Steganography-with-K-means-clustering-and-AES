# Image Steganography with K-means clustering and AES encryption
The text message is encrypted using 128 bit key AES encryption. Then, the image's pixels are clustered using the K-means clustering technique. The stego-image is then transmitted after performing cluster-wise steganography using LSB technique. 

## How to execute:
### Encryption
#### i) AES encryption:
In the directory Encryption-AES, run the main_encrypt.cpp file. Enter the plaintext and the key.
NOTE: Key must be of 16 characters only.
