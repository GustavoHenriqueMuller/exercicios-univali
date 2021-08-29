import numpy as np
import cv2
from matplotlib import pyplot as plt
from matplotlib import image as mpimg

img = mpimg.imread("faustao.png")
img2 = cv2.imread("ricardo.png", 0)

def zoom ():
    plt.imshow(img)
    plt.xticks([]), plt.yticks([])  # Esconder os números dos gráficos
    plt.title("Faustop")
    plt.show()

def pb ():
    plt.imshow(img2, cmap = 'gray',  interpolation = 'bicubic')
    plt.xticks([]), plt.yticks([])  # Esconder os números dos gráficos
    plt.title("Ricardo")
    plt.show()

zoom()
cv2.waitKey(0)
pb()
cv2.waitKey(0)

cv2.destroyAllWindows()