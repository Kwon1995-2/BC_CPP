create table author (
	author_ID int primary key,
	name varchar(20),
	phone varchar(15),
	e_mail varchar(50),
	sns varchar(50)
);

insert into author values(0097,"Kang","010-0000-0001","Kang00@mysql.com","kangwoo_king");
insert into author values(0098,"Park","010-0000-0002","Park01@mysql.com","bn_sj2013");

insert into author values(0099,"Kim","010-0000-0003","Kim02@mysql.com","kim_dj2014");insert into author values(0100,"Hong","010-0000-0004","Hong03@mysql.com","hhb_prof");
insert into author values(0101,"Ha","010-0000-0005","Ha04@mysql.com","hahahaha");
insert into author values(0102,"Ok","010-0000-0006","Ok05@mysql.com","ok_tyzang");
insert into author values(0103,"Lee","010-0000-0007","Lee06@mysql.com","leejs_ch");
insert into author values(0104,"Kwon","010-0000-0008","Kwon07@mysql.com","gweong_hs");
insert into author values(0105,"Jang","010-0000-0009","Jang08@mysql.com","jang_yj");
insert into author values(0106,"Jeong","010-0000-0010","Jeong09@mysql.com","Jeong_yn");

select * from author;