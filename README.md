# Password Strength Checker (CLI)

A simple and secure C++ command-line tool that evaluates password stength on length, complexity, entropy, blacklist matching, and pattern detection.

## Features

- Length and character variety checks
- Common password detection (10,000+ passwords)
- Pattern detection using regex
- Shannon entropy calculation

## Installation
### Requirements
- g++ compiler (C++17 or later)
- `make`
- Linux or macOS terminal (`bash`/`zsh`)

### Build
Clone the repository and run:
```bash
make # build and compile
./password-checker # run compiled executable
```

## Usage

To run the password checker, use:
```bash
./password-checker
```
You will be prompted to enter a password

Example interaction:
```bash
$ ./password-checker
Enter your password:
```
You then type the password you are testing.
Example output:
```bash
Password strength: Strong (score: 10)
