# New Codeforces' Polygon Problem Template

Including:

- `generators/basic.cpp` for basic input generation.
`generators` is separated into a folder since there maybe multiple generator files for more complex problems.
- `genscript.txt` instruction to generate input.
- `validatow.cpp` template for input validator. Including documentation for usage and possible warnings.
- `testlib.h`
- `solutions/` for solutions. `main.cpp` is main correct solution to generate output.
- `METADATA.json` include all metadata. Check form on polygon to see which infos are needed.

To be included:

- `.gitignore` to ignore generated output files.
- scripts to run all solutions and generate table to check its runtime.
