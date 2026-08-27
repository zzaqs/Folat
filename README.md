# Folat 0.3.0-alpha
Folat is a Finite State Machine (FSM) esolang, inspired by Assembly and tools that display aligned blocks of data and text, like `objdump`, and use fixed-width parsing to process the text. Folat was created on December 7, 2025, by the user @zzaqs (GitHub).

# Memory components
- `MEM`/`mem` being an array of 256 bytes.
- `FLG`/`flg` being a simple variable that changes to true or false.

# Syntax
As said before, Folat uses fixed-width parsing, the instructions and the two arguments must have exactly 3 characters and a space between them. Each line of the program must have 11 characters, or else the error `foli [X]: Line does not meet the minimum character limit (11).` Will happen, because the instructions and the two arguments are obligatory. Even so, some instructions, like the segments or `jmp`, cannot use all the arguments, so you can put anything in there that the instruction will ignore. Always operate with numbers to 0-255 and in 3 chars.

# Instructions
## Arithmetic
- `add trg dat`: `mem[trg] += dat`.
- `sub trg dat`: `mem[trg] -= dat`.
- `div trg dat`: `mem[trg] = mem[trg] / dat`.
- `mul trg dat`: `mem[trg] = mem[trg] * dat`.
- `mod trg dat`: `mem[trg] = mem[trg] % dat`.

## Utilities
- `set trg dat`: `mem[trg] = dat` (decimal value!).
- `out trg dat`: just print `trg` and `dat`, but with formatting (`-` are ignored, `\` are replaced by a break line in terminal).
- `ext trg dat`: exit the program, `trg` is the exit code, and `dat` is a bool (`000`/`fal` or `001`/`tru`) indicating if must have a break line at the end.
- `msl trg dat`: print a memory slice, `trg` or `dat` are the start index, and the other is the end index.

## Segments
**Segments just enable execution permission if the seek symbol matches with the segment symbol**
- `--- trg`: declare a segment, `trg` is his symbol.
- `cmp trg dat`: if `mem[trg] == dat`, `flg` is true, otherwise, it's false.
- `jwc trg dat`: native from interpreter, start seeking the segment of symbol `trg` if `dat` matches with the `flg` state.
- `jmp trg`: native from interpreter too, start seeking the segment of symbol `trg`.

# Starting
Here are all the steps:
```bash
$ git clone https://github.com/zzaqs/folat
$ cd Folat
$ make # build
$ make i # optional, add binary to '/usr/local/bin/'
$ foli test/abc.f # testing
```
All other explained examples in Folat are visible in the "test" folder.

# External Resources
- [Folat esolang page](https://esolangs.org/wiki/Folat)
