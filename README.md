# nocol

## Description

**nocol** is a tool that streams text from a command with the colors stripped from it. While other tools like `ansi2txt` exist, **nocol** supports streaming logs instantly, avoiding long pauses that occur when other tools wait to fill their buffer before writing to something like `tee`. **nocol** was specifically developed to address the use case of piping logs from a Node.js service into a log file in `/tmp` to make them easier to search inside NeoVim. This makes it ideal for working with program runners like Cargo or Yarn that output colored logs.

## Installation

### From Binary

Download the latest binary for your platform [here](https://github.com/divanvisagie/nocol/releases).

### Install via Homebrew

If you don't have the tap, add it with: 
```sh
brew tap divanvisagie/homebrew-tap
```

Then simply:
```sh
brew install nocol
```

## Usage

| Command Example                 | Description                                        |
|---------------------------------|----------------------------------------------------|
| `echo 'hello' \| lolcat \| nocol` | Strips colors from the output of `lolcat`.       |
| `ifconfig \| nocol`             | Strips colors from the output of `ifconfig`.      |
| `cat colorfulfile.txt \| nocol` | Strips colors from the contents of a file.        |

By using **nocol**, you can ensure that your log files are clean and easily searchable, and benefit from instant streaming without the delays experienced with other color-stripping tools.
