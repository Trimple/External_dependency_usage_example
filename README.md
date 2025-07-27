# External_dependency_usage_example
Repo with examples for the main approaches to use own external dependencies in C/C++.

Documentation for this repo is not finished. I made these exapmles for myself to make a decision and it was obviouse without finishing everything. So I only documented most imporatant points for decision making.

This repository shows examples of 3 different dependency management approaches:
1. Using CMake and FetchContent;
2. Using git submodules;
3. Using independent external git repository;

All code in the repo is built using CMake. To properly follow the examples and build/test all the code you will need:
1. **CMake 3.10** or newer;
2. Any build system, this particular example uses **Ninja**, but makefiles or anything else will also work.
3. Any C++ compiler that is available through command line.

## CMake and Fetch Content approach

This approach is based on the **FetchContent** functionality of **CMake** that allows to download code from any link (including git repositories). To make this example work (with dependencies) you need:
1. **CMake 3.10** or newer;
2. Any build system, this particular example uses **Ninja**, but makefiles or anything else will also work.

You don't need to have anything else to 

### How to test
#### How to initially load dependencies

1. Open cmake_based_source folder in shell of choice;
2. Create a build repo, usually:
```bash
mkdir build
```
3. cd into build directory:
```bash
cd build
```
4. Generate build files (this example uses Ninja, but any other CMake generator will work):
```bash
cmake -G "Ninja" ..
```
at this point all dependencies will be downloaded and can be used even if target project doesn't use CMake for building.  

---

#### How to update dependencies
If target project uses CMake itself, dependencies will be checked for updates every time the project is built.

If target project doesn't use CMake run generagor command from *build* directory every time you need to update dependencies (not sure, this step may requrie verification):
```bash
cmake -G "Ninja" ..
```

---

#### How to build examples:

1. open *build* folder in a shell of choice.

2. Build code:
```bash
cmake --build .
```
3. Run example executables that will be called **cmake_cmake_example** and **cmake_no_cmake_example**.




### How to use / support
Examples from this repo only work when dependency repo is public. Though it is possible to make it work with private repo as well.

**todo**: add explanation/exapmle for private repo or a link that describes the process.

**Approach advanatages**:
- Doesn't need any input at all from people who needs to develop code without touching dependendcies directly;
- Directly supports CI/CD;
- Makes building relatively easy if target project uses CMake as well;
- All dependencies are linked to CMake files that call FetchContent and therefore there are no issues with using this approach with monorepos;

**Approach disadvantages**:
- Doesn't allow to push changes to dependencies through dependencies themselves;
- Requires separate "build" folder to download external dependencies to, and if these dependencies generic and not CMake based it becomes a bit of a pain to load them into the projects as they are stored together with a lot of CMake files;
- To update dependencies to latest version you need to run CMake generator everytime if the target projet doesn't use CMake itself and there is absolutely no indication if there are any updates for dependencies.

**How to add new dependency**
**todo**: add if needed

### Opinion

After writing down all disadvantages it became quite clear that this is not a good way for working with generic dependencies (that may include not only code, or code that is not supposed to be built with CMake).

**todo**: Extend if needed

## Git submodules approach

### How to test



### How to use / support

**Approach advanatages**:
- Dependencies repo is added directly to the root of the target repo, which is very easy to use with any building approach;
- Allows pushing changes back to the repository with dependencies;
- Dependency can be added to any place inside target folder (not necessary into root);
- The same dependency can be used multiple times for monorepos (and can be added to different locations for every instance);

**Approach disadvantages**:
- Requires direct usage of git commands for dependencies update;
- Somewhat easy to mess up by people without a lot of experience or active practice with submodules;
- Requires a commit every time dependencies are update (maybe this not a bad thing, but more netural. Maybe it is even useful, as it will clearly show, with what dependency commit the build is made);
- Can become messy if used with GUI and there are changes to dependencies in multiple different projects;
- Requires a manual update every time for every single repo that uses this dependency. Can be automated using CI/CD, but this increases the amount of hustle quite significantly;

### Opinion
After experimenting with all 3 approaches it seems like this one it the best one out of all 3. It defenetely has a learning curve needed to make it work. But it also doesn't have any disadvantages, that would break any workflow at least I have in mind. 

## Independent repo approach

### How to test


### How to use / support

**Approach advanatages**:
- You always have only one version of the repo installed, and therefore it is easy to track and comprehend changes. Probably the cleared approach when used with many repositories at the same time;
- Single repo also makes it easy to update all local repositories, as you only nee
- Very hard to mess up even with almost no experience;

**Approach disadvantages**:
- Requires a bit of hustle with most building approaches because it is "out of source build". Makes adding new dependency files somewhat labor-intensive.
- Syntax highliting and code jumping will not work in VSCode if only folder with target is open, therefoer this approach will require to open a folder that stores all project folders, which will add more components to the tree that you may want to have (it is ok to have 2 projects - target and deps, but if deps are needed, usually there are more than 1 target and all of them will be visible at the same time. It becomes even worse, when target project is not in the root of its repo);
- Probably a bit of a pain to use with CI/CD (need confirmation if it is hard to pull multiple repos in CI/CD, if not, that this is not a problem, but just a property);



### Opinion

This approach has it flaws, but also has quite significant advantages. I think it has a right to exist and is probably the most useful where dependencies are a mono repo with lots of code and it is used in many projects at the same time.




To clone submodules into a newly cloned project use:

``` bash
git submodule update --init
```