# motor

! 以无动力轮方向所在方向为正方向

## 马达方向


me:

when you face the outside of the wheel
A : left wheel
B : right wheel

 A - 1B = 0 clockwise
 A - 1A = 0 countercw

 B - 2A = 0 countercw
 B - 1A = 0 clockwise


!!!!!!!!!!!**unvertified below**!!!!!!!!!!!!!!!!!!

### forwords & backwords
1. forwords

A-1A = B-1A = 0;
A-1B = B-2A = 1;

2. backwords

A-1B = B-2A = 0;
A-1A = B-1A = 1;

### turn

#### turn left

1. keep A wheel still

*still*


    A - 1B = 1 clockwise
 
    A - 1A = 1 countercw

    B - 2A = 1 countercw

*move*

    B - 1A = 0 clockwise


2. keep B wheel still

*still*

    B - 1A = 1 clockwise

    B - 2A = 1 countercw

    A - 1B = 1 clockwise

*move*

    A - 1A = 0 countercw

#### turn right

1. keep A wheel still

*still*


    A - 1B = 1 clockwise
 
    A - 1A = 1 countercw

    B - 1A = 0 clockwise

*move*

    B - 2A = 1 countercw


2. keep B wheel still

*still*

    B - 1A = 1 clockwise

    B - 2A = 1 countercw

    A - 1A = 0 countercw

*move*

    A - 1B = 1 clockwise

### spin

1. clockwise spin

    left(A) wheel counter clockwise 
    right(B) wheel clockwise
    
    A - 1A = 0 countercw
    A - 1B = 1 clockwise
    B - 1A = 0 clockwise
    B - 2A = 1 countercw

2. counterwi spin

    right(B) wheel counter clockwise
    left(A) wheel clockwise

    A - 1A = 1 countercw
    A - 1B = 0 clockwise
    B - 1A = 1 clockwise
    B - 2A = 0 countercw