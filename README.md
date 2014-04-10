QCCableConnections
==================

This Quartz Composer plugin makes connections bend more like cables:

[![](https://raw2.github.com/Ciechan/QCCableConnections/master/good.png)](https://raw.github.com/Ciechan/QCCableConnections/master/good.png)

Reasoning
---------

I can't stand the way back-pointing connections are drawn in Quartz Composer:

[![](https://raw2.github.com/Ciechan/QCCableConnections/master/bad.png)](https://raw.github.com/Ciechan/QCCableConnections/master/bad.png)

This is so wrong. The outgoing connections should go *out* of the patch. The incoming connections should go *into* the patch. Real-life cables are plugged from outside in, not the other way around.

Benefits
--------

- Easier flow reading
- No ambiguity

Installation
------------

Either build in Xcode and you're done, or copy the unzipped plugin directly into the destination folder:


	unzip Builds/QCCableConnections.plugin.zip -d ~/Library/Graphics/Quartz\ Composer\ Patches
	
Contact
-------
[Bartosz Ciechanowski](http://ciechanowski.me)

License
-------

QCCableConnections is released under an MIT license.

Copyright (c) 2014 Bartosz Ciechanowski



