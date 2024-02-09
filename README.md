# Text-to-phonemes-in-arabic-

Speech to text is a set of written symbols aimed at accurately recording linguistic sounds. Each individual sound is represented by a single symbol, and each symbol is represented by a single code. A change in phonetic phoneme gives a different meaning to the word. Hence, the need arose to build a high-precision system.

A comparative study was conducted on the existing systems to determine which one provides higher accuracy. It was found that there are several offices and systems that provide excellent results for the English language, while the results for the Arabic language were limited. The study concluded with the identification of three systems.

Several test cases were built based on the reading rules mentioned in the theoretical study to calculate the accuracy of each system. A library was used to calculate the similarity ratio between two string phonemes and then calculate the accuracy for all test cases.

It was found that the Toph system provides the highest accuracy among these systems, with an accuracy of 90.003%. The Toph system was adopted and some of its existing rules were modified to fit the recitation of Quranic verses, as it considers sequential reading, which is one of the most important requirements for reciting Quranic verses. It also takes into account special cases such as certain Quranic words and cases of stopping on a consonant or an Alef depending on the end of the word. After the modification, an accuracy of approximately 94% was achieved. Additionally, this system is built using the C++ programming language, so it was linked with Python and a suitable interface was developed.

The modified rules are as follows:

1. The case of hamzat al-wasl (connecting hamza) was taken into consideration.
2. The diacritical marks such as damma and kasra were omitted due to their non-compliance with the rules of Tajweed.
3. The letter "raa" (ر) was emphasized with shadda (gemination).
4. The gemination of the letters "waw" (و) and "yaa" (ي) was omitted according to the rules of Tajweed, while maintaining the gemination of diacritical marks in their appropriate positions.
5. The vocalization of numbers was omitted as it is not needed during recitation.
6. The letters "khaa" (خ), "ghayn" (غ), and "qaaf" (ق) were added as letters of isti'laa (raising).
7. The letter "alif" (أ) and the diacritical marks after the emphatic "raa" (ر) were emphasized.
