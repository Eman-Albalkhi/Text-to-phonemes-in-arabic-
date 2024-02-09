# Text-to-phonemes-in-arabic-

Speech to text is a set of written symbols aimed at accurately recording linguistic sounds. Each individual sound is represented by a single symbol, and each symbol is represented by a single code. A change in phonetic phoneme gives a different meaning to the word. Hence, the need arose to build a high-precision system.

A comparative study was conducted on the existing systems to determine which one provides higher accuracy. It was found that there are several offices and systems that provide excellent results for the English language, while the results for the Arabic language were limited. The study concluded with the identification of three systems.

Several test cases were built based on the reading rules mentioned in the theoretical study to calculate the accuracy of each system. A library was used to calculate the similarity ratio between two string phonemes and then calculate the accuracy for all test cases.

It was found that the Toph system provides the highest accuracy among these systems, with an accuracy of 90.003%. The Toph system was adopted and some of its existing rules were modified to fit the recitation of Quranic verses, as it considers sequential reading, which is one of the most important requirements for reciting Quranic verses. It also takes into account special cases such as certain Quranic words and cases of stopping on a consonant or an Alef depending on the end of the word. After the modification, an accuracy of approximately 94% was achieved. Additionally, this system is built using the C++ programming language, so it was linked with Python and a suitable interface was developed.

----
The TOPH system involves converting written symbols into phonetic symbols based on rules stored in the computer. It converts text from its written or spelled form into its corresponding spoken or pronounced form using language-specific algorithms. It should be noted that the input to the program is entirely in a coded format.

The modified rules are as follows:

The modified rules are as follows:

1. Consideration of the case of hamzat al-wasl (connecting hamza) being maddoomah (closed) or maktuubah (open) based on the movement of the third word.
2. Omission of diacritical marks (damma, kasra) due to their non-compliance with the rules of Tajweed.
3. Consideration of additional cases for emphasizing the letter "raa" (ر).
4. Omission of the gemination of "waw" (و) and "yaa" (ي) according to the adopted rules of Tajweed, while maintaining the gemination of diacritical marks in their appropriate positions.
5. Omission of vocalization of numbers as they are not needed during recitation.
6. Addition of the letters "khaa" (خ), "ghayn" (غ), and "qaaf" (ق) as letters of isti'laa (raising).
7. Consideration of emphasizing the letter "alif" (أ) and the diacritical marks after the emphatic "raa" (ر).
8. Consideration of emphasizing the letter "alif" (أ) and the diacritical marks after the letters of isti'laa and the emphatic letters of isti'laa.
9. Consideration of words in which the letter of elongation (madd) is written but not pronounced.
10. Consideration of the gemination and softening of the letter "lam" (ل) in the pronunciation of the Divine Name.
11. Consideration of "waw" (و) and "yaa" (ي) in all their cases.
