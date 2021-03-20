use mybooks;
select * from book; #data true
select * from author; #data true
select * from publisher; #data ture

insert into publisher values(1,"ChangBe","051-111-1111","ChangBe@naver.com","Guseoro122");
insert into publisher values(2,"Mega","051-222-2222","Mega@naver.com","Myeongrun");
insert into publisher values(3,"JangJung","051-333-3333","JangJung@naver.com","Jangjunro");
insert into publisher values(4,"LeeSan","051-444-4444","LeeSan@naver.com","BangBea");
insert into publisher values(5,"BeSang","051-555-5555","BeSang@naver.com","Seomyeon");

insert into book values(1000,"TimeTravler",15000,97,1);
insert into book values(1001,"Love is Sick",20000,98,2);
insert into book values(1002,"Blockchain",14500,100,2);
insert into book values(1003,"Sheri",8000,100,3);
insert into book values(1004,"Interstella",30000,101,4);
insert into book values(1005,"gravity",27000,102,5);

delete from book where book_ID = 1000;



