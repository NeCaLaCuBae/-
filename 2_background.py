import pygame

pygame.init() #초기화*필수*

#화면크기설정
screen_width = 480 #가로크기
screen_height = 640 # 세로 크기
screen = pygame.display.set_mode((screen_width, screen_height))

#화면타이틀설정
pygame.display.set_caption("Nado Game") #게임이름

#배경이미지불러오기
background = pygame.image.load("C:/Users/user/Documents/Python Workspace/background.png")
#이벤트루프
running = True #게임이진행중인가?
while running:
    for event in pygame.event.get(): #어떤이벤트가발생하였는가?
        if event.type == pygame.QUIT: #창이닫히는이벤트가발생하였는가?
            running = False #게임이진행중이아님
    screen.blit(background, (0, 0, 255)) 
    #screen.blit(background, (0, 0)) #배경그리기
    
    pygame.display.update() #게임화면을다시그리기!
#pygame종료
pygame.quit()