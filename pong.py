import pyxel

class App:
    def __init__(self):

        self.SCREEN_W = 200
        self.SCREEN_H = 120
        pyxel.init(self.SCREEN_W, self.SCREEN_H)

        #Computer player
        self.comp_x = 10
        self.comp_y = 5
        self.comp_length =20
        self.comp_down= True
        self.comp_up = False

        #Player One
        self.x = 190
        self.y = 4
        self.player_speed = 1

        #Scoring
        self.score = 0
        self.score_change = False

        #Game ball
        self.ball_x = self.SCREEN_W * 0.5
        self.ball_y = 0
        self.ball_down = True
        self.ball_right = True
        self.ball_speed = 1


        pyxel.run(self.update, self.draw)


    def update(self):
        self.update_ball()
        self.update_comp()
        self.update_player()
        self.ball_collision()

    def ball_collision(self):

        if self.ball_x +2 == self.x and self.ball_y >= self.y and self.ball_y<=self.y +20:
            if self.ball_right:
                self.ball_right = False
        if self.ball_x == self.comp_x  and self.ball_y >= self.comp_y and self.ball_y <= self.comp_y + self.comp_length:
            if self.ball_right ==False:
                self.ball_right =True

    def update_comp(self):
    #The computer player movements
        if self.comp_down:
            self.comp_y +=2
            if self.comp_y > self.SCREEN_H -22:
                self.comp_y += 1.5 *self.player_speed
                self.comp_down = False
                self.comp_up = True

        if self.comp_up:
            self.comp_y -=2
            if self.comp_y <= 0:
                self.comp_y -= 1.5 * self.player_speed
                self.comp_up = False
                self.comp_down = True

    def update_player(self):

        if pyxel.btn(pyxel.KEY_UP):
            if self.y >= 0 :
                self.y -= self.player_speed

        if pyxel.btn(pyxel.KEY_DOWN):
            if self.y <= self.SCREEN_H - 20:
                self.y += self.player_speed

    def update_ball(self):

        # if self.score_change == True:
        #     self.ball_speed +=1
        #     self.player_speed +=1
        #     self.score_change = False

        # if self.score > 1:
        #     self.ball_speed += 2
        #     self.player_speed +=1
        # elif self.score > 3:
        #     self.ball_speed += 1
        # elif self.score > 5:
        #     self.ball_speed
        #     self.player_speed

        if self.ball_down:
            self.ball_y += self.ball_speed
            if self.ball_y >= self.SCREEN_H-2:
                self.ball_down = False
                self.ball_y -=self.ball_speed
        elif self.ball_down == False:
            self.ball_y -=self.ball_speed
            if self.ball_y <= 0:
                self.ball_down =True
                self.ball_y +=self.ball_speed

        if self.ball_right:
            self.ball_x +=self.ball_speed
            if self.ball_x >= self.SCREEN_W -2 :
                self.ball_right = False
                self.ball_x -= self.ball_speed
                self.score -=1
        elif self.ball_right == False:
            self.ball_x -= self.ball_speed
            if self.ball_x <= 0:
                self.ball_right = True
                self.ball_x += self.ball_speed
                self.score +=1


    def draw(self):
        pyxel.cls(0)

        #Surface Midline
        pyxel.line(100,0,0.5*self.SCREEN_W,self.SCREEN_H,7)

        #Computer Player line
        pyxel.rect(self.comp_x, self.comp_y, self.comp_x + 1, self.comp_y +self.comp_length, 7)

        #Player One
        pyxel.rect(self.x, self.y, self.x + 1, self.y+20, 12)

        #Game Ball
        pyxel.rect(self.ball_x,self.ball_y,self.ball_x + 2, self.ball_y +2, 7)

        #Game SCORE
        pyxel.text(2,self.SCREEN_H-10,"Score: "+str(self.score),7)



App()
