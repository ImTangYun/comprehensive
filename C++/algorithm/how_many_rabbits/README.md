现在有一种兔子：
1.刚出生的小兔子需要2个月才能性成熟
2.性成熟的兔子需要孕育1个月才能生产
3.一对兔子每胎生产一对兔子
4.兔子寿命是25个月

第一年有一对刚出生的兔子，问题：
1.第7个月有多少对兔子
2.第30个月有多少对兔子

解决方案分析：
                
                第n年   第n+1年 第n+2年 第n+3年

刚出生          x       z       y+z     x+y+z

出生一年        y       x       z       y+z

性成熟          z       y+z     x+y+z   x+y+2z

f(n) = x+y+z
f(n+1) = x+y+z
f(n+2) = x+2y+3z
f(n+3) = 2x+3y+4z

=>f(n+3) = f(n) + f(n+2)

