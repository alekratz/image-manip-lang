# image-manip-lang
(working title)

Are you tired of having to look up ImageMagick command options? Are you annoyed that every time you want to manipulate an image using ImageMagick, you have to make an intermediate image in some location on disk, before tying it all together? Well, wake up! This image-manip-lang may be the language for you.

Rather than having to ~~fight~~ work with bash, sh, fish, zsh - or whatever your preferred shell is - to get your image manipulation scripts working correctly, I propose having an entire programming language designed around ImageMagick's `convert` tool to make script-based image manipulation (and composition) a more natural task, rather than having ugly, difficult-to-maintain bash scripts.

Right now, image-manip-lang is such a prototype that it doesn't even have a name. It's very much in the "idea" stage - I just want to get this in code and see what works, what doesn't work, et cetera. However, there are some examples in the repository that give you a good look at what you can do with it.

## What's it look like?
That's a great question. Here's a simple script that will convert a single png image to a jpg image:

```
# Loads "image.png" into the img1 variable
load "image.png" img1
# Push img1 to the canvas; this is the last thing we do after manipulation
push img1
# Flush the canvas and write it to image.jpg
flush "image.jpg"
```

Here is a more sophisticated, robust version of that script; this checks to make sure all images passed to it are pngs:

```
set path arg.1
if ! is(path png)
    echo "Input path must be a png file!"
    exit
end if

# Go through all arguments
for img_arg in args.*
    # Load the argument into variable img
    load img_arg img
    # Resize the image
    resize 120x120 img
    # Calling functions don't use commas like they do in C
    # Function calls at a depth of 1 or greater uses parentheses
    push img
    flush format("converted%03d.png" img_arg.which)
end for
```

# License
Currently, I am holding all rights to the image-manip-lang until I get it more stable/concrete. There is a 100% chance that it will be under a permissive, open source license (I'm thinking BSD) - I just want to get the project more established before I start slapping licenses on it.