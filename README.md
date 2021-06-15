![Jason](https://raw.githubusercontent.com/ismaeelakram/jason/master/logo.png?raw=true)

The easiest hash cracker, written in C++.

## Installation
No extra libraries are needed!
```sh
git clone https://github.com/IsmaeelAkram/jason
cd jason
make
```

## Usage
`./jas0n -s=<hash> -t=<hashType> -v -a=<alphabet>`

**hash**: The hash you want to crack. (**Required**)

**hashType**: The hashing algorithm used to crack the hash. (MD5, SHA1, NTLM, etc.) If this is left blank, Jason will attempt to auto-detect the algorithm. (**Optional**)

**-v**: Visualizing cracking. (slower) (**Optional**)

**alphabet**: Custom alphabet for cracking. If you leave this blank, it will use the default alphanumeric alphabet that comes with Jason (**Optional**)

## Supported Hash Algorithms
- MD5
- SHA1
- SHA256
- SHA384
- SHA512
And it's very easy to add your own custom algorithm in `brute.cpp:performHash()`!
