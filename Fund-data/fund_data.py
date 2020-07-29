# -*- coding = utf-8 -*-
# @Time : 2020/7/5 10:05
# @Author : 江城慕雪
# @File : fund_data.py
# @software:PyCharm

import re
import urllib
import requests
import pymysql


def main(str_num):
    print("开始网页爬取...")
    base_url = "https://finance.sina.com.cn/fund/api/xh5Fund/nav/"+str_num+".js"
    head = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36"
    }
    response = requests.get(base_url, head)
    print("数据获取成功,开始进行数据分析...")
    string = re.split('"', response.text)[3]  # 通过字符串切割获得想要的部分
    list = string.split("#")  # 将字符串切割成列表，每个元素为一天
    data_list = []
    for i in range(len(list)):
        list[i] = list[i].split(',')
        list[i][1] = float(list[i][1])
        list[i][2] = float(list[i][2])
    for i in range(0, len(list) - 1):
        list_cur = list[i]
        list_pre = list[i + 1]
        #if (list_pre[1] - list_cur[1] + list_cur[2] - list_pre[2] < 0.001):
        dif = list_cur[1] - list_pre[1]
        #else:
        #   dif = list_cur[2] - list_pre[2]
        change_range = format(100 * dif / list_pre[1],'.2f')
        change_range=float(change_range)
        list_cur = [list_cur[0], list_cur[1], list_cur[2], change_range]
        data_list.append(list_cur)
    print("数据处理完毕！！！")
    ##########################################数据保存#####################################
    print("准备连接")
    con = pymysql.connect(host='39.105.82.172', port=3306, user='root', passwd='jx19991022', database='fund_data')
    print("连接成功")
    cur = con.cursor()
    table_name = "N" + str_num
    sql_create = 'create table %s (data char(8) primary key unique,value float,added_value float,change_range float)' %table_name
    try:
        cur.execute(sql_create)
        print("创建表成功")
        for i in range(len(data_list)):
            data = data_list[i]
            sql_insert = 'insert into %s values (%s,%f,%f,%f) ' % (table_name,data[0], data[1], data[2], data[3])
            cur.execute(sql_insert)
    except pymysql.err.InternalError:
        print("基金表已存在，启动数据更新操作")
        data = data_list[0]     # 最新的一条数据
        sql_get = 'select data from %s order by data desc limit 1'%table_name
        cur.execute(sql_get)
        result = cur.fetchone()
        last_data = result[0]
        if(last_data != data[0]):
            sql_insert = 'insert into %s values (%s,%f,%f,%f) ' % (table_name,data[0], data[1], data[2], data[3])
            cur.execute(sql_insert)
            print("成功更新数据表 %s"%table_name)
    con.commit()
    cur.close()
    con.close()
    print("保存成功 %s"%table_name)


if __name__ == "__main__":
    #main("161725")
    list = ['163402','009326','005911','008282','519674','320007','005918','004746','161725','001632','002697','006229'\
        ,'260108','003547','161903','004070','007818','001630','001510','161810','005693','001410']
    for str_num in list:
        main(str_num)
    print("恭喜你，数据爬取成功！！！")