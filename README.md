# Image Steganography with K-means clustering and AES encryption
The text message is encrypted using 128 bit key AES encryption. Then, the image's pixels are clustered using the K-means clustering technique. The stego-image is then transmitted after performing cluster-wise steganography using LSB technique. 

## How to execute:
### Encryption
#### i) AES encryption:
In the directory Encryption-AES, run the main_encrypt.cpp file. Enter the plaintext and the key.
NOTE: Key must be of 16 characters only.
<img width="772" alt="image" src="https://user-images.githubusercontent.com/105154462/233543028-09f5af75-9617-4ba7-83f1-b9b010ac867f.png">

### Decryption
#### i)
#### ii) AES Decryption:
In the directory Decryption-AES, run the main_decrypt.cpp file. Enter the key. (Make sure its the same as the encryption key.)
<img width="706" alt="image" src="https://user-images.githubusercontent.com/105154462/233543154-3dd45fba-d686-41ef-9f86-47ff6ee05ad7.png">
