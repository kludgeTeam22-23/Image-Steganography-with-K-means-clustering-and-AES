## K-Means Clustering: 
This method divides n objects into k clusters, and each object is assigned to the 
cluster that has the closest mean. With this approach, k distinct clusters with the 
most variety are produced. K-Means clustering aims to reduce overall intra-cluster 
variation. Several chunks of encrypted data are inserted into an image using it in 
this case. Now that we have categorised the image into various groups, we may 
segment it. There are various techniques for segmenting images; in this case, the 
K-Means clustering algorithm is used to group the image's pixels according to their 
RGB values. Cluster data is stored for LSB. 

Taking k=4 and no. of iterations/epochs = 100, we could get the following results 
for the below image: 

<img width="242" alt="Screenshot 2023-04-23 013748" src="https://user-images.githubusercontent.com/105167498/233804294-2c0ba5a3-051c-40a6-b069-1476f8d5ea1f.png">

## LSB Encryption:
The Least Significant Bit (LSB) technique is a popular method for hiding 
information within an image. In LSB steganography, the message to be hidden is 
encoded into the least significant bit of each pixel in an image, which is usually the 
bit that changes the least when the pixel is altered. By modifying the least 
significant bit, the change in the pixel value is often too small to be detected by the 
human eye, and the image appears unchanged.

Here is how the LSB technique can be applied to image steganography:

1. The message to be hidden is first converted into binary form. For example, 
the letter 'A' can be represented as the binary value 01000001. 
2. The cover image, which is the image that will contain the hidden message, is 
divided into small blocks of pixels. 
3. For each block of pixels in the cover image, the least significant bit of each 
pixel is modified to contain a bit from the binary message. For example, if 
the first pixel in the block has a value of 11110011 and the first bit of the 
binary message is 0, then the modified pixel value would be 11110010. 
4. Once all the pixels in a block have been modified, the modified block is 
written back to the cover image. 
5. This process is repeated for all the blocks in the image until the entire 
message has been hidden.
