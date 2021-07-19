===== blobutils =====

Tools to manipulate binary data in Unix, because it was a nightmare.

They are not fast (written in shell and Python), I usually need to convert only several bytes, so it does not matter.

http://jenda.hrach.eu/gitweb/?p=blobutils;a=summary

Terms: bin: raw binary data; bits: ascii '0' and '1'; hex: ascii hexdump

blbgrep: grep binary file
<code>
  
> blbgrep data.bin 04 ee 04 7e
  
data.bin:<offset>
  
</code>
blbinhex: hexdump (binary to hexa)

blbithex: bits to hex
<code>
> echo 1110 0011 | blbithex
E3
</code>

blcstruct: unpack C structure, e.g. "blcstruct f" unpacks array of floats

blhexbin: hex to binary

blhexbit: hex to bits

blhexbitmap: hex to black and white image (e.g. adafruit gfx format)
<code>
echo 22 54 54 78 42 | blhexbitmap
  
██ ███ █
  
█ █ █ ██
  
█ █ █ ██
  
█    ███
  
█ ████ █
  
</code>

blhexflip: interactive binary editor

blhexrev: no idea

blrev: MSB to LSB format

blxor: 64bit xor (used heavily during implementation of A5/1 cracker)

dechex, dechex: base convert

gp.sh: 1D data plot. First column is label, second value. Parameter is filename.
<code>
echo -e "bla -7.247 \nble 3.28 \nfoo 0.3 \nxx 1" | gp.sh my_numbers
</code>

gr-pack, gr-unpack: convert binary to gnuradio bytes and back

itemize: add line numbers (I did not know about nl command back then)

sum.sh: sum numbers, one per line
<code>
echo -e "-7.247 \n 3.28 \n 0.3 \n 1" | sum.sh
  
-2.667
</code>

udate: unix timestamp to human-readable date
