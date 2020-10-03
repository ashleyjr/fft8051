import sys
import os
import numpy
from PIL import Image, ImageDraw, ImageFont
import argparse

FONTFILE = 'tools/imageGen/Dance.ttf'
MAX      = 255
THRESH   = MAX /2
X        = 32
Y        = 16

def main(line1, line2, fontsize, var):
    # name of the file to save
    fnt = ImageFont.truetype(FONTFILE, fontsize)
    # create new image
    image = Image.new(mode = "RGB", size = (X,Y), color = "black")
    draw = ImageDraw.Draw(image)
    draw.text((0,0),    line1, font=fnt, fill=(MAX,MAX,MAX))
    draw.text((0,Y/2),  line2, font=fnt, fill=(MAX,MAX,MAX))
    # Turn to numpy
    m = numpy.asarray(image.convert('L'))
    # Print the code
    print "static const U16 "+var+"["+str(X)+"] = {"
    for i in range(X-1,-1,-1):
        s = "0b"
        for j in range(Y-1,-1,-1):
            if(m[j,i] > THRESH):
                s += '0'
            else:
                s += '1'
        if(i != 0):
            s += ','
        print s
    print "};"
    return

if "__main__" == __name__:
    parser = argparse.ArgumentParser(description='fft8051 display text gen.')
    parser.add_argument('--line1',  default="",     type=str,   help='Top line')
    parser.add_argument('--line2',  default="",     type=str,   help='Bottom line')
    parser.add_argument('--size',   default="10",   type=int,   help='Size of font')
    parser.add_argument('--var',    default="disp", type=str,   help='Variable name')
    args = parser.parse_args()
    main(args.line1, args.line2, args.size, args.var)

