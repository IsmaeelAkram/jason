![Jason](https://raw.githubusercontent.com/ismaeelakram/jason/master/logo.png?raw=true)

The best and fastest hash cracker, written in C++.

## Usage
`jason -s=<hash> -t=<hashType> -v -a=<alphabet>`

**hash**: The hash you want to crack. (**Required**)

**hashType**: The hashing algorithm used to crack the hash. (MD5, SHA1, NTLM, etc.) (**Required**)

**-v**: Visualizing cracking. (slower) (**Optional**)

**alphabet**: Custom alphabet for cracking. If you leave this blank, it will use the default alphanumeric alphabet that comes with Jason (**Optional**)

## Supported Hash Algorithms
- MD5
- NTLM
- SHA1
- SHA256
- SHA384
- SHA512
- And it's very easy to add your own custom algorithm in the **hash.cpp** file.

## TODO
- Add optional GPU cracking (much faster).
- Add custom algorithms.