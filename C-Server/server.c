#include<stdio.h>      //C标准输入输出
#include<ctype.h>      //toupper函数头文件
#include<sys/socket.h>   //socket通信
#include<arpa/inet.h>    //socket通信
#include<stdlib.h>        //C标准库
#include<sys/epoll.h>      //epoll函数头文件
#include<unistd.h>         //POSIX系统调用API
#include<string.h>         //字符串操作，与string并列存在
#include<errno.h>          //通过错误码提示错误信息
#include<mysql/mysql.h>    //编译数据库文件

#define SERV_PORT 9999

//打印错误信息
void sys_err(const char *str){
	perror(str);	
	//exit(1);
}

//数据库链接
MYSQL* db_conn(){
	MYSQL* conn;
	conn = mysql_init(NULL);
	char * host = "39.105.82.172";
	char * user = "root";
	char* password = "jx19991022";
	char* db = "fund_data";
	if(mysql_real_connect(conn,host,user,password,db,0,NULL,0)){
		printf("database connection success\n");
	}
	else{
		sys_err("connect error");
	}
	return conn;
}
//数据库查询与数据处理
float db_read(MYSQL*conn,char* query,int index){
	MYSQL_RES * res;
	MYSQL_ROW row;
	float range = 9999.99;
	int ret = mysql_real_query(conn,query,strlen(query));
	printf("ret=%d\n",ret);
	if(!ret){
		printf("query success\n");
		res = mysql_store_result(conn);
		int rows = mysql_num_rows(res);
		printf("一共读取了%d天的数据\n",rows);
		if(rows){
			float sum =0.0;          //交易产生的收益&&支出
			int count=0;              //记录交易的总天数，代指投入金额
			switch(index){
				case 0:
					row = mysql_fetch_row(res);
					//printf("第0天:%s\n",row[0]);
					//memset(row,0,sizeof(row));
					for(int i=1;i<rows;i++){
						row = mysql_fetch_row(res);
						printf("第%d天:%s\n",i,row[0]);
						sum += i*atof(row[0]);
					}
					range = sum/(rows-1);
					break;

				case 1:
					row = mysql_fetch_row(res);
					if(row[0][0]=='-')
						count=1;
					else 
						count=0;
					//printf("第0天:%s\n",row[0]);
					for(int i=1;i<rows;i++){
						row = mysql_fetch_row(res);
						printf("第%d天：%s\n",i,row[0]);
						sum += count*atof(row[0]);
						if(row[0][0]=='-' && i!=rows-1)
							count++;
					}
					range = sum/count;
					break;

				case 2:
					row = mysql_fetch_row(res);
					if(row[0][0]=='-'){
						count+=(int)(row[0][1]-'0')+1;
					}
					//printf("第0天:%s\n",row[0]);
					for(int i=1;i<rows;i++){
						row = mysql_fetch_row(res);
						printf("第%d天：%s\n",i,row[0]);
						sum += count*atof(row[0]);
						if(row[0][0]=='-' && i!=rows-1)
							count+=(int)(row[0][1]-'0')+1;
					}
					range = sum/count;
					break;

				default:range = 8888.88;
			}
		}
	}
	else{
		sys_err("query error");
	}
	mysql_close(conn);
	
	return range;
}
int main(int argc,char *argv[])
{
	int lfd ,cfd,epfd;
	int ret,n;
	printf("server waitting for connection...\n");
	char buf[BUFSIZ],client_IP[1024];
	struct sockaddr_in serv_addr,clit_addr;
	socklen_t clit_addr_len;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	lfd = socket(AF_INET,SOCK_STREAM,0);
	if(lfd==-1){
		sys_err("socket error");
	}
	
	ret = bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(ret ==-1)
		sys_err("bind error");
	listen(lfd,128);
	struct epoll_event tmp,array[1024];
	epfd = epoll_create(1024);
	tmp.events = EPOLLIN;
	tmp.data.fd = lfd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&tmp);
	//多路复用IO
	while(1){
		ret = epoll_wait(epfd,array,1024,-1);
		for(int i=0;i<ret;i++){
			if(array[i].data.fd == lfd){
				cfd = accept(lfd,(struct sockaddr*)&clit_addr,&clit_addr_len);
				printf("client ip:%s port:%d connected...\n ",
				inet_ntop(AF_INET,&clit_addr.sin_addr,client_IP,sizeof(client_IP)),
				ntohs(clit_addr.sin_port));
				tmp.events = EPOLLIN;
				tmp.data.fd = cfd;
				epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&tmp);
			}
			else{
				n = read(array[i].data.fd,buf,sizeof(buf));
				if(n==0){
					close(array[i].data.fd);
					epoll_ctl(epfd,EPOLL_CTL_DEL,array[i].data.fd,NULL);
				}
				else if(n>0){
					char table_name[8]={'N'};
					char begin_date[9],end_date[9];
					char index[2]={-1};
					int j;
					for(j=0;j<strlen(buf);j++){
						if(j<6) 
							table_name[j+1]=buf[j];
						else if(j<14)
							begin_date[j-6]=buf[j];
						else if(j<22)
							end_date[j-14]=buf[j];
						else index[0] = buf[j];
					}
					char my_query[100];
					sprintf(my_query,"select change_range from %s where date between %s and %s",table_name,begin_date,end_date);
					MYSQL* conn = db_conn();
					printf("%s\n",my_query);
					int strategy_index = (int)(index[0]-'0');
					float range = db_read(conn,my_query,strategy_index);
					printf("range的值为%.2f",range);
					char send_msg[10];
					sprintf(send_msg,"%.2f",range);
					printf("send_msg:%s",send_msg);
					write(array[i].data.fd,send_msg,sizeof(send_msg));
					write(STDOUT_FILENO,index,sizeof(index));
				}

			}
		}
	}

	return 0;
}
