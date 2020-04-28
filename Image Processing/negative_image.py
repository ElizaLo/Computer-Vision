import image

img = image.Image("/Downloads/feather-girl.png")
#img = image.Image("/Downloads/istockphoto-1130414550-170667a.jpg")

win = image.ImageWin(img.getWidth(), img.getHeight())

for row in range(img.getHeight()):
    for col in range(img.getWidth()):
        img.draw(win)
        p = img.getPixel(col, row)

        newred = 255 - p.getRed()
        newgreen = 255 - p.getGreen()
        newblue = 255 - p.getBlue()

        newpixel = image.Pixel(newred, newgreen, newblue)

        img.setPixel(col, row, newpixel)
        img.draw(win)

#img.draw(win)
win.exitonclick()

