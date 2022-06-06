# New Codeforces' Polygon Problem Package Template

User's checklist:

0. Metadata, including link to problem statement if PDF
1. Main correct solution
2. Samples
3. Validator
4. Checkers
5. Input generators
6. Input generation scripts

Including:

- `METADATA.json` include all metadata. Check form on polygon to see which infos are needed.
- `solutions/` for solutions. `main.cpp` is main correct solution to generate output.
- `samples-concatenated.txt` text files included all example tests.
- `checkers/` included all standard checkers for codeforces. Template for customized checkers NOT included.
- `validatow.cpp` template for input validator. Including documentation for usage and possible warnings.
- `generators/basic.cpp` for basic input generation.
`generators` is separated into a folder since there maybe multiple generator files for more complex problems.
- `genscript.txt` instruction to generate input.
- `testlib.h`

To be included:

- `.gitignore` to ignore generated output files.
- scripts to run all solutions and generate table to check its runtime.
- customized checkers template.
