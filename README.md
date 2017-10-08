# EasyHub
> Version 2.7

## What is EasyHub ?
> EasyHub is a command-line tool developed in C++ for Windows users, It helps developers
> to navigate threw their different application/environment more easily

## How it works ?

There are different commands:

### Create variable linked to path
type: `define my_var "C:/My/Path" cd`  
*Be Careful*: - your variable cannot contains spaces,  
- the path parser accepts the '"' character in case of your path contains spaces
- `cd` is the method, here cd is to open a Windows Command-Line linked to the path

### Create variable linked to executable
type: `define my_var "C:/My/Path/some_executable.exe exec`

### Delete a variable
type: `delete my_var`

### Create an environment variable
There are two possibilities of environment variable
- One will add some path to the `PATH` variables of Windows: type: `env add my_var "C:/My/Path" path`
- The other one will add the given name linked to the given path (Ex: `my_path=C:/My/Path`): type: `env add my_path "C:/My/Path" none`. `none` significates that it'll be added as a normal environment variable

### Remove an environment variable
type: `env remove my_var`

### Save variables in a config file
config files can be whatever you want, in this example I'll use config.ezh  
type: `save C:/Users/minot0r/Desktop/config.ezh`  
*Tip*: The path can contains quotes '"'

### Load my config file
type: `load C:/Users/minot0r/Desktop/config.ezh`  
*Tip*: The path can contains quotes '"'

### Open a new windows command-line
type: `cmd`


## Is it dangerous ?
> Of course it isn't, the environment variables are loaded only in the EasyHub environment,
> and EasyHub cannot modify your Windows settings, and also doesn't require any privileges
