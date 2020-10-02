import sys
import os
import numpy
from PIL import Image, ImageDraw, ImageFont


def main(argv):
    # name of the file to save
    filename = "img02.png"
    fnt = ImageFont.truetype('Dance.ttf', 14)
    # create new image
    image = Image.new(mode = "RGB", size = (32,16), color = "black")
    draw = ImageDraw.Draw(image)
    draw.text((0,0), "TEST", font=fnt, fill=(255,255,255))
    # save the file
    image.save(filename)


    m = numpy.asarray(Image.open(filename).convert('L'))

    print m

    for i in range(31,-1,-1):
        s = "0b"
        for j in range(15,-1,-1):
            if(m[j,i] > 128):
                s += '0'
            else:
                s += '1'
        if(i != 0):
            s += ','
        print s


    return

if "__main__" == __name__:
    main(sys.argv)

