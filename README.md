# FindFault

Authour:Nina Nguyen
Filename: FindFault.h
Date: 10/21/2017 (Version 1 - 10/15/2017)
Version: 1

Description:
This program demonstrates a has-a (composition) relationship between two classes.  This class encapsulate several (FIVE) EncryptWord objects. The user has to correct input words that matches
requirements set by EncryptWord class. (4 letters, lowercase or more and no spaces or punctuations). It will encrypt or decrypt a word but adds the
notion of "corruption". The program uses a random number generator between 1-100 and then use modulo to get an odd
or even number. Even is considered false and the word won't be corrupted and Odd is considered true and will be corrupted.
Words are corrupted by appending the letter "x" to the end of the string.  The program will assist the user in finding the
corrupted word by calling decode on the prior encrypted word. If the decrypted word dows not match the original word
sent in by the user, it will be considered corrupt.

FindFault will instantiate EncryptWord - all public functions in EnvryptWord will be available in FindFault but not th driver.

Built in:
Visual Studios
Vim

Acknowledgement:
p2 from Seattle u
