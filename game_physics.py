import pyxel

class App:
    def __init__(self):
        pyxel.init(160, 120)
        self.x = 10
        self.y = 95

        pyxel.run(self.update, self.draw)

    def update(self):

        if pyxel.btnp(pyxel.KEY_W):
            self.y -= 8
        if pyxel.btn(pyxel.KEY_D):
            self.x +=2
        if pyxel.btn(pyxel.KEY_A):
            self.x-=2

        self.update_collision()
    def update_collision(self):
        if self.y >=95:
            self.y =95
    def draw(self):
        pyxel.cls(0)
        pyxel.rect(0,100,160,120,4)
        pyxel.rect(0,100,160,105,3)



        self.y +=1
        pyxel.rect(self.x,self.y,self.x + 4, self.y+4,10)

App()
