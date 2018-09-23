import pyxel
import random

class App:
    def __init__(self):
        #Game Window
        #how many times drawn

        self.run = 0
        self.width = 160
        pyxel.init(self.width, 120)
        pyxel.image(0).load(0, 0, 'assets/cat_16x16.png')

        #Character
        self.x = 0
        self.y = 0
        self.current_score = 0

        #Bullets
        self.bullet_x = 0
        self.bullet_y = 0
        self.bullet = False
        self.bullets = []


        #Set up the original enemies
        self.first = True

        #Adding num_enemies
        self.hit = False
        self.targets = []
        self.speed = 0.3

        pyxel.run(self.update, self.draw)

    def update(self):
        self.update_player()
        self.update_bullet()
        self.update_enemies()
        self.update_hit()
        self.update_targets()
        self.update_collision()

    def update_player(self):
        if pyxel.btn(pyxel.KEY_A):
            self.x -=2
        if pyxel.btn(pyxel.KEY_D):
            self.x +=2
        if pyxel.btn(pyxel.KEY_S):
            self.y +=2
        if pyxel.btn(pyxel.KEY_W):
            self.y -=2



    def update_bullet(self):


        if pyxel.btnp(pyxel.KEY_SPACE) == True:
            self.bullet = True
            self.bullet_x = self.x +5
            self.bullet_y = self.y
        if self.bullet == True:
            self.bullet_x +=3


        if self.bullet_x > self.width:
            self.bullet = False



    def update_enemies(self):
        self.num_enemies = random.randint(1,5)

    def update_collision(self):
        center_x = self.x + 4
        center_y = self.y +4
        for k in range(0, len(self.targets)):
            if abs(center_x - self.targets[k][0]) < 6 and abs(center_y - self.targets[k][1])<6 and self.targets[k][3]==1:
                self.current_score -=1

    def update_hit(self):

        self.hit = False
        for k in range(0, len(self.targets)):
            if abs(self.bullet_x+9 - self.targets[k][0])<7 and abs(self.bullet_y+9 -self.targets[k][1])<7:
                self.targets[k][3] = 3
                self.current_score += 1
                self.hit = True



    def update_targets(self):
        if self.run%100 ==0:
            self.speed += 0.1
        for k in range(0,len(self.targets)):
            self.targets[k][0] -= self.speed
            #self.targets[k][1]+= 0.5

    def get_targets(self):
        if self.first == True:
            for k in range(0,5):
                x = random.randint(160,320)
                y = random.randint(0,100)
                radius = 5
                colour = 1
                self.targets.append([x,y,radius,colour])

        if self.run %50 == 0:
            target_num = random.randint(0,5)
            for l in range(0,target_num):
                x = random.randint(160,250)
                y = random.randint(0,100)
                radius = 5
                colour = 1
                self.targets.append([x,y,radius,colour])
        else:
            return self.targets


        return self.targets

    def get_colour(self):
        num = random.randint(0,6)
        if num == 0 or num==4:
            return 8
        if num == 1 or num ==3:
            return 12
        if num ==2:
            return 14
        else:
            return 10


    def draw(self):



        pyxel.cls(0)


        player_colour = self.get_colour()

        pyxel.rect(self.x, self.y, self.x + 16, self.y+16, player_colour)

        pyxel.blt(self.x, self.y , 0, 0, 0, 16, 16,0)


        targets = self.get_targets()
        for k in targets:
            for i in range(0,4):
                pyxel.circ(k[0],k[1],k[2],k[3])
            self.first =False

        # if run%100 == 0:
        #     new_circle = (random.randint(30,160),random.randint(1,160),5,3)
        #     self.targets.append(new_circle)



        #For shooting the bullet not enemy generation!
        if self.bullet==True:
            pyxel.rect(self.bullet_x, self.bullet_y+8, self.bullet_x + 9, self.bullet_y + 9,12)

        #!! Currently enemies are those background dots
        # BACKGROUND DOTS
        for x in range(0,self.num_enemies):
            x = random.randint(1,160)
            y = random.randint(1,120)
            pyxel.rect(x, y , x+1,y+1,13)


        pyxel.text(2,2,"Score: "+str(self.current_score),7)

        if self.current_score <0:
            pyxel.cls(0)
            i = 0
            while i < 1000:

                colour = i%15
                pyxel.text(40,60,"You Died Motha Fucka", 15)

                i+=1
        self.run +=1


App()
