# Image Steganography with K-means clustering and AES encryption
The text message is encrypted using 128 bit key AES encryption. Then, the image's pixels are clustered using the K-means clustering technique. The stego-image is then transmitted after performing cluster-wise steganography using LSB technique. 

## How to execute:
### Encryption
#### i) AES encryption:
In the directory Encryption-AES, run the main_encrypt.cpp file. Enter the plaintext and the key.
NOTE: Key must be of 16 characters only.
<img width="772" alt="image" src="https://user-images.githubusercontent.com/105154462/233543028-09f5af75-9617-4ba7-83f1-b9b010ac867f.png">

#### ii) K-means and LSB encryption:
Make sure that stb_image folder, example.txt(obtained from AES encryption) and the image (testimg.png) is in the same directory and run the k_lsb.c file. (Replit was used in the below image)
cluster[number] are images after k-means and Cluster[number] are the images generated after LSB encryption.

<img width="384" alt="Screenshot 2023-04-22 202106" src="https://user-images.githubusercontent.com/105167498/233803615-8e792601-dfa8-4670-8d3d-b54b8dd5a99c.png">
<img width="386" alt="Screenshot 2023-04-22 202122" src="https://user-images.githubusercontent.com/105167498/233803637-03630ae5-7863-47f3-b2eb-fdf91e45a504.png">

### Decryption
#### i) LSB Decryption
Check if all the final Cluster[number] images obtained from above and stb_image folder are in the same directory and then run the lsb_decrypt.c file.



#### ii) AES Decryption:
In the directory Decryption-AES, run the main_decrypt.cpp file. Enter the key. (Make sure its the same as the encryption key.)
<img width="706" alt="image" src="https://user-images.githubusercontent.com/105154462/233543154-3dd45fba-d686-41ef-9f86-47ff6ee05ad7.png">
