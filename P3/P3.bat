
del p3.out

REM Circle
P3.exe /circle /i < circle_3D_v2.txt > p3.out
P3.exe /circle /p 1.0 10.0 >> p3.out

REM Annulus
P3.exe /annulus /i < annulus_3D_v2.txt > p3.out
P3.exe /annulus /p 1.0 0.5 10.0 >> p3.out

REM rectangle_filled
P3.exe /rectangle_filled /i < rectangle_filled_3D_v2.txt > p3.out
P3.exe /rectangle_filled /p 1.0 2.0 10.0 >> p3.out

REM rectangle_hollow
P3.exe /rectangle_hollow /i < rectangle_hollow_3D_v2.txt > p3.out
P3.exe /rectangle_hollow /p 2.0 0.75 2.0 1.5 10.0 >> p3.out

REM Help + Nonsense example
P3.exe /h >> p3.out

P3.exe poqiwejh9fyu32189042183usdhakfhu90324yrfwuoqeahsfuaowefu