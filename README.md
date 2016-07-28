seq2gif
=======
[![Build Status](https://travis-ci.org/saitoha/seq2gif.svg?branch=master)](https://travis-ci.org/saitoha/seq2gif)
[![Coverage Status](https://img.shields.io/coveralls/saitoha/seq2gif.svg)](https://coveralls.io/r/saitoha/seq2gif)


Description
------------

This software converts a sequences record file generated by [ttyrec](https://github.com/mjording/ttyrec)
into a gif animation directly(without taking screenshots),
by using portable built-in terminal emulation engine originated
from [yaft](https://github.com/uobikiemukot/yaft).
[yaft](https://github.com/uobikiemukot/yaft) provides rare terminal emulation
features such as SIXEL/DRCS.


Demo
----

Play [sl](https://github.com/mtoyoda/sl).

![img2sixel](https://raw.githubusercontent.com/saitoha/seq2gif/master/images/sl.gif)


Show SIXEL animation with [img2sixel](https://github.com/saitoha/libsixel#img2sixel).

![img2sixel](https://raw.githubusercontent.com/saitoha/seq2gif/master/images/sixel.gif)


The following demo plays [sl](https://github.com/mtoyoda/sl) and records it with [ttyrec](https://github.com/mjording/ttyrec), and
converts that record into a GIF animation using seq2gif,
and converts that GIF into a SIXEL animation and plays it with [img2sixel](https://github.com/saitoha/libsixel#img2sixel).
Furthermore, generates the log record of above experience using [ttyrec](https://github.com/mjording/ttyrec), and
converts that log into the following GIF animation.

![ttyrec](https://raw.githubusercontent.com/saitoha/seq2gif/master/images/ttyrec.gif)


Download
--------
Source package and Windows binary is [available](https://github.com/saitoha/seq2gif/releases/).


Build and Install
-----------------

This software works in Windows, Linux, BSDs and OSX.
If you want to build windows native build, [MinGW](http://www.mingw.org/) is required.

```
  $ ./configure
  $ make
  # make install
```

Packages
--------

- [FreeBSD ports](http://portsmon.freebsd.org/portoverview.py?category=graphics&portname=seq2gif)


Usage
-----

```
Usage: seq2gif [Options] < ttyrecord > record.gif
       seq2gif [Options] -i ttyrecord -o record.gif

Options:
-w WIDTH, --width=WIDTH                specify terminal width in cell size.
                                       (default: 80)
-h HEIGHT, --height=HEIGHT             specify terminal height in cell size.
                                       (default: 24)
-l DELAY, --last-frame-delay=DELAY     specify delay in msec which is added
                                       to the last frame. (default: 300)
-f COLORNO, --foreground-color=COLORNO specify foreground color palette.
                                       number.
-b COLORNO, --background-color=COLORNO specify background color palette
                                       number.
-c COLORNO, --cursor-color=COLORNO     specify cursor color palette
                                       number.
-t TABSTOP, --tabstop=TABSTOP          specify hardware tabstop(default: 8)
-j, --cjkwidth                         treat East Asian Ambiguous width
                                       characters (UAX#11) as wide.
-r COUNT, --repeat=COUNT               specify animation repeat count. loop
                                       infinitely if 0 is given. (default: 0)
-i FILE, --input=FILE                  specify input file name. use STDIN
                                       if '-' is given. (default: '-')
-o FILE, --output=FILE                 specify output file name. use STDOUT
                                       if '-' is given. (default: '-')
-V, --version                          show version and license information.
-H, --help                             show this help.
-I DELAY, --render-interval=DELAY      skip frames with smaller delays than
                                       DELAY specified in milliseconds.
                                       (default: 20)
-s NUM, --play-speed=NUM               specify the factor of the play speed.
                                       A larger value means faster play.
                                       (default: 1.0)
-m COLORMAP, --colormap=COLORMAP       specify a colormap from the following
                                       list (default: xterm256):
                                         rgb332   -> R:3bit, G:3bit, B:2bit
                                         xterm256 -> xterm 256color
```


Acknowledgements
----------------

### recterm

This program is derived from [recterm](https://github.com/uobikiemukot/recterm)
written by haru <uobikiemukot at gmail dot com> ([@uobikiemukot](https://github.com/uobikiemukot/))

### yaft

Some part of glyph data generator(glyph/*) is imported from [yaft](http://uobikiemukot.github.io/yaft/)
written by haru <uobikiemukot at gmail dot com> ([@uobikiemukot](https://github.com/uobikiemukot/))

### gifsave89

GIF encoder (gifsave89.c) is imported from [gifsave89](http://www.forkosh.com/gifsave90.html)
distributed under GPLv3+ by [John Forkosh Associates, Inc.](http://www.forkosh.com)(john@forkosh.com)

### milkjf
This package includes a milkjf font and its derivative(gryph/milkjf.h).
Original milkjf font was designed by japanfarm (Nihon-Nouen) and used on Sharp X68000 series.
Chisato Yamauchi converted milkjf font to bdf for X Window System.
haru([@uobikiemukot](https://github.com/uobikiemukot/)) converted it to a C-styled header file.

### M+ BITMAP FONTS
This package includes [M+ Bitmap Font](http://mplus-fonts.sourceforge.jp/mplus-bitmap-fonts/index.html)
and its derivative(gryph/mplus.h).

License:

```
M+ BITMAP FONTS            Copyright 2002-2005  COZ <coz@users.sourceforge.jp>

LICENSE

These fonts are free softwares.
Unlimited permission is granted to use, copy, and distribute it, with
or without modification, either commercially and noncommercially.
THESE FONTS ARE PROVIDED "AS IS" WITHOUT WARRANTY.
```

### GNU Unifont
This package includes [GNU Unifont Glyphs](http://unifoundry.com/unifont.html)
and its derivative(gryph/unifont.h).

License: GPLv2+
http://unifoundry.com/LICENSE.txt


```
M+ BITMAP FONTS            Copyright 2002-2005  COZ <coz@users.sourceforge.jp>

LICENSE

These fonts are free softwares.
Unlimited permission is granted to use, copy, and distribute it, with
or without modification, either commercially and noncommercially.
THESE FONTS ARE PROVIDED "AS IS" WITHOUT WARRANTY.
```

### M+ BITMAP FONTS
This package includes a C header file derived from M+ font(gryph/mplus.h).


### Markus Kuhn's wcwidth
This package includes Markus Kuhn's wcwidth(mk_wcwidth)

```
Markus Kuhn -- 2007-05-26 (Unicode 5.0)

Permission to use, copy, modify, and distribute this software
for any purpose and without fee is hereby granted. The author
disclaims all warranties with regard to this software.

Latest version: http://www.cl.cam.ac.uk/~mgk25/ucs/wcwidth.c
```

Contributors
-------------

- [@arakiken](https://bitbucket.org/arakiken/profile/repositories)
- [IWAMOTO Kouichi(@ttdoda)](https://github.com/ttdoda)


Similar Software
----------------

### [sugyan/ttyrec2gif](https://github.com/sugyan/ttyrec2gif)

This also generates GIF animation without taking screenshots, written in [Go](http://golang.org/).
Using [j4k.co/terminal](http://godoc.org/j4k.co/terminal) as terminal emulation engine().
It is derived from [sugyan/ttygif](https://github.com/sugyan/tty2gif).


### [uobikiemukot/recterm/tools/rec2gif.c](https://github.com/uobikiemukot/recterm/blob/master/tools/rec2gif.c)

Additional tools which uses [yaft](https://github.com/uobikiemukot/yaft) terminal emulation engine,
distributed with [uobikiemukot/recterm](https://github.com/uobikiemukot/recterm/).


References
----------

### [ttyrec](http://0xcc.net/ttyrec/index.html.en)

A tty recorder.

### [ttyrec4windows](https://github.com/mattn/ttyrec4windows)

A Windows port for [ttyrec](http://0xcc.net/ttyrec/index.html.en) written in [Go](http://golang.org/).


License
-------

![GPLv3](https://raw.githubusercontent.com/saitoha/seq2gif/master/images/gplv3.png)

