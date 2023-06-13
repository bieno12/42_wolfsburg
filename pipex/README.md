**Pipex**

Pipex is a project that allows you to mimic the behavior of the shell command line by redirecting the standard input and output of a series of commands to files. The goal of this project is to improve your understanding of file descriptors and processes in Unix.

## Usage

To use Pipex, run the following command:
```
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
This command redirects the output of `cmd1` with the input of `cmd2`, the output of `cmd2` with the input of `cmd3`, and so on, until the output of `cmdn` is redirected to `file2`. 

In other words, this command behaves like:
```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

You can also use Pipex with a here document by running the following command:
```
./pipex here_doc LIMITER cmd cmd1 file
```
This command redirects the output of `cmd` with the input of `cmd1`, and then redirects the output of `cmd1` to `file` using a here document delimited by `LIMITER`.

In other words, this command behaves like:
```
cmd << LIMITER | cmd1 >> file
```

## Compile

To compile the executable run the command
```
make pipex
```
