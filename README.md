## Description

Streams text from a command with the colors stripped from it.

**Note on current state of accuracy**
Currently the stripping mechanism is based on common escape codes, but it might not cover every possible scenario. This is a work in progress until a 1.0 release.

# Installation

### From Binary

Download the latest binary for your platform [here](https://github.com/yourusername/nocol/releases)

### Install via Homebrew 
If you don't have the tap, add it with: 
```sh 
brew tap divanvisagie/homebrew-tap 
```

Then simply
```sh
brew install nocol
```

# Usage

| Command Example             | Description                                       |
|-----------------------------|---------------------------------------------------|
| echo 'hello' | lolcat | nocol | Strips colors from the output of `lolcat`.      |
| ifconfig | nocol             | Strips colors from the output of `ifconfig`.     |
| cat colorfulfile.txt | nocol | Strips colors from the contents of a file.       |
