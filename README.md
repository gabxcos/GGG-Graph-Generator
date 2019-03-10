# GGG
GGG stands for **GGG is a Graph Generator**, and it's an utility to generate all directed, connected graphs of a given amount of nodes in a .GFD format, used by [RI-DS](https://github.com/InfOmics/RI-DS) for subgraph matching.


### Context
The need for a single standard for direct graphs to be read and to work with led our team to coming up with a "converter" kind of solution.
We decided to uniform the input used by other softwares to a modified version of the one used by [RI-DS](https://github.com/InfOmics/RI-DS).
The **.GFD** format lists in the following order:
- the graph's path, descriptive of its stats
- the number of vetices
- a list of labels (in the form of numbers)
- a list of couples of vertices to represent the edges

Our version of the .GFD format provides the word "directed" or "undirected" in spite of the path (momentarily works on directed graphs only, because of our team's current needs, but it's easily extendable to undirected ones); it doesn't list any labels, as it is intended to generate all possible directed, connected graphs regardless of the different ways they can be labelled (future work on labels needed).

### How does it work?
First of all, it uses the utilities from the [nauty and Traces](http://pallini.di.uniroma1.it/) packages to generate the graphs, in the following way:
1) it generates all connected, undirected graphs of a given number of vertices with the `geng` utility
2) from the first output, the utility `directg` redirects the edges in all possible ways to create the complete set of directed graphs.
3) then the `showg` utility redirects the output to a single file called `strings.txt` where all the graphs are written in the form of their adjacency matrix.

This final text file is then elaborated by a routine written in C that takes every matrix and rewrites it as a list of edges in a separate file.

### How to use it
1) Install the latest version of [nauty and Traces](http://pallini.di.uniroma1.it/) (tested on v2.6 (r11) of nauty)
2) Add the folder with all of nauty utilities to your PATH variable (depends on OS used)
- alternatively, one could copy-paste the executables of `geng, directg & showg` in GGG's folder and edit the scripts, i.e. to call `./geng` instead of `geng`

3) Compile `main.c` as `main.o`
- with gcc: 
```
gcc main.c -o main.o
```

4) Use `GGG` as your current directory (cd). Run the script with the number of vertices [n] as argument (without brackets []):
- on Windows' Command Prompt:
```
gen-dg [n]
```
- on shell terminals:
```
./gen-dg.sh [n]
```

5) All .gfd generated files will be in the `results` folder.
