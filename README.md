# nocol

**nocol** is a command-line tool designed to stream text output from commands, stripping away any embedded ANSI colour codes. Unlike other tools like `ansi2txt`, **nocol** streams logs instantly, avoiding the long pauses typical of tools that buffer before writing to `tee` or other destinations. This makes **nocol** perfect for scenarios where you need real-time log processing, such as piping logs from a Node.js service into a log file in `/tmp` for easier searching within NeoVim. It's particularly handy for use with program runners like Cargo or Yarn, which produce coloured log outputs.

## Installation

### From Binary

Download the latest binary for your platform [here](https://github.com/divanvisagie/nocol/releases).

### Install via Homebrew

If you haven't added the tap yet, do so with:
```sh
brew tap divanvisagie/homebrew-tap
```

Then, install **nocol** with:
```sh
brew install nocol
```

## Usage

| Command Example                 | Description                                        |
|---------------------------------|----------------------------------------------------|
| `echo 'hello' \| lolcat \| nocol` | Strips colours from the output of `lolcat`.       |
| `ifconfig \| nocol`             | Strips colours from the output of `ifconfig`.      |
| `cat colorfulfile.txt \| nocol` | Strips colours from the contents of a file.        |

By using **nocol**, you ensure that your log files are clean and easily searchable, while benefiting from instant streaming without the delays experienced with other colour-stripping tools.

